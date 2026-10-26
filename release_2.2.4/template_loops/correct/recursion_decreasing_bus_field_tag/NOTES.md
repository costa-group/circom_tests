REGRESSION (2e368af, works with a100fae): false loop detection.
Recursion that terminates thanks to the tag of a bus field. The instantiation name used by
the loop detection does not include bus field tags (TODO in execute.rs, execute_template_call),
so this may be reported as a false loop.
