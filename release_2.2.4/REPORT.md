# Tests de la release circom 2.2.4

Rama `in_work_2.2.3`, a partir de HEAD `60cacbe`. Los tests se ejecutan con `run_tests.py` sobre wasm y C++, en `--O0`, `--O1` y `--O2`.

## Resumen

Todo lo que encontraron los tests está arreglado: las regresiones de los commits de 2.2.4, los arreglos incompletos y los issues abiertos #431 y #433. Los cambios del compilador están en el working tree y todavía no están commiteados.

| Ejecución | PASS | FAIL | DIFF |
|---|---|---|---|
| `release_2.2.4` (159 casos) con `60cacbe` | 107 | 14 | – |
| `release_2.2.4` con los arreglos | **159** | 0 | – |
| Suite existente (229 casos) con a100fae, la base de los issues | 217 | 10 | 2 |
| Suite existente con `60cacbe` | 167 | **60** | 2 |
| Suite existente con los arreglos | **218** | 9 | 2 |

- **Los 9 FAIL que quedan en la suite existente ya fallaban con a100fae y v2.2.3, por los mismos motivos.** No tienen relación con 2.2.4 (ver el final del documento).
- **El caso que pasa de más es `test_known_unknown/fails/not_correct_10_cons`.** Su `error.txt` registra en realidad una compilación correcta, y el runner ahora lo interpreta así.

## Problemas encontrados y arreglados

### Regresiones de los commits de 2.2.4

