// Exploring static declarations in functions (pretty sure this is a repeat).

// Conclusion: with static, there is one declaration, no matter how many times
// the function with the declaration is called.

#include <stdio.h>

int fn(void);

int main(void) {
	for (int x = 10; x > 0; --x)
		printf("%d\n", fn());

	return 0;
}

int fn(void) {
	static int x = 20;

	return x++;
}
