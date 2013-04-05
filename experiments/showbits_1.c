////////////////////////////////////////////////////////////////////////////////
// Comments

// Prints the bit-field of a given unsigned integer.

// Bug: doesn't handle under or over flows.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>
#include <math.h>
#include <limits.h>

////////////////////////////////////////////////////////////////////////////////
// Symbolic Constants

#define FALSE 0
#define TRUE 1

////////////////////////////////////////////////////////////////////////////////
// Function Prototype

int is_ws( char c );
/* Determines if a character is a whitespace character or not.
 
   `c` = Input character to check.

   Returns TRUE if `c` is a white space character; otherwise false. */

int is_num( char c );
/* Determines if a character is a number character or not.
 
   `c` = Input character to check.

   Returns TRUE if `c` is a number character; otherwise returns FALSE. */

void showbits( unsigned x );
/* Prints the bit field representation of an unsigned input integer.
 
   `x` = Unsigned input integer to represent as a bit field. */

////////////////////////////////////////////////////////////////////////////////
// Functions

int is_ws( char c )
{
	if( c == ' ' || c == '\t' || c == '\n' )
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

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
	int c, in_num = FALSE; // Character, IN a NUMber
	unsigned total = 0;

	while( ( c = getchar() ) != EOF )
	{
		if( in_num && is_ws( c ) )
		{
			printf( "%u = ", total );
			showbits( total );
			in_num = FALSE;
			total = 0;
		}
		else if( !in_num && is_num( c ) )
		{
			total = c - '0';
			in_num = TRUE;
		}
		else if( in_num && is_num( c ) )
		{
			total = total * 10 + c - '0';
		}
		else
		{
			in_num = FALSE;
			total = 0;
		}
	}

	return 0;
}
