// Explores static vars in recursive functions.

// Conclusion: static vars retain their state across recursions.

void fn(void);

int main(void) {
	fn();

	return 0;
}

#include <stdio.h>

void fn(void) {
	static int x;

	if (x > 10)
		return;
	else {
		printf("x = [%d]\n", x++);
		fn();
	}
}
