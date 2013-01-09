////////////////////////////////////////////////////////////////////////////////
// Comments

// I had a funny float output in one of my functions, so I'm testing it out further.

// N.B. Use printf's float print control for floats, et al.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
int main()
{
	double x = 152.5;
	double y = 152.1986;

	// Correct
	printf( "%3.1lf - %3.4lf = %lf\n", x, y, x - y );

	// Incorrect
	printf( "%3.1lf - %3.4lf = %lf\n", x, y, x - y );

	return 0;
}
