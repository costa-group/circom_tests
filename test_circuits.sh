#!/usr/bin/env bash
set +e

# --- Color helpers ---
RED='\033[0;31m'
YELLOW='\033[1;33m'
GREEN='\033[0;32m'
NC='\033[0m' # No color

# --- Compute base directories ---
BASE_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
TEST_ROOT="$BASE_DIR/circomlib_original_2.0/test"
DETECT_DIR="$BASE_DIR/detecting_last_assignment"
EJ_DIR="$BASE_DIR/ej_functions_arrays/correct"
EXAMPLES_EQ_DIR="$BASE_DIR/examples_multiple_eq"
EXAMPLES_PARALLEL_DIR="$BASE_DIR/examples_parallel_component"
INCOMPLETE_ASSIGNMENTS_DIR="$BASE_DIR/incomplete_assignments"
MULTIPLE_ASSIGNMENTS_ANALYSIS_DIR="$BASE_DIR/multiple_assignments_analysis"
TAGS_2_2_DIR="$BASE_DIR/tags_2.2"
TEST_KNOWN_UNKNOWN="$BASE_DIR/test_known_unknown"

# --- Validate required commands ---
required_commands=(circom snarkjs node curl openssl)

for cmd in "${required_commands[@]}"; do
    if ! command -v "$cmd" >/dev/null 2>&1; then
        echo -e "${RED}❌ '$cmd' command could not be found${NC}"
        exit 1
    fi
done

# --- Verify circom supports expected flags ---
if ! circom --help | grep -q -- "--r1cs"; then
    echo -e "${RED}❌ circom binary does not support --r1cs flag. Wrong version?${NC}"
    exit 1
fi

echo -e "${GREEN}✅ All required commands found and valid${NC}"

# --- Proving setup (PTAU) ---
PTAU_URL="https://storage.googleapis.com/zkevm/ptau/powersOfTau28_hez_final_18.ptau"

# Shared working dir (kept across runs to cache zkeys & VKs)
WORKDIR="$BASE_DIR/workdir"
mkdir -p "$WORKDIR"

PTAU_PATH="$WORKDIR/$(basename "$PTAU_URL")"
if [[ ! -f "$PTAU_PATH" ]]; then
    echo "⬇️  Downloading PTAU: $PTAU_URL"
    curl -L "$PTAU_URL" -o "$PTAU_PATH"
    if [[ $? -ne 0 ]]; then
        echo -e "${RED}❌ Failed to download PTAU file${NC}"
        exit 1
    fi
fi

# --- Initialize arrays and binaries ---
TESTS=()
CIRCOM_BIN="circom"
SNARKJS_BIN="snarkjs"

# --- Helper: add nested tests (<root>/<sub>/<name>/<name>.circom) ---
add_nested_tests() {
    local ROOT_DIR="$1"
    local ROOT_NAME
    ROOT_NAME=$(basename "$ROOT_DIR")

    if [[ -d "$ROOT_DIR" ]]; then
        echo "📂 Searching for tests under: $ROOT_NAME"
        while IFS= read -r CIRCUIT_FILE; do
            local CIRCUIT_DIR
            CIRCUIT_DIR=$(dirname "$CIRCUIT_FILE")
            TESTS+=("$CIRCUIT_DIR")
        done < <(find "$ROOT_DIR" -type f -name "*.circom")
    else
        echo "⚠️  Warning: $ROOT_NAME directory not found: $ROOT_DIR"
    fi
}

# --- circomlib_original_2.0 tests (flat structure) ---
if [[ -d "$TEST_ROOT" ]]; then
    echo "📂 Searching for tests under: circomlib_original_2.0"
    while IFS= read -r DIR; do
        TESTS+=("$DIR")
    done < <(find "$TEST_ROOT" -maxdepth 1 -type d -not -path "$TEST_ROOT")
else
    echo "⚠️  Warning: circomlib_original_2.0/test directory not found: $TEST_ROOT"
