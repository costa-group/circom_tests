REGRESSION (6c3a24a): works with a22aeaf. inside_unknown_loop is set for every loop (even with known conditions) and is
not reset when a template is instantiated, so expressions of templates instantiated inside a loop are
not considered computed and their array sizes are rejected (T2033 Invalid array size).
Breaks circomlib (escalarmulfix, sha256, poseidon, pedersen, eddsa, ...).
