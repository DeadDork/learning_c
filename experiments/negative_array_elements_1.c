// Explores whether it's possible to refer to negative array index elements.

// Conclusion: looks like you can have negative indexes.

#include <stdio.h>

int main() {
	char *string = "Hello my darling";
	int element = 0;

	while (++element && *string++ != '\0');

	while (element >= 0)
		putchar(string[-element--]);
	putchar('\n');

	return 0;
}
