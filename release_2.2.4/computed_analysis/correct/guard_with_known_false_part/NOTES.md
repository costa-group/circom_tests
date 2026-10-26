REGRESSION (6c3a24a, works with v2.2.3 and a22aeaf): at i = 0 the condition is unknown (0 && unknown is not folded), so executing both arms reads x[-1].
