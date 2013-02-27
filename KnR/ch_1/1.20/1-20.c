////////////////////////////////////////////////////////////////////////////////
// Comments

// Solution to ex. 1-20.

// Works!

// To answer the question of whether to use a symbolic constant or a variable: it's better to use a variable, as it's more flexible (e.g. as demonstrated below, the user can change the offset with just an argument, rather than recompiling). Credit for this answer should go to Richard Heathfield (http://users.powernet.co.uk/eton/kandr2/krx120.html).

// To compile, link or copy sstring.h & sstring.c to this directory.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>
#include "sstring.h"

////////////////////////////////////////////////////////////////////////////////
int main( int argc, char * argv[] )
{
	int c, e; // Character, Element
	int tabstop = 4; // full length of a TABSTOP in spaces (default)
	int offset = 0; // OFFSET relative to tabstop

	/* Can optionally set the length of the tabstop via an argument */
	if( argc == 2 )
	{
		tabstop = ( int )str2num( argv[ 1 ] );
	}

	while( ( c = getchar() ) != EOF )
	{
		if( c == '\n' )
		{
			putchar( c );
			offset = 0;
		}
		else if( c == '\t' )
		{
			for( e = 0; e < tabstop - offset; ++e )
			{
				putchar( ' ' );
			}
			offset = 0;
		}
		else
		{
			putchar( c );
			++offset;
		}
	}

	return 0;
}
