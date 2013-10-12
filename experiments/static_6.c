// Explores whether static variables can be autoincremented when defined.

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
	//static number++; // fails
	static int number; ++number; // works

	printf("number = [%d]\n", number);
}
// static_function() }}}
