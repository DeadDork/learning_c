////////////////////////////////////////////////////////////////////////////////
// Comments

// Solution to exercise 2-7.

// Demonstrates the use of setbits().

// show_bits() uses <math.h>, which I'm not supposed to "know" about yet.
// However, as show_bits() is completely secondary to this exercise, but quite
// illustrative, I decided to use it anyway.

// N.B. I added unneccessary parens to make the binary expressions easier to read.

// N.B. Freaky behavior: enter '1,2', and this program will treat the ',' as a ws
// character.

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

unsigned invert( unsigned src_bf, unsigned inv_spos, unsigned inv_len );
/* Invert the bit field in src_bf starting at inv_spos and of inv_len length.

   `src_bf` = SouRCe Bit Field.

   `inv_spos` = Start POSition in source bit field to begin INVersion.

   `inv_len` = LENgth of INVersion from start position in the source bit field.

   Returns the new bit field.

   N.B. bit fields are numbered from right to left, e.g. in '000100', '1' is in
   position 2 and the rightmost '0' is in position 0.

   N.B. Lengths are measured left to right, e.g. invert( 31, 3, 3 ) would
   change '11111' to '10001' and invert( 31, 3, 2 ) would change '11111' to
   '10011'. */

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
	extern unsigned maxbit;

	int e ; // Element

	for( e = maxbit; e >= 0; --e )
	{
		printf( "%u", x >> e );
		x = x & ( ( 1 << e ) - 1 );
	}
	putchar( '\n' );
}

unsigned invert( unsigned src_bf, unsigned inv_spos, unsigned inv_len )
{
	return src_bf ^ ( ( ( 1 << inv_len ) - 1 ) << ( ( inv_spos + 1 ) - inv_len ) );
}

////////////////////////////////////////////////////////////////////////////////
int main( void )
{
	extern unsigned maxbit;
	maxbit = ( unsigned )( log( UINT_MAX ) / log( 2 ) );

	int c, pos_bool = FALSE, len_bool = FALSE; // Character, POSition boolean, LENgth boolean
	unsigned bf = 0, pos_val = 0, len_val = 0; // Bit Field,  POSition VALue, LENgth VALue

	while( ( c = getchar() ) != EOF )
	{
		if( pos_bool && len_bool && ( pos_val < maxbit && ( pos_val + 1 ) >= len_val ) && is_ws( c ) )
		{
			printf( "Original bit field:\n\t%u = ", bf );
			showbits( bf );

			bf = invert( bf, pos_val, len_val );
			printf( "Replaced bit field:\n\t%u = ", bf );
			showbits( bf );

			pos_bool = len_bool = FALSE;
			pos_val = len_val = 0;
		}
		else if( !pos_bool && is_num( c ) )
		{
			pos_val = pos_val * 10 + c - '0';
		}
		else if( !pos_bool && !is_num( c ) )
		{
			pos_bool = TRUE;
		}
		else if( pos_bool && !len_bool && is_num( c ) )
		{
			len_val = c - '0';
			len_bool = TRUE;
		}
		else if( len_bool && is_num( c ) )
		{
			len_val = len_val * 10 + c - '0';
		}
		else if( !is_ws( c ) )
		{
			pos_bool = len_bool = FALSE;
			pos_val = len_val = 0;
		}
	}

	return 0;
}
