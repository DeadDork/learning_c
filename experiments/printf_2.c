////////////////////////////////////////////////////////////////////////////////
// Comments

// Tests if printf can print a character array even if there is no NULL.

// Conclusion: printf terminates at '\0'.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
int main()
{
	char c[ 4 ];
	int e;

	for( e = 0; e < 5; ++e )
	{
		c[ e ] = e + '1';
	}
	printf( "c:\n" );
	for( e = 0; c[ e ] != '\0'; ++e )
	{
		printf( "\t[%c]/[%d]\n", c[ e ], ( int )c[ e ] );
	}
	printf( "\t[%c]/[%d]\n", c[ e ], ( int )c[ e ] );

	printf( "The moment of truth:\n\tc = [%s]\n", c );

	return 0;
}
