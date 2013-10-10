// Screws around with reversing a string.

#include <stdio.h>

int main() {
	char *string = "Hello my darling";
	char *start_string = string;

	while (*string++ != '\0');

	while (--string >= start_string)
		putchar(*string);
	putchar('\n');

	return 0;
}