fi

# --- Nested test roots ---
NESTED_TEST_DIRS=(
    "$DETECT_DIR"
    "$EJ_DIR"
    "$EXAMPLES_EQ_DIR"
    "$EXAMPLES_PARALLEL_DIR"
    "$INCOMPLETE_ASSIGNMENTS_DIR"
    "$MULTIPLE_ASSIGNMENTS_ANALYSIS_DIR"
    "$TAGS_2_2_DIR"
    "$TEST_KNOWN_UNKNOWN"
)

for dir in "${NESTED_TEST_DIRS[@]}"; do
    add_nested_tests "$dir"
done

# --- Summary of collected tests ---
echo "🔍 Found ${#TESTS[@]} test directories total."

# Keep result tallies
PASSED=()
FAILED=()

# --- Main test loop ---
for TEST_DIR in "${TESTS[@]}"; do
    CIRCUIT_FILE=$(find "$TEST_DIR" -maxdepth 1 -type f -name "*.circom" | head -n 1)
    TEST_NAME=$(basename "$TEST_DIR")
    CIRCUIT_BASENAME=$(basename "$CIRCUIT_FILE" .circom)
    INPUT_FILE="$TEST_DIR/witness/input.json"

    # Build dir per-circuit inside WORKDIR (clean each time)
    BUILD_DIR="$WORKDIR/build_$CIRCUIT_BASENAME"
    JS_DIR="$BUILD_DIR/${CIRCUIT_BASENAME}_js"
    WASM_FILE="$JS_DIR/${CIRCUIT_BASENAME}.wasm"
    WITNESS_FILE="$JS_DIR/witness.wtns"
    R1CS_PATH="$BUILD_DIR/${CIRCUIT_BASENAME}.r1cs"

    # Paths for prove/verify artifacts (cached across runs by r1cs hash)
    # These live in WORKDIR (not in BUILD_DIR) so they persist.
    echo "=============================================="
    echo "🔧 Running test: $TEST_NAME"
    echo "=============================================="

    if [[ ! -f "$CIRCUIT_FILE" ]]; then
        echo "⚠️  Skipping $TEST_NAME — missing circom file"
        continue
    fi
    if [[ ! -f "$INPUT_FILE" ]]; then
        echo "⚠️  Skipping $TEST_NAME — missing input.json"
        continue
    fi

    rm -rf "$BUILD_DIR"
    mkdir -p "$BUILD_DIR"

    echo "Compiling $CIRCUIT_FILE ..."
    $CIRCOM_BIN "$CIRCUIT_FILE" --r1cs --wasm --sym -o "$BUILD_DIR"
    if [[ $? -ne 0 ]]; then
        echo -e "${RED}❌ Compilation failed for $TEST_NAME${NC}"
        FAILED+=("$TEST_NAME (compile)")
        continue
    fi

    echo "Generating witness..."
    node "$JS_DIR/generate_witness.js" "$WASM_FILE" "$INPUT_FILE" "$WITNESS_FILE"
    if [[ $? -ne 0 ]]; then
        echo -e "${RED}❌ Witness generation failed for $TEST_NAME${NC}"
        FAILED+=("$TEST_NAME (witness)")
        continue
    fi

    echo "Checking witness against R1CS..."
    $SNARKJS_BIN wtns check "$R1CS_PATH" "$WITNESS_FILE"
    if [[ $? -ne 0 ]]; then
        echo -e "${RED}❌ snarkjs witness check failed for $TEST_NAME${NC}"
        FAILED+=("$TEST_NAME (wtns check)")
        continue
    fi

    # Compute md5 of R1CS to cache zkey/vk per exact circuit
    R1CS_MD5=$(openssl dgst -hex -md5 "$R1CS_PATH" | awk '{print $2}')
    ZKEY_PATH="$WORKDIR/${TEST_NAME}_${R1CS_MD5}_final.zkey"
    VK_PATH="$WORKDIR/${TEST_NAME}_${R1CS_MD5}_verification_key.json"
    ZKEY_STAGE0="$WORKDIR/${TEST_NAME}_${R1CS_MD5}_0000.zkey"
    PROOF_PATH="$WORKDIR/${TEST_NAME}_proof.json"
    PUBLIC_PATH="$WORKDIR/${TEST_NAME}_public.json"

    # Setup Groth16 only if we don't have a zkey cached for this R1CS
    if [[ ! -f "$ZKEY_PATH" ]]; then
        echo "Running Groth16 setup for $TEST_NAME (md5=$R1CS_MD5)..."
        $SNARKJS_BIN groth16 setup "$R1CS_PATH" "$PTAU_PATH" "$ZKEY_STAGE0"
        if [[ $? -ne 0 ]]; then
            echo -e "${RED}❌ groth16 setup failed for $TEST_NAME${NC}"
            FAILED+=("$TEST_NAME (setup)")
            continue
        fi

        # Small contribution for non-interactive CI-style flows
        ENTROPY1=$(head -c 64 /dev/urandom | od -An -tx1 -v | tr -d ' \n')
        $SNARKJS_BIN zkey contribute "$ZKEY_STAGE0" "$ZKEY_PATH" --name="1st Contribution" -v -e="$ENTROPY1"
        if [[ $? -ne 0 ]]; then
            echo -e "${RED}❌ zkey contribute failed for $TEST_NAME${NC}"
            FAILED+=("$TEST_NAME (contribute)")
            continue
        fi

        $SNARKJS_BIN zkey verify "$R1CS_PATH" "$PTAU_PATH" "$ZKEY_PATH"
        if [[ $? -ne 0 ]]; then
            echo -e "${RED}❌ zkey verify failed for $TEST_NAME${NC}"
            FAILED+=("$TEST_NAME (zkey verify)")
            continue
        fi
    else
        echo "♻️  Reusing cached zkey: $(basename "$ZKEY_PATH")"
    fi

    # Export verification key if missing
    if [[ ! -f "$VK_PATH" ]]; then
        $SNARKJS_BIN zkey export verificationkey "$ZKEY_PATH" "$VK_PATH"
        if [[ $? -ne 0 ]]; then
            echo -e "${RED}❌ export verification key failed for $TEST_NAME${NC}"
            FAILED+=("$TEST_NAME (export vk)")
            continue
        fi
    fi

    # Prove & Verify
    echo "Proving..."
    $SNARKJS_BIN groth16 prove "$ZKEY_PATH" "$WITNESS_FILE" "$PROOF_PATH" "$PUBLIC_PATH"
    if [[ $? -ne 0 ]]; then
        echo -e "${RED}❌ groth16 prove failed for $TEST_NAME${NC}"
        FAILED+=("$TEST_NAME (prove)")
        continue
    fi

    echo "Verifying..."
    $SNARKJS_BIN groth16 verify "$VK_PATH" "$PUBLIC_PATH" "$PROOF_PATH"
    if [[ $? -ne 0 ]]; then
        echo -e "${RED}❌ groth16 verify failed for $TEST_NAME${NC}"
        FAILED+=("$TEST_NAME (verify)")
        continue
    fi

    echo -e "${GREEN}✅ $TEST_NAME proved & verified successfully${NC}"
    PASSED+=("$TEST_NAME")
    echo
done

# --- Summary ---
echo "=============================================="
echo "🧾 TEST SUMMARY"
echo "=============================================="
echo -e "✅ Passed: ${#PASSED[@]} | ❌ Failed: ${#FAILED[@]}"
if [ ${#PASSED[@]} -gt 0 ]; then
  echo "✅ Passed tests:"
  printf '  %s\n' "${PASSED[@]}"
fi
if [ ${#FAILED[@]} -gt 0 ]; then
  echo "❌ Failed tests:"
  printf '  %s\n' "${FAILED[@]}"
fi
