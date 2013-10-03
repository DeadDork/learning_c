////////////////////////////////////////////////////////////////////////////////
// Comments

// Explores the scope of a function declared inside another function.

// The test: will a second parent function be able to call the child function?

// Conclusion: yes, a second parent will. That said, if you change the order,
// such that function_stepparent() occurs above function_parent(), you'll have
// a compilation failure, as it's missing the prototype. Honestly, I don't get
// why you would declare a function in a smaller scope than Global...

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
// Function Prototypes

void function_parent(void);

void function_stepparent(void);

////////////////////////////////////////////////////////////////////////////////
// Functions

void function_child(void) {
	static int number; // Because `static`, initialized to 0.

	printf("%d", ++number);
}

void function_parent(void) {
	void function_child(void);

	printf("p[");
	function_child();
	printf("] ");
}

void function_stepparent(void) {
	printf("sp[");
	function_child();
	printf("] ");
}

////////////////////////////////////////////////////////////////////////////////
int main(void) {
	int element = 10;

	while (element--) {
		function_parent();
		function_stepparent();
	}
	putchar('\n');

	return 0;
}
