// ...Because I can?

// Main {{{
#include <stdio.h>

#define Abs(x) (((x) < 0) ? -(x) : (x))

int get_number(int, char *[]);
int factorial(int);

int main(int argc, char *argv[]) {
	printf("Factorial of the absolute value of %s = %d\n", argv[argc - 1], factorial(Abs(get_number(argc, argv))));

	return 0;
}
// Main }}}

// Get the number from arguments {{{
#include <stdlib.h>

int get_number(int argc, char *argv[]) {
	if (argc == 1)
		return 0; // In case no input

	return atoi(argv[1]);
}
// Get the number from arguments }}}

int factorial(int number) {
	return number * ((number > 1) ? factorial(number - 1) : 1);
}
