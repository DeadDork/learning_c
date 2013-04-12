////////////////////////////////////////////////////////////////////////////////
// Comments

// Solution to ex. 2-9.

// Prompts for a number, then prints the number of 'on' bits in it.

// N.B. I added unneccessary parens to make the binary expressions easier to read.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>
#include <limits.h>

////////////////////////////////////////////////////////////////////////////////
// Symbolic Constants

#define FALSE 0
#define TRUE 1

////////////////////////////////////////////////////////////////////////////////
// External Variables

unsigned maxbit; // MAXimum number of bits in type unsigned int

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

unsigned clz( unsigned x );
/* Counts the number of leading zeros.
 
   `x` = Unsigned input integer from which to get the left-most 'on' bit.

   Returns the number of leading zeros. */

unsigned bitcount( unsigned x );
/* Counts the number of 'on' bits in a number.

   `x` = The number within which to count bits.

   Returns the number of 'on' bits. */

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

unsigned clz( unsigned x )
{
	int e; // Element

	for( e = 0; ( UINT_MAX / ( 1 << ( e + 1 ) ) > x ) && ( UINT_MAX / ( 1 << ( e + 1 ) ) != 1 ); ++e );

	return e;
}

void showbits( unsigned x )
{
	extern unsigned maxbit;

	int e ; // Element

	for( e = maxbit; e >= 0; --e )
	{
		printf( "%u", x >> e );
		x = x & ( ( 1 << e ) - 1 );
	}
	putchar( '\n' );
}

unsigned bitcount( unsigned x )
{
	int e; // Element

	for( e = 0; x > 0; ++e )
	{
		x &= x - 1;
	}

	return e;
}

////////////////////////////////////////////////////////////////////////////////
int main( void )
{
	extern unsigned maxbit;
	maxbit = clz( 0 );

	int c, in_num = FALSE; // Character, IN a NUMber
	unsigned total = 0;

	while( ( c = getchar() ) != EOF )
	{
		if( in_num && is_ws( c ) )
		{
			printf( "Bit field:\n\t%u = ", total );
			showbits( total );

			printf( "Number of 'on' bits:\n\t%u = %u\n", total, bitcount( total ) );

			in_num = FALSE;
			total = 0;
		}
		else if( !in_num && is_num( c ) )
		{
			total = c - '0';
			in_num = TRUE;
		}
		else if( in_num  && is_num( c ) )
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
