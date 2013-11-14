// Explores goto scope further.

// Conclusion: can't jump from functions.

#include <stdio.h>

void fn(void);

int main(void) {
	goto label1;

	label1:
	printf("main()\n");

	fn();

	label2:
	return 0;
}

void fn(void) {
	printf("fn()\n");
	goto label2; // error: use of undeclared label 'label2'
}
