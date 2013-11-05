// Explores how macros are expanded in a line.

// Conclusion: the way `cpp` expands macros is as a one-liner (i.e. the
// terminal '\' escapes terminal newlines).

#include <stdio.h>

#define CountToThree\
	ONE,\
	TWO,\
	THREE

enum NUMBERS {
	ZERO,
	CountToThree,
	FOUR,
	FIVE
};

int main(void) {
	enum NUMBERS number;
	for (number = ZERO; number < FIVE; ++number)
		printf("%d\n", number);

	return 0;
}
