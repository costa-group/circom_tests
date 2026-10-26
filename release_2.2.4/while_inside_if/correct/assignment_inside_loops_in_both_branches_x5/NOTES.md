Bug found by this test (fixed): Signal assigned inside a known loop in both branches of an unknown if: reported as
"Signal has been already assigned" (the same line as previous and current assignment).
Fails with v2.2.3, a100fae and HEAD: 51bcaa8 (#437) does not cover it.
