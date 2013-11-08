// Explores a simple macro concatenation, post compile (cpp was not showing
// proper catting on my Mac).

// Conclusion: pre-processor concatenation occurs within clang, not separately
// by CPP. In other words, this works!
// (Thank god!)

#include <stdio.h>

enum NUMBERS {
	START_NUMBERS,
	ONE,
	TWO,
	THREE,
	FOUR,
	FIVE,
	SIX,
	SEVEN,
	EIGHT,
	NINE,
	TEN,
	END_NUMBERS
};

#define EnumSize(x) END_ ## x - START_ ## x - 1

int main(void) {
	printf("Size of enum NUMBERS = [%d]\n", EnumSize(NUMBERS));

	return 0;
}
