// Explores the scoping of goto.

// Conclusion: yes, goto's are scoped.

#include <stdio.h>
#include <stdlib.h>

void goto_fn(void);

int main(void) {
	int x = arc4random() % 2;

	if (x)
		goto fn; // error: use of undeclared label 'fn'
	else
		printf("main\n");

	end:
	return 0;
}

void goto_fn(void) {
	fn:
	printf("goto_fn\n");
	goto end; // error: use of undeclared label 'end'
}
