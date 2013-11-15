// Explores white space in the control statement.

// Conclusion: white spaces aren't important.

#include <stdio.h>

#define PrintExpression(x) printf(#x " = [%d]\n", (x))

int main(void) {
	int x;
	for (x = 20; x; --x)
		if (x < 5 ||
				x > 15)
			PrintExpression(x);

	return 0;
}
