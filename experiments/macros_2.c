// Explores macro parameter expansion.

#include <stdio.h>

#define PrintExpression(x) printf(#x " = [%d]\n", (x))
//#define Sum(x) sum(x) // error: macro "Sum" passed 2 arguments, but takes just 1
#define Sum(x, y) sum((x), (y))

int sum(int, int);

int main(void) {
	PrintExpression(Sum(1, 2));

	return 0;
}

int sum(int x, int y) {
	return x + y;
}
