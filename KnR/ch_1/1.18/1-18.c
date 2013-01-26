////////////////////////////////////////////////////////////////////////////////
// Comments

// Solution to ex. 1-18.

// Bug/feature: cuts off after MAXLEN, and treats the string until that point as the full string. This prevents buffer overflow, but leads to funny outputs in the higher character ranges (cf. test line #16 - #24).

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
// Symbolic Constants

#define MAXLEN 100 // MAXimum LENgth of string

////////////////////////////////////////////////////////////////////////////////
int main()
{
	int c, n; // Character, Number
	char buf[ MAXLEN ]; // BUFfer

	n = 0;
	while( ( c = getchar() ) != EOF )
	{
		if( c != '\n' )
		{
			if( n < MAXLEN )
			{
				buf[ n++ ] = c;
			}
		}
		else
		{
			for( --n; buf[ n ] == '\t' || buf[ n ] == ' '; --n );
			buf[ n + 1 ] = '\0';
			printf( "[%s]\n", buf );
			n = 0;
		}
	}

	return 0;
}
