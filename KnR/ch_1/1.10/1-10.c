////////////////////////////////////////////////////////////////////////////////
// Comments

// Solution to ex. 1-10.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
int main()
{
	int c; // Character

	while( ( c = getchar() ) != EOF )
	{
		/* Puts a '\' behind BACKSPACE, TAB, and \, but otherwise printfs C to STDIN */
		if( c == '\t' )
		{
			printf( "\\t" );
		}
		else if( c == '\b' )
		{
			printf( "\\b" );
		}
		else if( c == '\\' )
		{
			printf( "\\\\" );
		}
		else
		{
			putchar( c );
		}
	}

	return 0;
}

