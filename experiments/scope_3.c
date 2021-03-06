////////////////////////////////////////////////////////////////////////////////
// Comments

// Explores the scope of a function declared inside another function.

// The test: will `static` reinitialize every parent function call?

// Conclusion: no, it won't.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
// Function Prototypes

void function_parent(void);

////////////////////////////////////////////////////////////////////////////////
// Functions

void function_parent(void) {
	void function_child(void);

	function_child();
}

void function_child(void) {
	static int number; // Because `static`, initialized to 0.

	printf("%d-", ++number);
}

////////////////////////////////////////////////////////////////////////////////
int main(void) {
	int element = 10;

	while (--element)
		function_parent();
	putchar('\n');

	return 0;
}
