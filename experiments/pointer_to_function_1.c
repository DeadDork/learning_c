// Explores having a function argument point to another function.

// Works!!!

#include <stdarg.h>
#include <stdio.h>

void print_expression(int (*function)(int, int), int, int);
int sum(int, int);

int main(void) {
	print_expression((int (*)(int, int))sum, 7, 9);

	return 0;
}

void print_expression(int (*function)(int, int), int x, int y) {
	printf("%d\n", (*function)(x, y));
}

int sum(int x, int y) {
	return x + y;
}
