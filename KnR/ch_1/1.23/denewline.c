////////////////////////////////////////////////////////////////////////////////
// Comments

// This program removes "excessive" newlines.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
int main( void )
{
	int c; // Character
	int nlcount = 3; // NewLine COUNT

	while( ( c = getchar() ) != EOF )
	{
		if( c == '\n' )
		{
			++nlcount;
		}
		else if( c != ' ' && c != '\t' && c != '\n' ) // for blank lines
		{
			nlcount = 0;
		}

		if( nlcount < 3 )
		{
			putchar( c );
		}
	}

	return 0;
}
