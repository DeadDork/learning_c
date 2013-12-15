// Explores setting multiple statics in a function.

// Conclusion: the static applies to all of the declarations in that line.

// Main {{{
void function(void);

int main(void) {
	function();
	function();
	function();
	function();
	function();

	return 0;
}
// }}}

// Function {{{
#include <stdio.h>

#define PrintExpression(x) printf(#x " = %d\n", (x))

void function(void) {
	static int x = 1, y = -1;
	int z = 11;

	++x, --y;

	PrintExpression(x);
	PrintExpression(y);
	PrintExpression(z);
}
// }}}
