////////////////////////////////////////////////////////////////////////////////
// Comments

// Plays with pointers to different memory blocks.

// Conclusion: you get a warning, but the program does compile. Moreover, it
// works!

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
// Function Prototypes

void print_float(float *);

void print_int(int *);

////////////////////////////////////////////////////////////////////////////////
// Functions

void print_float(float *number) {
	printf("\tFloat version: [%f]\n", *number);
}

void print_int(int *number) {
	printf("\tInt version: [%d]\n", *number);
}

////////////////////////////////////////////////////////////////////////////////
int main(void) {
	int integer;
	float decimal;

	for (;;) {
		printf("Integer: ");
		if (scanf("%d", &integer) > 0) {
			print_float(&integer);
			print_int(&integer);
		} else
			break;

		printf("Float: ");
		if (scanf("%f", &decimal) > 0) {
			print_float(&decimal);
			print_int(&decimal);
		} else
			break;
	}
	putchar('\n');

	return 0;
}
