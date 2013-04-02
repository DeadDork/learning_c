////////////////////////////////////////////////////////////////////////////////
// Comments

// Solution to exercise 2-4.

// "Squeezes" a source string, such that any characters in a squeeze string are
// removed from it.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
// Symbolic Constants

#define MAXLEN 1000 // MAXimum LENgth of string array
#define NUL '\0' // end of string NULl character

#define FALSE 0
#define TRUE 1

////////////////////////////////////////////////////////////////////////////////
// Function Prototypes

void squeeze( char string[], char sqzstr[] );
/* Deletes all occurrences of the characters in sqzstr[] from string[]/
 
   `string[]` = The source string to be acted on.

   `sqzstr[]` = The array with all of the characters to delete from string[]. */

int cmatch( char c, char mstr[] );
/* Determines whether a character is in a character array.
 
   `c` = The character to check for in the array.

   `mstr[]` = The character array to check.

   Returns TRUE if the character exists in the array; otherwise FALSE. */

////////////////////////////////////////////////////////////////////////////////
// Functions

int cmatch( char c, char mstr[] )
{
	int e; // Element
	int value = FALSE; // return VALUE

	for( e = 0; mstr[ e ] != NUL; ++e )
	{
		if( c == mstr[ e ] )
		{
			value = TRUE;
		}
	}

	return value;
}

void squeeze( char string[], char sqzstr[] )
{
	int e, ee; // Element, Element copy 1, Element copy 2
	char sstring[ MAXLEN ]; // STRING[] copy 1

	for( e = ee = 0; string[ e ] != NUL; ++e )
	{
		if( !cmatch( string[ e ], sqzstr ) )
		{
			sstring[ ee++ ] = string[ e ];
		}
	}
	sstring[ ee ] = NUL;

	while( ee >= 0 )
	{
		string[ ee ] = sstring[ ee ];
		--ee;
	}
}

////////////////////////////////////////////////////////////////////////////////
int main( void )
{
	int c; // Character
	char s[ MAXLEN ]; // source String
	char ss[ MAXLEN ]; // squeeze String
	int pos = 0; // POSition

	ss[ 0 ] = 'a';
	ss[ 1 ] = 'b';
	ss[ 2 ] = 'c';
	ss[ 3 ] = 'd';
	ss[ 4 ] = NUL;

	while( ( c = getchar() ) != EOF )
	{
		if( c == '\n' || pos == MAXLEN - 1 )
		{
			s[ pos ] = NUL;
			squeeze( s, ss );
			printf( "%s\n", s );
			pos = 0;
		}
		else
		{
			s[ pos++ ] = c;
		}
	}

	return 0;
}
