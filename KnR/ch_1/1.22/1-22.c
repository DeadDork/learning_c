////////////////////////////////////////////////////////////////////////////////
// Comments

// Solution to ex. 1-22

// Works!

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
int main( void )
{
	int maxlen = 80; // MAXimum LENgth of a string per line (i.e. the width of the screen)
	--maxlen; // -1 in order to have a space for a mid-word hyphen for over-long lines
	char s[ maxlen ]; // String for line
	int c, e; // Character, Element
	int chanum = 0; // CHAracter NUMber
	int lastch = 0; // position in string array of LAST CHaracter (N.B. lastch is always 1 greater than the actual last array position of a non-whitespace char)

	while( ( c = getchar() ) != EOF )
	{
		if( c == '\n' || chanum == maxlen )
		{
			for( e = 0; e < lastch; ++e )
			{
				putchar( s[ e ]);
			}
			if( lastch == maxlen && c != '\t' && c != ' ' && c != '\n' )
			{
				putchar( '-' );
			}
			putchar( '\n' );
			lastch = 0;
			chanum = 0;
			if( c != '\t' && c != ' ' && c != '\n' )
			{
				s[ chanum++ ] = c;
				lastch = chanum;
			}
		}
		else
		{
			s[ chanum++ ] = c;
			if( c != '\t' && c != ' ' )
			{
				lastch = chanum;
			}
		}
	}

	return 0;
}
