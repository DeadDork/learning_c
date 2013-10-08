// Looks at whether a function and a variable can have the same name.

// As to be expected: "error: called object 'function' is not a function"

// main() {{{
#include <stdio.h>

#define PrintExpression(x) printf(#x " = [%d]\n", (x))

int function(void);

int main() {
	int function = 10;

	PrintExpression(function);
	PrintExpression(function());

	return 0;
}
// }}}

// function() {{{
int function() {
	return 20;
}
// }}}
