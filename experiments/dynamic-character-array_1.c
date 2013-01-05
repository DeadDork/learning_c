////////////////////////////////////////////////////////////////////////////////
// Comments

// This creates a character array of undefined length (within the limits of the hardware), and prints it.

// Line 21 is necessary, but I don't really understand why.
// My best guess is that without it d_s does not point to the heap, so realloc can't work appropriately (my confusion comes from the fact that the realloc docs said that the first call to realloc works just like malloc).

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
	while( ( c = fgetc( stdin ) ) != '\n' && c != EOF )
	{
		d_s = realloc( d_s, sizeof( char ) * ++sz );
		*( d_s + ( sz - 1 ) ) = c;
	}
	*( d_s + sz ) = '\0';

	printf( "Dynamic string = [%s]\n", d_s );

	free( d_s );

	return 0;
}
