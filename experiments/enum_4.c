// Explores the scope of enum.

// Conclusion: enum is scoped.

#include <stdio.h>

#define PrintExpression(x) printf(#x " = [%d]\n", (x))

enum {
	ZERO,
	ONE,
	TWO,
	THREE,
	FOUR
};

void enum_print(void);

int main(void) {
	enum {
		ONE,
		TWO,
		THREE,
		FOUR
	};

	printf("In main\n");
	PrintExpression(ONE);
	PrintExpression(TWO);
	PrintExpression(THREE);

	printf("\nOutside main\n");
	enum_print();

	return 0;
}

void enum_print(void) {
	PrintExpression(ONE);
	PrintExpression(TWO);
	PrintExpression(THREE);
}
