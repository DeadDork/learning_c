////////////////////////////////////////////////////////////////////////////////
// Comments

// This creates a character array of undefined length (within the limits of the hardware), and prints it.

// Line 21 is necessary, presumably because otherwise there is pointer to the heap.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>
#include <stdlib.h>

////////////////////////////////////////////////////////////////////////////////
int main()
{
	char* d_s; // Dynamic String array
	int c; // Character
	int sz = 0; // Size

	d_s = malloc( sizeof( char ) );

	while( ( c = fgetc( stdin ) ) != '\n' )
	{
		d_s = realloc( d_s, sizeof( char ) * ++sz );
		*( d_s + ( sz - 1 ) ) = c;
	}
	*( d_s + sz ) = '\0';

	printf( "Dynamic string = [%s]\n", d_s );

	free( d_s );

	return 0;
}
