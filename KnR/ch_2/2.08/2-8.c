////////////////////////////////////////////////////////////////////////////////
// Comments

// Solution to ex. 2-8.

// N.B. I'm not quite clear what it means to 'rotate'. I am assuming for the
// sake of this exercise that it means to shift the value of a bit one over for
// all bits but the first one, the value of which is rotated to the end of the
// bit field.

// N.B. I added unneccessary parens to make the binary expressions easier to read.

// I used recursion in rightrot. I'm not sure if I'm supposed to "know" it yet...
// It's one of those things, though, that "just makes" sense, so I'm using it.

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

unsigned l_m_bit( unsigned src_bf );
/* Gets the position of the left-most 'on' bit in an unsigned int.
 
   `x` = Unsigned input integer from which to get the left-most 'on' bit.

   Returns the aforementioned bit position. */

unsigned rightrot( unsigned src_bf, unsigned rot_num );
/* Rotates bit field src_bf to the right rot_num bit spaces.

   `src_bf` = SouRCe Bit Field to rotate.

   `rot_num` = NUMber of bit spaces to ROTate to the right.

   Returns the new bit field. */

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

unsigned l_m_bit( unsigned src_bf )
{
	int e; // Element

	for( e = 0; src_bf > 1; ++e )
	{
		src_bf = src_bf >> 1;
	}

	return e;
}

unsigned rightrot( unsigned src_bf, unsigned rot_num )
{
	extern unsigned maxbit;

	if( rot_num > maxbit )
	{
		return rightrot( src_bf, rot_num - maxbit );
	}
	else
	{
		return ( src_bf >> rot_num ) | ( src_bf << ( maxbit - rot_num ) );
	}
}

////////////////////////////////////////////////////////////////////////////////
int main( void )
{
	extern unsigned maxbit;
	maxbit = l_m_bit( UINT_MAX );

	int c, in_num = FALSE; // Character, IN a NUMber
	unsigned bf = ( 1 << ( maxbit / 2 ) ) - 1, rot_num = 0; // Bit Field, NUMber of spaces to ROTate

	while( ( c = getchar() ) != EOF )
	{
		if( in_num && is_ws( c ) )
		{
			printf( "Old bit field:\n\t%u = ", bf );
			showbits( bf );

			bf = rightrot( bf, rot_num );
			printf( "New bit field:\n\t%u = ", bf );
			showbits( bf );

			in_num = FALSE;
			rot_num = 0;
		}
		else if( !in_num && is_num( c ) )
		{
			rot_num = c - '0';
			in_num = TRUE;
		}
		else if( in_num  && is_num( c ) )
		{
			rot_num = rot_num * 10 + c - '0';
		}
		else
		{
			in_num = FALSE;
			rot_num = 0;
		}
	}

	return 0;
}
