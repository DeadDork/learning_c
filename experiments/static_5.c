// Explores whether `static` can be used for defining multiple variables.

// Conclusion: it appears as if it can.

// main() {{{
#define PrintExpression(x) printf(#x " = [%d]\t", (x))

void dummy_function(void);
void static_function(void);

int main(void) {
	int element = 10;
	while (element-- > 0) {
		static_function();
		dummy_function();
	}

	return 0;
}
// }}}

// static_function() {{{
#include <stdio.h>

void static_function(void) {
	static int number1, number2;
	int number3;

	PrintExpression(number1);
	number1++;

	PrintExpression(number2);
	number2++;

	PrintExpression(number3);
	number3++;

	putchar('\n');
}
// }}}

void dummy_function(void) {
	int number1 = 1, number2 = 2, number3 = 3;
}
