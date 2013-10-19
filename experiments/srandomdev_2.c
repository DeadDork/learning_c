// Prints out the desired number of random numbers (default to 10 numbers).

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int element = 10;
	if (argc > 1)
		element = atoi(argv[1]);
	int modulus = 10;
	if (argc > 2)
		modulus = atoi(argv[2]);

	while (element-- > 0) {
		srandomdev();
		printf("%d\n", (int)random() % modulus);
	}

	return 0;
}
