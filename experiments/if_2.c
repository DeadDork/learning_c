////////////////////////////////////////////////////////////////////////////////
// Comments

// Explores whether a getchar() can be used in a test even if the test fails.

// As expected, you can assign in a test, even if the test fails.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
int main( void )
{
	int c, cc; // Character (1st, 2nd)

	while( ( c = getchar() ) != EOF )
	{
		if( c != '\n' )
		{
			cc = c;
			printf( "Before test:\n\tcc = [%c]\n", cc );

			printf( "After test:" );
			if( ( c = getchar() ) == EOF )
			{
				cc = c;
				printf( "\n\tEOF cc = [%c]\n\n", cc );
				break;
			}
			else if( c != '\n' )
			{
				cc = c;
				printf( "\n\tNOT EOF cc = [%c]\n\n", cc );
			}
		}
	}

	return 0;
}
