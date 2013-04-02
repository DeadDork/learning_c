////////////////////////////////////////////////////////////////////////////////
// Comments

// Attempts to suss out bool type

// Also fails. Methinks that I'll have to use typedef to create a bool...

////////////////////////////////////////////////////////////////////////////////
// External Variables

enum bool { FALSE, TRUE };

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>
#include <limits.h>

////////////////////////////////////////////////////////////////////////////////
int main( void )
{
	unsigned char e; // Element
	bool b; // Boolean

	for( e = 0; e < UCHAR_MAX; ++e )
	{
		printf( "e = [%d]\nbool = [%d]\n", e, b = e );
	}

	return 0;
}
