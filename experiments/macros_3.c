// Explores macro parameter expansion further

#include <stdio.h>

#define PrintExpression(x) printf(#x "\n")

int main(void) {
	PrintExpression((1, 2, 3));

	return 0;
}
