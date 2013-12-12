// Explores the order of autoincrement vs. dereferencing.

// Hypothesis: results should be {"[a]", "[b]"}.
// Because '++' & '*' operate from right to left, `y` will autoincrement
// before it dereferences, but because it is a right autoincrement, the
// former value will be dereferenced.

// Conclusion: results were {"[a]", "[b]"}.

#include <stdio.h>

#define AutoIncrementPrinter(x) printf(#x " = [%c]\n", (x))

int main(void) {
	char string1[] = "a1", *string2;

	string2 = string1;
	AutoIncrementPrinter(*string2++); // "[a]"
	AutoIncrementPrinter(*string2++); // "[b]"

	putchar('\n');
	string2 = string1;
	AutoIncrementPrinter(*(string2++)); // "[a]"
	AutoIncrementPrinter(*(string2++)); // "[b]"

	putchar('\n');
	string2 = string1;
	AutoIncrementPrinter((*string2)++); // "[a]"
	AutoIncrementPrinter((*string2)++); // "[b]"

	return 0;
}
