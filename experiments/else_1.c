// Explores the sole use of else.

// I guess you need if? (CF else_2.c)

#include <stdio.h>

enum {
	FALSE,
	TRUE
};

int main(void) {
	FALSE; // Maybe this would trick else into executing?
	else // error: expected expression
		printf("Else printf()\n"); // error: expected expression

	return 0;
}
