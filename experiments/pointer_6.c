// Explores the ANSI C pointer declaration syntax (AKA type qualifier list?!?!)

// Conclusion: indeed, you can append a type qualifier to pointer (who knew?!)

// Discussion: how is `char *const x` different from `const char *x`?
// The latter forces all declarations in an expression to be type-qualified as
// `const`, the former declares only the one object as `const`.

// Main {{{
#include <stdio.h>

void without_type_qualifier(void);
void with_type_qualifier(void);

int main(void) {
	printf("Without type qualifier:\n");
	without_type_qualifier(); // Control

	printf("\nWith type qualifier:\n");
	with_type_qualifier(); // Test

	return 0;
}
// }}}

// Tests {{{
#include <stdlib.h>

#define PrintExpression(x) printf(#x " = %c\n", (x))

void without_type_qualifier(void) {
	char *pc_a = malloc(1), *pc_b = malloc(1);
	*pc_a = 'a', *pc_b = 'b';

	PrintExpression(*pc_a);
	PrintExpression(*pc_b);

	pc_b = pc_a;

	PrintExpression(*pc_a);
	PrintExpression(*pc_b);
}

void with_type_qualifier(void) {
	char *pc_a = malloc(1), *pc_b = malloc(1);
	char *const pc_c = pc_a;

	*pc_a = 'a', *pc_b = 'b';

	PrintExpression(*pc_a);
	PrintExpression(*pc_b);
	PrintExpression(*pc_c);

	// Should error
	pc_c = pc_b; // error: read-only variable is not assignable

	PrintExpression(*pc_a);
	PrintExpression(*pc_b);
	PrintExpression(*pc_c);
}
// }}}
