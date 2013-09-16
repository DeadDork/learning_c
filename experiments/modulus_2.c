////////////////////////////////////////////////////////////////////////////////
// Comments

// Explores whether the mod operator can work on floats.

// Conclusion: the mod operator only works on integers.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>
#include <stdlib.h>

////////////////////////////////////////////////////////////////////////////////
// Macros

// Float
//#define ModPrint(x, y) printf("%s mod %s = %f\n", #x, #y, (x) % (y))

// Integer
#define ModPrint(x, y) printf("%s mod %s = %d\n", #x, #y, (int)(x) % (int)(y))

////////////////////////////////////////////////////////////////////////////////
int main(void) {
	float f, ff;
	int i;

	do {
		i = scanf("%f%f", &f, &ff);
		if (i == 2)
			ModPrint(f, ff);
	} while (i == 2);

	return 0;
}
