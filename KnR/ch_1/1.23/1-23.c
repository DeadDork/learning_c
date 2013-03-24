////////////////////////////////////////////////////////////////////////////////
// Comments

// Solution to ex. 1-23.

// N.B. The output has too many spaces. However, I felt that rather than address
// this by adding spacing features to this program, it was better left to a
// second program. Otherwise, this program loses generality (god knows that
// there are a multitude of comment styles).

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
// Symbolic Constants

#define FALSE 0
#define TRUE 1

////////////////////////////////////////////////////////////////////////////////
// External Variables

int linecomm; // LINE COMMent
int blockcomm; // BLOCK COMMent

////////////////////////////////////////////////////////////////////////////////
// Function Prototypes

int incomment( char ctriple[] );
/* Determines if there is a comment.
 
   `ctriple[]` = Three character long string array used to check if there is a comment.

   Returns TRUE if the current character from STDIN is inside either a block or line
   comment; otherwise returns FALSE. */

////////////////////////////////////////////////////////////////////////////////
// Functions

int incomment( char ctriple[] )
{
	extern int linecomm;
	extern int blockcomm;

	int value; // return VALUE

	/* "Look ahead" in case the latest character is a possible comment character */
	if( ctriple[ 2 ] == '/' )
	{
		ctriple[ 0 ] = ctriple[ 1 ];
		ctriple[ 1 ] = ctriple[ 2 ];
		ctriple[ 2 ] = getchar();
	}

	/* Determine if in a comment */
	if( linecomm == FALSE && blockcomm == FALSE && ctriple[ 1 ] == '/' && ctriple[ 2 ] == '/' )
	{
		linecomm = TRUE;
	}
	if( linecomm == FALSE && blockcomm == FALSE && ctriple[ 1 ] == '/' && ctriple[ 2 ] == '*' )
	{
		blockcomm = TRUE;
	}

	/* Determine if NOT in a comment */
	if( linecomm == TRUE && ctriple[ 2 ] == '\n' )
	{
		linecomm = FALSE;
	}
	if( blockcomm == TRUE && ctriple[ 0 ] == '*' && ctriple[ 1 ] == '/' )
	{
		blockcomm = FALSE;
	}

	if( linecomm == TRUE || blockcomm == TRUE )
	{
		value = TRUE;
	}
	else
	{
		value = FALSE;
	}
	return value;
}

////////////////////////////////////////////////////////////////////////////////
int main( void )
{
	extern int linecomm;
	extern int blockcomm;
	linecomm = FALSE;
	blockcomm = FALSE;

	int c; // Character
	char ctriple[ 3 ]; // Character TRIPLE

	/* Usually the last element in a string array is assigned a NULL.
	   N.B. ctripple[ 1 ] is assigned ctripple[ 2 ] in main(),
	   and ctripple[ 0 ] is assigned ctripple[ 1 ] and ctripple[ 1 ]
	   is assigned ctripple[ 2 ] in incomment(). */
	ctriple[ 2 ] = '\0';

	while( ( c = getchar() ) != EOF )
	{
		ctriple[ 0 ] = ctriple[ 1 ];
		ctriple[ 1 ] = ctriple[ 2 ];
		ctriple[ 2 ] = c;
		if( !( incomment( ctriple ) ) )
		{
			putchar( ctriple[ 2 ] );
		}
	}

	return 0;
}
