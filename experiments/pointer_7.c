// Explores the difference between `const char *x` and `char *const x`.

// Main {{{
void test_const_1(void);
void test_const_2(void);

int main(void) {
	test_const_1(); // Tests `const char *x`
	test_const_2(); // Tests `char *const x`

	return 0;
}
// }}}

// Tests {{{
#include <stdio.h>
#include <stdlib.h>

#define PrintExpression(x) printf(#x " = %c\n", (x))

void test_const_1(void) {
	const char a = 'a', b = 'b';
	char c = 'c';

	// Control
	const char *p_a = &a;
	PrintExpression(*p_a);

	// Should compile, as p_a is still pointing to a const char
	p_a = &b;
	PrintExpression(*p_a);

	// Should fail to compile, as p_a is no longer pointing to a const char
	// Doesn't fail, not as expected
	p_a = &c;
	PrintExpression(*p_a);

	// But this does! Not all hope is lost!
	//*p_a = 'd';
	PrintExpression(*p_a);
}

void test_const_2(void) {
	char *const p_a = malloc(1), *p_b = malloc(1);

	// Control
	*p_a = 'a';
	PrintExpression(*p_a);

	// Should compile, as p_a's address doesn't change
	*p_a = 'b';
	PrintExpression(*p_a);

	// Should fail to compile, p_a's address *does* change
	// Fails, as expected
	*p_b = 'b';
	//p_a = p_b; // error: read-only variable is not assignable
	PrintExpression(*p_a);
}
// }}}
