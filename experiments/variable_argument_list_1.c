// Explores having a function argument point to another function.

#include <stdarg.h>
#include <stdio.h>

#define PrintExpression(x) printf(#x " = [%d]\n", (x))

int sum(int, ...);

int main(void) {
	PrintExpression(sum(4, 2, 2, 2, 2));

	return 0;
}

int sum(int argument_number, ...) {
	va_list argument_next;
	int number_total = 0;

	va_start(argument_next, argument_number);
	while (argument_number-- > 0)
		number_total += va_arg(argument_next, int);
	va_end(argument_next);

	return number_total;
}
