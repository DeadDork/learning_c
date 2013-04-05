////////////////////////////////////////////////////////////////////////////////
// Comments

// getbits() is a crazy-looking example from 2-9 that I had to try out.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>
#include <limits.h>
#include <math.h>

////////////////////////////////////////////////////////////////////////////////
// Symbolic Constants

#define FALSE 0
#define TRUE 1

////////////////////////////////////////////////////////////////////////////////
// Function Prototypes

int is_num( char c );
/* Determines if a character is a number character or not.
 
   `c` = Input character to check.

   Returns TRUE if `c` is a number character; otherwise returns FALSE. */

unsigned getbits( unsigned x, int p, int n );
/* Get the desired slice of a bit-field.
 
   `x` = The source bit-field.

   `p` = The beginning position of the slice.

   `n` = The length of the slice. */

void showbits( unsigned x );
/* Prints the bit field representation of an unsigned input integer.
 
   `x` = Unsigned input integer to represent as a bit field. */

////////////////////////////////////////////////////////////////////////////////
// Functions

int is_num( char c )
{
	if( c >= '0' && c <= '9' )
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

unsigned getbits( unsigned x, int p, int n )
{
	return ( x >> ( p + 1 - n ) ) & ~( ~0 << n );
}

void showbits( unsigned x )
{
	int e ; // Element
	int maxbit = ( int )log( UINT_MAX ) / log( 2 );

	for( e = maxbit; e >= 0; --e )
	{
		printf( "%u", x >> e );
		x = x << maxbit - ( e - 1 );
		x = x >> maxbit - ( e - 1 );
	}
	putchar( '\n' );
}

////////////////////////////////////////////////////////////////////////////////
int main( void )
{
	int c, x = 0, p, n, in_num = FALSE;

	while( ( c = getchar() ) != EOF )
	{
		if( in_num && !is_num( c ) )
		{
			p = ( int )( log( x ) / log( 2 ) );
			n = ( x >= 4 ) ? 3 : ( int )( log( x ) / log( 2 ) ) + 1;

			printf( "Full bit-field ( %u )  = ", x );
			showbits( x );
			printf( "Bit-field slice ( %u ) = ", getbits( x, p, n ) );
			showbits( getbits( x, p, n ) );

			in_num = FALSE;
		}
		else if( !in_num && is_num( c ) )
		{
			x = c - '0';

			in_num = TRUE;
		}
		else if( in_num && is_num( c ) )
		{
			x = x * 10 + c - '0';
		}
	}

	return 0;
}
