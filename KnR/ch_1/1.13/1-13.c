////////////////////////////////////////////////////////////////////////////////
// Comments

// Solution to ex. 1-13.

// This is the horizontal histogram.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>
#include <math.h>

////////////////////////////////////////////////////////////////////////////////
// Symbolic Constants

#define IN 1 // In a word
#define OUT 0 // Out of a word
#define MAX 21 // Max number of characters in a word
#define WIDTH 60 // Max histogram size

////////////////////////////////////////////////////////////////////////////////
int main()
{
	int c, e, ee, high, wc, state;
	int length[ MAX ];

	/* Word count */
	for( e = 0; e < MAX; ++e )
	{
		length[ e ] = 0;
	}
	wc = high = 0;
	state = OUT;
	while( ( c = getchar() ) != EOF )
	{
		if( state == IN && ( c == '\t' || c == '\n' || c == ' ' ) )
		{
			if( wc < MAX - 1 )
			{
				++length[ wc ];
				if( length[ wc ] > high )
				{
					high = length[ wc ];
				}
			}
			else
			{
				++length[ MAX - 1 ];
				if( length[ MAX - 1 ] > high )
				{
					high = length[ MAX - 1 ];
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
	for( e = 1; e < MAX; ++e )
	{
		if( e < MAX - 1 )
		{
			printf( "%4d  ", e );
		}
		else
		{
			printf( "  19+ " );
		}
		length[ e ] = ( int )( ( length[ e ] * ( WIDTH / ( float )high ) ) + 0.99 );
		for( ee = 0; ee < length[ e ]; ++ee )
		{
			putchar( '|' );
		}
		putchar( '\n' );
	}

	return 0;
}
