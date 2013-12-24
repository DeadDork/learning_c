// Explores partial array assignment.

// Conclusion: hey, whadaya know! It works!

// Main {{{
#include <stdio.h>

#define PrintExpression(x) printf(#x " = %d\n", (x))

int main(void) {
	int array[3] = {[0] = 5, [2] = 10};

	PrintExpression(array[0]);
	PrintExpression(array[1]);
	PrintExpression(array[2]);

	return 0;
}
// }}}
