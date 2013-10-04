////////////////////////////////////////////////////////////////////////////////
// Comments

// Explores using a symbolic constant in a symbolic constant.

// How about that, it works--macros are imperative.

////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>

#define TWO 2
#define THREE 3
#define SIX TWO * THREE
#define StupidPrint(x, y, z) printf(#x " * " #y " = " #z ":\n\t%d * %d = %d\n", x, y, z)

main(void) {
	StupidPrint(TWO, THREE, SIX);

	return 0;
}
