////////////////////////////////////////////////////////////////////////////////
// Comments

// Print relational values

// Yup, '1 < 2' = 1 and '1 > 2' = 2.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
int main( void )
{
	printf( "'1 < 2' = [%d]\n", 1 < 2 );
	printf( "'1 > 2' = [%d]\n", 1 > 2 );

	return 0;
}