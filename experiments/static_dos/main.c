////////////////////////////////////////////////////////////////////////////////
// Comments

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include "header.h"

////////////////////////////////////////////////////////////////////////////////
// External Variables

extern int external1;
extern int external2;
//extern static int external2; // "main.c:14: error: multiple storage classes in
                               // declaration specifiers"

////////////////////////////////////////////////////////////////////////////////
int main(void) {
	printf("Initial values:\n");
	Print(external1);
	Print(external2);

	printf("Running object's internal adder:\n");
	add_to_external1();
	add_to_external2();
	Print(external1);
	Print(external2);

	printf("Running objects's external adder:\n");
	++external1;
	++external2;
	Print(external1);
	Print(external2);

	return 0;
}
