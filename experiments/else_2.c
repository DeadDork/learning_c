// Explores the use of else.

// Conclusion: indeed, you need an if.

#include <stdio.h>

enum {
	FALSE,
	TRUE
};

int main(void) {
	if (FALSE);
	//if (TRUE);
	else
		printf("Else printf()\n");

	return 0;
}
