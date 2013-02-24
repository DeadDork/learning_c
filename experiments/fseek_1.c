////////////////////////////////////////////////////////////////////////////////
// Comments

// Tests `fseek`.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
int main()
{
	int c;
	FILE * f;

	f = fopen("abcd.txt", "r" );

	fseek( f, -1, SEEK_END );
	c = fgetc( f );
	printf( "Last character = [%c/%d]\n", c, ( int )c );

	fseek( f, -2, SEEK_END );
	c = fgetc( f );
	printf( "Second to last character = [%c/%d]\n", c, ( int )c );

	fseek( f, -3, SEEK_END );
	c = fgetc( f );
	printf( "Third to last character = [%c/%d]\n", c, ( int )c );

	fclose( f );

	return 0;
}
