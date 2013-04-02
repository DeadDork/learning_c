////////////////////////////////////////////////////////////////////////////////
// Comments

// Attempts to suss out bool type

// Fails to compile. Bool isn't a type?

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>
#include <limits.h>

////////////////////////////////////////////////////////////////////////////////
int main( void )
{
	unsigned char e; // Element
	signed bool b; // Boolean
	unsigned bool bb; // Boolean copy 1

	for( e = 0; e < UCHAR_MAX; ++e )
	{
		printf( "e = [%d]\n\tsigned bool =   [%d]\n\tunsigned bool = [%d]\n", e, b = e, bb = e );
	}

	return 0;
}
