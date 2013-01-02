////////////////////////////////////////////////////////////////////////////////
// Comments

// Tests what kind of arrays receive an automatic NULL at their end.

// a[ 3 ] is garbage. It looks like only char arrays automatically get a NULL at the end.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
int main()
{
	int a[] = { 9, 8, 7 };
	char b[] = "hey";
	int i;

	for( i = 0; i < 4; ++i )
		printf( "a[%d] = [%d]\n", i, a[ i ] );
	for( i = 0; i < 4; ++i )
		printf( "b[%d] = [%d]\n", i, b[ i ] );

	return 0;
}
