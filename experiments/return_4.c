// Explores returning a value from a bracket enclosure.

#include <stdio.h>

#define Return(x) ++x

int main(void) {
	int x = 3;
	printf("%d\n", Return(x));

	return 0;
}
