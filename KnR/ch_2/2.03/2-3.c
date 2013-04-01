////////////////////////////////////////////////////////////////////////////////
// Comments

// Solution to ex. 2-3.

// Negative numbers?

// Bug: maxes at the max size of unsigned long (in my implementation, that's
// 18446744073709551615).

// Will ignore non-hex strings in a file, but convert all hex strings
// (useful for tab separated mixed-values files).

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
// Symbolic Constants

#define NO 0
#define YES 1

////////////////////////////////////////////////////////////////////////////////
// Function Prototypes

int is_ws( char c );
/* Determines if a character is a white space characer.
 
   `c` = Input character to check.

   Return NO if it is not a white space character; YES if it is. */

int is_hex( char c );
/* Deterimes if a character is a hexadecimal character.
 
   `c` = Input character to check.

   Return NO if it is not a hexadecimal character; YES if it is. */

char lower( char c );
/* Take upper case letters and turns them into lower case letters.
 
   `c` = The input letter to lower.

   If the letter is already lower case, returns it as it is; if it is upper case, it makes it into a lower case.

   N.B. Ideally I would use the <ctype.h> library lower() function, but I wanted to get my hands dirty.
   
   N.B. I chose to lower as opposed to go upper case because lower case seems more common. */

int htoi( char c );
/* Take a hexadecimal input, and transform it into an integer value.
 
   `c` = The input hexadecimal character to transform.

   Returns the integer value of a hex.

   N.B. This has a "bug": non-hex characters will be assigned 0 same as '0'.
   Accordingly, this function should always be conditional on is_hex(). */

////////////////////////////////////////////////////////////////////////////////
// Functions

int is_ws( char c )
{
	if( c == ' ' || c == '\t' || c == '\n' )
	{
		return YES;
	}
	else
	{
		return NO;
	}
}

int is_hex( char c )
{
	if( ( c >= '0' && c <= '9' ) || ( c >= 'a' && c <= 'f' ) || ( c >= 'A' && c <= 'F' ) )
	{
		return YES;
	}
	else
	{
		return NO;
	}
}

char lower( char c )
{
	if( c >= 'A' && c <= 'Z' )
	{
		return c + ( 'a' - 'A' );
	}
	else
	{
		return c;
	}
}

int htoi( char c )
{
	int hexmap[ 16 ] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f' };
	int e; // Element

	for( e = 0; lower( c ) != hexmap[ e ] && e < 16; ++e );
	return e;
}

////////////////////////////////////////////////////////////////////////////////
int main( void )
{
	int c; // Character
	int pos = 0; // POSition
	unsigned long total;
	int in_hex = NO; // IN a HEXadecimal string

	while( ( c = getchar() ) != EOF )
	{
		if( is_ws( c ) )
		{
			if( in_hex == YES )
			{
				printf( "%lu", total );
				putchar( c );
				in_hex = NO;
			}
			total = pos = 0;
		}
		else if( pos == 0 && is_hex( c ) )
		{
			total = htoi( c );
			in_hex = YES;
			++pos;
		}
		else if( pos == 1 && total == 0 && ( c == 'x' || c == 'X' ) )
		{
			in_hex = NO; // in case input is ' 0x '
			++pos;
		}
		else if( pos == 1 && is_hex( c ) )
		{
			total = total * 16 + htoi( c );
			++pos;
		}
		else if( pos == 2 && is_hex( c ) )
		{
			total = total * 16 + htoi( c );
			in_hex = YES;
			++pos;
		}
		else if( pos > 2 && is_hex( c ) )
		{
			total = total * 16 + htoi( c );
		}
		else
		{
			in_hex = NO;
		}
	}

	return 0;
}
