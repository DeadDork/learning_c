////////////////////////////////////////////////////////////////////////////////
// Comments

// Solution to ex. 1-22

// Works!

// ...But folding is too basic, and I don't like the design.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
int main( void )
{
	int maxlen = 80; // MAXimum LENgth of a string per line (i.e. the width of the screen)
	--maxlen; // -1 in order to have a space for a mid-word hyphen for over-long lines (optional)
	char s[ maxlen ]; // String for line
	int c, e; // Character, Element
	int chanum = 0; // CHAracter NUMber
	int termch = 0; // TERMinating non-whitespace CHaracter

	while( ( c = getchar() ) != EOF )
	{
		if( c == '\n' || chanum == maxlen )
		{
			for( e = 0; e < termch; ++e )
			{
				putchar( s[ e ] );
			}
			/* Optional */
			if( termch == maxlen && c != '\t' && c != ' ' && c != '\n' )
			{
				putchar( '-' );
			}
			putchar( '\n' );

			chanum = 0;
			termch = 0;

			if( c != '\n' )
			{
				s[ chanum++ ] = c;
				termch = chanum;
			}
		}
		else
		{
			s[ chanum++ ] = c;
			if( c != '\t' && c != ' ' )
			{
				termch = chanum;
			}
		}
	}

	return 0;
}
