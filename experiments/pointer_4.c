////////////////////////////////////////////////////////////////////////////////
// Comments

// Explores whether pointers definitions also initialize the address they point
// to.

// Conclusion: it does not.

// N.B. I've had other pointer-related bugs that were solved via explicit
// definition. In the future, I will define variables explicitly.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>
#include <stdlib.h>

////////////////////////////////////////////////////////////////////////////////
// Macros

#define Print(x) printf("%s = %d\n", #x, (x))

////////////////////////////////////////////////////////////////////////////////
int main(void) {
	int i, * i_ptr;

	i_ptr = malloc(1 * sizeof(int)); // If this is not done, you get a segfault.

	Print(i);
	Print(*i_ptr);

	free(i_ptr);

	return 0;
}
