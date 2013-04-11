////////////////////////////////////////////////////////////////////////////////
// Comments

// Trying to create custom "types" (namely boolean type), yet again.

// Another failure... I just can't get enum to work!

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
// External Variables

//enum boolean { FALSE, TRUE }; // BOOLean "type"

////////////////////////////////////////////////////////////////////////////////
int main( void )
{
	enum boolean { FALSE, TRUE }; // BOOLean "type"

	int c; // Character
	boolean tf; // True or False

	while( ( c = getchar() ) != EOF )
	{
		if( c == 't' || c == 'T' )
		{
			tf = TRUE;
		}
		else if( c == 'f' || c == 'F' )
		{
			tf = FALSE;
		}

		if( tf == TRUE )
		{
			printf( "tf = TRUE\n" );
		}
		else if( tf == FALSE )
		{
			printf( "tf = FALSE\n" );
		}
	}

	return 0;
}
