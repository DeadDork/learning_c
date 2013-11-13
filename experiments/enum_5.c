// Explores enum naming.

// Conclusion: different enum names won't differentiate same enum elements.

#include <stdio.h>

#define PrintEnum(x) printf(#x " = %d\n", (x))

enum One {
	ONE
};

enum ZeroOne {
	ZERO,
	ONE // error: redefinition of enumerator 'ONE'
};

enum One enum_1(void);
enum ZeroOne enum_2(void);

int main(void) {
	PrintEnum(enum_1());
	PrintEnum(enum_2());

	return 0;
}

enum One enum_1(void) {
	return ONE;
}

enum ZeroOne enum_2(void) {
	return ONE;
}
