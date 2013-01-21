////////////////////////////////////////////////////////////////////////////////
// Comments

// Solution to ex. 1-14.

// Though a vertical histogram looks better, I simply could not make 127 bars fit on a page. The alternative would have forced me to restrict the character set to just [:alnum:], and I decided against it.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
// Symbolic Constants

#define MAXW 160 // MAX histogram Width
#define MINA 0 // MIN Ascii number
#define MAXA 127 // MAX Ascii number

////////////////////////////////////////////////////////////////////////////////
int main()
{
	int c, e, ee, high;
	int length[ MAXA + 1 ];

	/* Character count */
	for( e = MINA; e <= MAXA; ++e )
	{
		length[ e ] = 0;
	}
	high = 0;

	while( ( c = getchar() ) != EOF )
	{
		if( ++length[ c ] > high )
		{
			high = length[ c ];
		}
	}

	/* Print histogram */
	for( e = MINA; e <= MAXA; ++e )
	{
		if( e == 0 )
		{
			printf( "[NUL] " );
		}
		else if( e == 1 )
		{
			printf( "[SOH] " );
		}
		else if( e == 2 )
		{
			printf( "[STX] " );
		}
		else if( e == 3 )
		{
			printf( "[ETX] " );
		}
		else if( e == 4 )
		{
			printf( "[EOT] " );
		}
		else if( e == 5 )
		{
			printf( "[ENQ] " );
		}
		else if( e == 6 )
		{
			printf( "[ACK] " );
		}
		else if( e == 7 )
		{
			printf( "[BEL] " );
		}
		else if( e == 8 )
		{
			printf( "[BS]  " );
		}
		else if( e == 9 )
		{
			printf( "[HT]  " );
		}
		else if( e == 10 )
		{
			printf( "[NL]  " );
		}
		else if( e == 11 )
		{
			printf( "[VT]  " );
		}
		else if( e == 12 )
		{
			printf( "[NP]  " );
		}
		else if( e == 13 )
		{
			printf( "[CR]  " );
		}
		else if( e == 14 )
		{
			printf( "[SO] " );
		}
		else if( e == 15 )
		{
			printf( "[SI] " );
		}
		else if( e == 16 )
		{
			printf( "[DLE] " );
		}
		else if( e == 17 )
		{
			printf( "[DC1] " );
		}
		else if( e == 18 )
		{
			printf( "[DC2] " );
		}
		else if( e == 19 )
		{
			printf( "[DC3] " );
		}
		else if( e == 20 )
		{
			printf( "[DC4] " );
		}
		else if( e == 21 )
		{
			printf( "[NAK] " );
		}
		else if( e == 22 )
		{
			printf( "[SYN] " );
		}
		else if( e == 23 )
		{
			printf( "[ETB] " );
		}
		else if( e == 24 )
		{
			printf( "[CAN] " );
		}
		else if( e == 25 )
		{
			printf( "[EM]  " );
		}
		else if( e == 26 )
		{
			printf( "[SUB] " );
		}
		else if( e == 27 )
		{
			printf( "[ESC] " );
		}
		else if( e == 28 )
		{
			printf( "[FS]  " );
		}
		else if( e == 29 )
		{
			printf( "[GS]  " );
		}
		else if( e == 30 )
		{
			printf( "[RS]  " );
		}
		else if( e == 31 )
		{
			printf( "[US]  " );
		}
		else if( e >= ' ' && e <= '~' )
		{
			printf( "[%c]   ", e );
		}
		else if( e == 127 )
		{
			printf( "[DEL] " );
		}

		for( ee = MINA; ee < ( int )( ( length[ e ] * ( MAXW / ( double )high ) ) + 0.99 ); ++ee ) // Adjusts width to fit screen
		{
			putchar( '|' );
		}
		putchar( '\n' );
	}

	return 0;
}
