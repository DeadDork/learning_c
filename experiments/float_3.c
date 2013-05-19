////////////////////////////////////////////////////////////////////////////////
// Comments

// Prints out the values of various float symbolic constants.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <float.h> // Vim can't find this header file...
#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
int main (void) {
	printf ("Float:\n");
	printf ("\tFLT_MANT_DIG = %d\n", FLT_MANT_DIG);
	printf ("\tFLT_MIN_EXP = %d\n", FLT_MIN_EXP);
	printf ("\tFLT_MAX_EXP = %d\n", FLT_MAX_EXP);
	printf ("\tFLT_DIG = %d\n", FLT_DIG);
	printf ("\tFLT_MIN_10_EXP = %d\n", FLT_MIN_10_EXP);
	printf ("\tFLT_MAX_10_EXP = %d\n", FLT_MAX_10_EXP);
	printf ("\tFLT_MIN = %.0f\n", FLT_MIN);
	printf ("\tFLT_MAX = %.0f\n", FLT_MAX);
	printf ("\tFLT_EPSILON = %.0f\n", FLT_EPSILON);

	printf ("\nDouble:\n");
	printf ("\tDBL_MANT_DIG = %d\n", DBL_MANT_DIG);
	printf ("\tDBL_MIN_EXP = %d\n", DBL_MIN_EXP);
	printf ("\tDBL_MAX_EXP = %d\n", DBL_MAX_EXP);
	printf ("\tDBL_DIG = %d\n", DBL_DIG);
	printf ("\tDBL_MIN_10_EXP = %d\n", DBL_MIN_10_EXP);
	printf ("\tDBL_MAX_10_EXP = %d\n", DBL_MAX_10_EXP);
	printf ("\tDBL_MIN = %.0f\n", DBL_MIN);
	printf ("\tDBL_MAX = %.0f\n", DBL_MAX);
	printf ("\tDBL_EPSILON = %.0f\n", DBL_EPSILON);

	printf ("\nLong double:\n");
	printf ("\tLDBL_MANT_DIG = %.0Lf\n", (long double) LDBL_MANT_DIG);
	printf ("\tLDBL_MIN_EXP = %.0Lf\n", (long double) LDBL_MIN_EXP);
	printf ("\tLDBL_MAX_EXP = %.0Lf\n", (long double) LDBL_MAX_EXP);
	printf ("\tLDBL_DIG = %.0Lf\n", (long double) LDBL_DIG);
	printf ("\tLDBL_MIN_10_EXP = %.0Lf\n", (long double) LDBL_MIN_10_EXP);
	printf ("\tLDBL_MAX_10_EXP = %.0Lf\n", (long double) LDBL_MAX_10_EXP);
	printf ("\tLDBL_MIN = %.0Lf\n", (long double) LDBL_MIN);
	printf ("\tLDBL_MAX = %.0Lf\n", (long double) LDBL_MAX);
	printf ("\tLDBL_EPSILON = %.0Lf\n", (long double) LDBL_EPSILON);

	return 0;
}