| Commit | Problema | Arreglo |
|---|---|---|
| 6c3a24a (#434) | `inside_unknown_loop` desactivaba el plegado de constantes dentro de **todo** bucle y no se restablecía al instanciar templates. Consecuencias: `T2033 Invalid array size` en templates instanciadas dentro de un `for` (49 regresiones en circomlib, buses, …); un panic en `merger.rs:663`; ejecución de los dos brazos de un ternario desconocido, que provocaba stack overflow con recursión, asserts y OOB en compilación. | Se elimina `inside_unknown_loop`. El bug real de #434 eran los brazos de un ternario con condición desconocida que conservaban un valor computado en una iteración anterior. Ahora esos brazos se marcan como no computados sin ejecutarse (`mark_as_not_computed`), salvo los accesos a tags. Una expresión no simplificable también se marca como no computada. |
| a22aeaf (#435) | Las sentencias elevadas de los brazos (`inits_true`/`inits_false`) y los bloques nuevos de los `if` sin llaves no se bajaban: un ternario anidado o un literal de array acababan en `unreachable!` en `translate.rs`. | `map_substitutions` se aplica a esas sentencias, y `map_extended_stmts` a los bloques nuevos. |
| 3a9efd5 | En C++, un store de tamaño 0 en una salida de una template `parallel` dejaba una llave sin cerrar. | Se cierra el bloque también con tamaño 0 (`store_bucket.rs`). Además, un call de tamaño 0 ya no marca como asignada una salida vecina (`call_bucket.rs`). |
| 2e368af (#420) | Falso positivo en la detección de bucles: el nombre de la instancia no incluía los tags de los campos de bus. | La traza compara nombre, parámetros y `TagWire` completos, con el mismo criterio que `identify_node`. |

### Arreglos incompletos y bugs que ya existían

| Problema | Arreglo |
|---|---|
| `--sanity_check 3` no comprobaba los índices de señales de subcomponentes (`t.out[i]`, `t.ob.a[i]`). | `build_signal_location` devuelve las comprobaciones; en arrays mixtos se generan si todas las instancias tienen las mismas dimensiones. |
| La comprobación OOB usaba la dirección de 32 bits: `i = 2^32` leía `a[0]` en wasm y `a[4*i]` daba la vuelta. | La comprobación se hace sobre el valor del índice en el cuerpo finito: `!(idx \ size)` vale 1 si y solo si `0 <= idx < size`. Solo se construye con `--sanity_check 3`, y los índices constantes no se comprueban. |
| `%` por 0 en runtime no se comprobaba en `--sanity_check 3` (wasm: trap; C++: SIGFPE). | `Mod` se añade a la comprobación de divisor cero. Docs y RELEASES actualizados. |
| Panic por división por cero con buses que tienen campos de tamaño 0 (`build.rs`), y con dimensiones de tamaño 0 en `compute_full_address`. | Tamaño individual 0 / `checked_div`. |
| En wasm, un store de tamaño 0 descartaba las comprobaciones de su fuente. | Se genera la fuente y se descarta su valor (`drop`), igual que en C++. |
| C++ volvía a ejecutar un subcomponente tras una asignación de tamaño 0 (arrays mixtos). | La condición de ejecución exige un tamaño > 0 (`build_run_condition`). |
| Una asignación dentro de un `for` conocido en las dos ramas de un `if` desconocido daba "already assigned" (el contador del bucle se volvía desconocido). | Las variables declaradas dentro del bloque desconocido son locales a él y conservan su valor (`unknown_block_start`). |
| `A(n)` que instancia `A(n+1)` desbordaba la pila, y una recursión legítima de unos 300 niveles también. | El compilador se ejecuta en un hilo con pila de 2 GiB (solo reservada). Más de 10000 llamadas anidadas dan un error limpio, y las trazas largas se recortan. |
| `0x` provocaba un panic en el parser. | La expresión regular de `HEXNUMBER` exige al menos un dígito. |
| Un ternario o un array usado directamente como argumento de `log`/`assert` provocaba un panic (también en v2.2.3). | Se extraen a una variable. |
| #431: `x = [x[1], x[0]]` se asignaba elemento a elemento. | Si el array lee la variable asignada, se construye primero en una variable auxiliar. |
| #433: una llamada en la condición de un `while`/`for` (y en el cuerpo de un `while` sin llaves) se evaluaba una sola vez, antes del bucle. | Las sentencias elevadas de la condición se repiten al final de cada iteración, y las del cuerpo se quedan en el cuerpo. |

## Decisiones tomadas

- **Errores en el brazo no tomado de un ternario desconocido.** Un OOB o un `assert` en ese brazo **no** son errores de compilación, igual que en v2.2.3. Casos: `computed_analysis/correct/guard_with_known_false_part` y `untaken_arm_with_failing_assert`.
- **Código de error del pragma demasiado grande.** Se mantiene P1010, que es lo que implementa ea0263d; el issue #421 esperaba P1003.
- **Límite de 10000 llamadas anidadas a templates.** Con la pila de 2 GiB, una recursión de 9000 niveles compila en unos 5 s y usa unos 700 MB.

## Fallos de la suite existente que ya estaban antes (sin relación con 2.2.4)

- **`circomlib_original_2.0`** (aliascheck, eddsa*, sign, pointbits_loopback, smt*):
  - los circuitos de este repo contienen `log` de depuración ("Imprimiendo iteración …") que wasm decodifica mal en UTF-8 y que C++ imprime más veces que wasm;
  - `smtverifier10_test` y `smtprocessor10_test` fallan además al generar el witness wasm.
- **`incomplete_assignments/correct/simple`:** espera la semántica antigua de asignar arrays con dimensiones incompletas, que cambió en 2.2.3.
- **DIFF de `examples_parallel_component/ex5/parallel_component` e `incomplete_assignments/correct/function_multiple3`:** difieren solo de los `.wtns` y `.r1cs` de referencia.
- **Tests unitarios Rust:** `cargo test` tiene 3 tests que fallan igual en v2.2.3 (`algebra_constraint_apply_substitution`, `complement_of_complement_is_the_original_test`, `produce_code`). Están desactualizados.

## Reproducir

```sh
cargo build --release
cd circom_tests
python3 run_tests.py --circom ../target/release/circom --only release_2.2.4 --jobs 12 --report head.md
python3 run_tests.py --circom ../target/release/circom --jobs 12          # suite completa
python3 tools/gen_release_2.2.4.py release_2.2.4                          # regenerar los casos
```
