// A macro that return the number of arguments

// Conclusion: works!

// N.B. C99 is better than C90.

#include <stdarg.h>
#include <stdio.h>

#define PrintExpression(x) printf(#x " = [%d]\n", (x))
#define Sum(args...) sum(argument_count(#args), args)

int argument_count(char *);
int sum(int, ...);

int main(void) {
	PrintExpression(Sum(1, 1, 1, 1, 1));

	return 0;
}

int argument_count(char *argv) {
	int argc = 0;

	while (*argv)
		if (*argv++ == ',')
			++argc;

	return (argc > 0) ? ++argc : 0;
}

int sum(int argument_number, ...) {
	int total = 0;
	va_list argument_next;

	va_start(argument_next, argument_number);
	while (argument_number-- > 0)
		total += va_arg(argument_next, int);
	va_end(argument_next);

	return total;
}
