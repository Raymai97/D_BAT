Usage1: DCls 0
Effect: Move CMD cursor to top-left corner (0,0)
        Useful for redrawing screen with minimal flickering.

Usage2: DCls e
Effect: Clear line where CMD cursor located to the end of line.
        Then, move CMD cursor to the start of line.

Usage3: DCls 11e
Effect: Clear line 11, and move CMD cursor to the start of line 11.

Usage4: DCls x5
Effect: Move CMD cursor to col 5 of current line.
