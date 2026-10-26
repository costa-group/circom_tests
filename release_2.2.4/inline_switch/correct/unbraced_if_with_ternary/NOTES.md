REGRESSION (a22aeaf): compiles with v2.2.3 / a100fae, panics at HEAD.
a22aeaf stores the statements lifted from each arm (inits_true/inits_false) in blocks that are not
lowered by the sugar cleaner (map_substitutions / rhe_array_case), so a nested switch or an array
literal reaches translate.rs and hits unreachable!("This expression is syntactic sugar").
