////////////////////////////////////////////////////////////////////////////////
// Comments

// Explores the use of static internal variables.

// Conclusion: it's a bit hard to see, but a moments investigation of the
// output shows that the internal variables in both stupid_definition() &
// not_static_internal() use the same address. As such the garbage value of
// not_static_internal() comes from stupid_definition(). Meanwhile,
// static_internal() appears to be protected.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
// Macros

#define PrintAddress(x) printf("\t&%s = %p\n", #x, (&x))

#define PrintValue(x) printf("\t%s = %d\n", #x, (x))

////////////////////////////////////////////////////////////////////////////////
// Function Prototypes

void stupid_definition(void);

void not_static_internal(void);

void static_internal(void);

////////////////////////////////////////////////////////////////////////////////
// Functions

void stupid_definition(void) {
	int stupid_integer = 3;

	PrintAddress(stupid_integer);
	PrintValue(stupid_integer);
}

void not_static_internal(void) {
	int not_static_integer;

	++not_static_integer;

	PrintAddress(not_static_integer);
	PrintValue(not_static_integer);
}

void static_internal(void) {
	static int static_integer;

	++static_integer;

	PrintAddress(static_integer);
	PrintValue(static_integer);
}

////////////////////////////////////////////////////////////////////////////////
int main(void) {
	int count;

	for (count = 0; count < 10; ++count) {
		stupid_definition();
		static_internal();
	}

	puts("");
	for (count = 0; count < 10; ++count) {
		stupid_definition();
		not_static_internal();
	}

	return 0;
}
