// Explores strcpy()'s return value.

// main() {{{
#define PrintAddress(x) printf(#x " = [%p]\n", (x))
#define STRING_MAX 100

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void) {
	char *string_1, *string_one;
	char *string_2, *string_two;

	string_one = string_1 = malloc(STRING_MAX);
	string_two = string_2 = malloc(STRING_MAX);

	// Tests strcpy()
	PrintAddress(string_1);
	string_1 = strcpy(string_1, "foo");
	PrintAddress(string_1);

	// Tests stpcpy()
	PrintAddress(string_2);
	string_2 = stpcpy(string_2, "bar");
	PrintAddress(string_2);

	free(string_one);
	free(string_two);

	return 0;
}
// }}}
