////////////////////////////////////////////////////////////////////////////////
// Comments

// Solution to ex. 2-5.

// Returns the first position in a source array where any character from a
// match array occurs.

// N.B. Stops assigning characters to source string in lines with over
// MAXLEN - 1 characters.

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

int cmatch( char c, char mstr[] );
/* Determines whether a character is in a character array.
 
   `c` = The character to check for in the array.

   `mstr[]` = The character array to check.

   Returns TRUE if the character exists in the array; otherwise FALSE. */

int smatch( char sstr[], char mstr[] );
/* Determines the position of any character in a match string in a source string.
 
   `sstr[]` = Source string.

   `mstr[]` = Match string.

   If there is a match, returns the array position of the first match;
   if there is NO match, returns -1. */

////////////////////////////////////////////////////////////////////////////////
// Functions

int cmatch( char c, char mstr[] )
{
	int e; // Element

	for( e = 0; mstr[ e ] != NUL; ++e )
	{
		if( c == mstr[ e ] )
		{
			return TRUE;
		}
	}

	return FALSE;
}

int smatch( char sstr[], char mstr[] )
{
	int e; // Element

	for( e = 0; sstr[ e ] != NUL && !cmatch( sstr[ e ], mstr ); ++e );
	if( cmatch( sstr[ e ], mstr ) )
	{
		return e; // match
	}
	else 
	{
		return -1; // no match
	}
}

////////////////////////////////////////////////////////////////////////////////
int main( void )
{
	int c; // Character
	char src[ MAXLEN ]; // SouRCe String
	char mtch[ MAXLEN ]; // MaTCH String
	int pos = 0; // POSition

	mtch[ 0 ] = 'a';
	mtch[ 1 ] = 'b';
	mtch[ 2 ] = 'c';
	mtch[ 3 ] = 'd';
	mtch[ 4 ] = NUL;

	while( ( c = getchar() ) != EOF )
	{
		if( c == '\n' || pos == MAXLEN - 1 )
		{
			if( pos < MAXLEN )
			{
				src[ pos ] = NUL;
				printf( "%d\n", smatch( src, mtch ) );
			}

			if( c == '\n' )
			{
				pos = 0;
			}
			/* Waits for newline if line longer than MAXLEN - 1 */
			else if( pos == MAXLEN - 1)
			{
				pos = MAXLEN;
			}
		}
		else if( pos < MAXLEN - 1 )
		{
			src[ pos++ ] = c;
		}
	}

	return 0;
}
