////////////////////////////////////////////////////////////////////////////////
// Comments

// Solution to ex. 1-17.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
// Symbolic Constants

#define MINLEN 79 // MINimum LENgth of printable string - 1 (shift because of array index starting at 0).

////////////////////////////////////////////////////////////////////////////////
int main()
{
	int c, n; // Character, Number
	char s[ MINLEN + 1 ]; // String

	n = 0;
	while( ( c = getchar() ) != EOF )
	{
		if( n < MINLEN )
		{
			s[ n ] = c;
		}
		else if( n == MINLEN )
		{
			printf( "%s", s );
		}
		else if( n > MINLEN )
		{
			putchar( c );
		}

		if( c == '\n' )
		{
			n = 0;
		}
		else
		{
			++n;
		}
	}

	return 0;
}
