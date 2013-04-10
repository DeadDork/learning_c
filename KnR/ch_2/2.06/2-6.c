////////////////////////////////////////////////////////////////////////////////
// Comments

// Solution to exercise 2-6.

// Demonstrates the use of setbits().

// show_bits() uses <math.h>, which I'm not supposed to "know" about yet.
// However, as show_bits() is completely secondary to this exercise, but quite
// illustrative, I decided to use it anyway.

// N.B. I added unneccessary parens to make the binary expressions easier to read.

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

unsigned setbits( unsigned src_bf, unsigned src_pos, unsigned sub_len, unsigned sub_bf );
/* Substitutes the bit field in src_bf starting at src_rp and of length sub_len with
   the bit field of length sub_len from the right end of sub_bf.

   `src_bf` = SouRCe Bit Field.

   `src_pos` = SouRCe bit field replace start POSition.

   `sub_len` = SUBstitute bit field replace LENgth.

   `sub_bf` = SUBstitute Bit Field.

   Returns the new bit field.

   (N.B. bit fields are numbered from right to left, e.g. in '000100', '1' is in
   position 2 and the rightmost '0' is in position 0). */

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
	int maxbit = ( unsigned )( log( UINT_MAX ) / log( 2 ) );

	for( e = maxbit; e >= 0; --e )
	{
		printf( "%u", x >> e );
		x = x & ( ( 1 << e ) - 1 );
	}
	putchar( '\n' );
}

unsigned setbits( unsigned src_bf, unsigned src_pos, unsigned sub_len, unsigned sub_bf )
{
	unsigned mask_1, mask_2;

	/* Creates a mask that's identical to src_bf, except that the substitution area
	   is replaced with 1's */
	mask_1 = src_bf | ( ( ( 1 << sub_len ) - 1 ) << ( ( src_pos + 1 ) - sub_len ) );

	/* Creates a mask of 1's except at the substitution area, which instead has the
	   desired substitution bit field segment */
	mask_2 = ( ( ( ~0 << sub_len ) | sub_bf ) << ( ( src_pos + 1 ) - sub_len ) ) | ~( ~0 << ( ( src_pos + 1 ) - sub_len ) );

	return mask_1 & mask_2;
}

////////////////////////////////////////////////////////////////////////////////
int main( void )
{
	int c, in_num = FALSE; // Character, IN a NUMber
	unsigned bf_old = 0, bf_new = 0, pos_new, len_new; // OLD Bit Field, NEW Bit Field, start POSition of NEW bit field in old bit field, field LENgth of NEW bit field

	while( ( c = getchar() ) != EOF )
	{
		if( in_num && is_ws( c ) )
		{
			printf( "Original bit field:\n\t%u = ", bf_old );
			showbits( bf_old );

			printf( "Replacement bit field:\n\t%u = ", bf_new );
			showbits( bf_new );

			pos_new = ( unsigned )( log( bf_new ) / log( 2 ) );
			len_new = pos_new + 1;
			bf_old = setbits( bf_old, pos_new, len_new, bf_new );
			printf( "Replaced bit field:\n\t%u = ", bf_old );
			showbits( bf_old );

			in_num = FALSE;
			bf_new = 0;
		}
		else if( !in_num && is_num( c ) )
		{
			bf_new = c - '0';
			in_num = TRUE;
		}
		else if( in_num && is_num( c ) )
		{
			bf_new = bf_new * 10 + c - '0';
		}
		else
		{
			in_num = FALSE;
			bf_new = 0;
		}
	}

	return 0;
}
