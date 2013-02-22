////////////////////////////////////////////////////////////////////////////////
// Comments

// Solution to ex. 1-19.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
// Symbolic Constants

#define MAXLEN 100 // MAXimum LENgth of string

////////////////////////////////////////////////////////////////////////////////
// Function Prototypes

void reverse( char string[] );
/* Reverses the order of elements in a character array.
 
   *string* = string that will have it's character order reversed (e.g. "abc" --> "cba"). */

////////////////////////////////////////////////////////////////////////////////
// Functions

void reverse( char string[] )
{
	int e, sz; // Element, array SiZe
	char temp[ MAXLEN ]; // TEMPorary array

	for( sz = 0; string[ sz ] != '\0'; ++sz )
	{
		temp[ sz ] = string[ sz ];
	}

	for( e = 0; e < sz; ++e )
	{
		string[ e ] = temp[ sz - ( e + 1 ) ];
	}
}

////////////////////////////////////////////////////////////////////////////////
int main()
{
	int c, n; // Character, Number
	char buf[ MAXLEN ]; // BUFfer

	n = 0;
	while( ( c = getchar() ) != EOF )
	{
		if( c != '\n' )
		{
			if( n < MAXLEN )
			{
				buf[ n++ ] = c;
			}
		}
		else
		{
			if( n < MAXLEN )
			{
				buf[ n ] = '\0';
			}
			else
			{
				buf[ --n ] = '\0';
			}

			// Prettified
			/*
			if( n > 0 )
			{
				printf( "Original: [%s]\n", buf );
				reverse( buf );
				printf( "Reverse:  [%s]\n", buf );
			}
			*/
			// Unixfied
			reverse( buf );
			printf( "%s\n", buf );

			n = 0;
		}
	}

	return 0;
}
