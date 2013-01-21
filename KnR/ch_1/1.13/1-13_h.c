////////////////////////////////////////////////////////////////////////////////
// Comments

// Solution to ex. 1-13.

// This is the horizontal histogram.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
// Symbolic Constants

#define IN 1 // IN a word
#define OUT 0 // OUT of a word
#define MAXC 21 // Max number of Characters in a word
#define MAXW 60 // Max histogram Width

////////////////////////////////////////////////////////////////////////////////
int main()
{
	int c, e, ee, high, wc, state;
	int length[ MAXC ];

	/* Word count */
	for( e = 0; e < MAXC; ++e )
	{
		length[ e ] = 0;
	}
	wc = high = 0;
	state = OUT;

	while( ( c = getchar() ) != EOF )
	{
		if( state == IN && ( c == '\t' || c == '\n' || c == ' ' ) )
		{
			if( wc < MAXC - 1 )
			{
				if( ++length[ wc ] > high )
				{
					high = length[ wc ];
				}
			}
			else
			{
				if( ++length[ MAXC - 1 ] > high )
				{
					high = length[ MAXC - 1 ];
				}
			}

			wc = 0;
			state = OUT;
		}
		else if(  c != '\t' && c != '\n' && c != ' ' )
		{
			++wc;
			if( state == OUT )
			{
				state = IN;
			}
		}
	}

	/* Print histogram */
	for( e = 1; e < MAXC; ++e )
	{
		if( e < MAXC - 1 )
		{
			printf( "%4d  ", e );
		}
		else
		{
			printf( "  19+ " );
		}
		for( ee = 0; ee < ( int )( ( length[ e ] * ( MAXW / ( float )high ) ) + 0.99 ); ++ee )
		{
			putchar( '|' );
		}
		putchar( '\n' );
	}

	return 0;
}
