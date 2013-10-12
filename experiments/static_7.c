// Tracks changes to a static variable that is defined in its declaration, if
// any.

// Conclusion: declared once in definition, and not again.

// main() {{{
void static_function(void);

int main(void) {
	int element = 10;
	while (element-- > 0)
		static_function();

	return 0;
}
// main() }}}

// static_function() {{{
#include <stdio.h>

void static_function(void) {
	static int number = 1;

	printf("number = [%d]\n", number++);
}
// static_function() }}}
