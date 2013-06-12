////////////////////////////////////////////////////////////////////////////////
// Comments
//
// Tests whether non-repeating decimals in base-10, but which are repeating in
// base-2, have a rounding error that accumulates when iterated.
//
// Conclusion: Indeed, there are errors. At least my CPU does not have a type
// for fractions.
//
// N.B. As expected, the error bar is much bigger with the incremental zero-ing,
// as the one big zero-ing frequently can represent certain floats (e.g. when
// i = 4, f = 0.5).
//
// N.B. However, beyond 100,000,000 or so, the former test will have a smaller 
// error than the latter.
//
// N.B. Doing much more than 10,000 iterations will make f round out.
//
// N.B. To test integers larger than MAX_INT, change to unsigned, long, or
// a float.
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
// Symbolic Constants

#define FALSE 0
#define TRUE 1

////////////////////////////////////////////////////////////////////////////////
int main (void) {
	int i, subtract = TRUE;
    //int max = 100;
    //int max = 10000;
    //int max = 100000000;
    //int max = 1000000000;
    long max = 10000000000; // This might not be possible... System always locks.
    float f;

    // Incremental zero-ing {{{
    f = 0.0;
    for (i = 0; i <= max; ++i) {
        if (subtract) {
            f -= 0.1;
            subtract = TRUE;
        } else {
            f += 0.1;
            subtract = FALSE;
        }
    }
    printf ("[%.8f]\n", f); // 8 is approximately the number of spaces float
                            // can be precise to with a mantissa of 24 in base-2
    // }}}

    // One big zero-ing {{{
    f = 0.0;
    for (i = 0; i < max; ++i) {
        f += 0.1;
    }
    f -= 0.1 * max;
    printf ("[%.8f]\n", f);
    // }}}

    return 0;
}
