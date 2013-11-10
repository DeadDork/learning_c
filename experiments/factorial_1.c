// ...Because I can?

// Main {{{
#include <stdio.h>
#include <stdlib.h>

#define Abs(x) (((x) < 0) ? -(x) : (x))

int factorial(int);

int main(int argc, char *argv[]) {
	printf("Factorial of the absolute value of %s = %d\n", argv[argc - 1], factorial(Abs(atoi(argv[argc - 1]))));

	return 0;
}
// Main }}}

int factorial(int number) {
	return number * ((number > 1) ? factorial(number - 1) : 1);
}
