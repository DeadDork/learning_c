////////////////////////////////////////////////////////////////////////////////
// Comments

// Tests how to determine the maximum value of a float.

// Doesn't work. That said, something funky occurs at 2^130.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
int main( void )
{
	float f; // Float
	float ff; // Float copy 1

	f = ff = 1;
	while( f <= ff )
	{
		printf( "[%.0f]\n", f );

		f = ff;
		ff = 2 * f;
	}

	return 0;
}
