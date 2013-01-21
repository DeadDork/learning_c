////////////////////////////////////////////////////////////////////////////////
// Comments

// Solution to ex. 1-13.

// This is the vertical histogram.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
// Symbolic Constants

#define IN 1 // IN a word
#define OUT 0 // OUT of a word
#define MAXC 21 // Max number of Characters in a word
#define MAXH 30 // Max histogram height

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

	/* Adjust lengths to fit on page */
	for( e = 1; e < MAXC; ++e )
	{
		length[ e ] = ( int )( ( length[ e ] * ( MAXH / ( float )high ) ) + 0.99 );
	}

	/* Print histogram */
	for( e = MAXH; e > 0; --e )
	{
		for( ee = 1; ee < MAXC ; ++ee )
		{
			if( length[ ee ] >= e )
			{
				printf( " _ " );
			}
			else
			{
				printf( "   " );
			}
		}
		putchar( '\n' );
	}
	for( e = 1; e < MAXC - 1; ++e )
	{
		printf( "%2d ", e );
	}
	printf( "20+\n" );

	return 0;
}
