Bug found by this test (fixed): '0x' without digits reaches parse_bytes(..).expect() in parser/src/lang.lalrpop and panics.
