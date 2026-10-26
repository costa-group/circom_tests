Bug found by this test (fixed): Accesses to signals of subcomponents (t.out[i]) are not bounds-checked:
compiler/src/intermediate_representation/translate.rs (build_signal_location) computes the
checks for the Uniform case and drops them; the Mixed/Mapped case never creates them.
