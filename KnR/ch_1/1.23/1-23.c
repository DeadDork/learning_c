////////////////////////////////////////////////////////////////////////////////
// Comments

// Solution to ex. 1-23.

// N.B. The output has unattractive spacing. However, rather than addressing
// this issue in this program, I thought it better to modularize the code
// as much as possible, such that this program handles comment removal,
// and a second program handles spacing.

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

int incomment( int ctriple[] );
/* Determines if there is a comment.
 
   `ctriple[]` = Three character long string array used to check if there is a comment.

   Returns TRUE if the current character from STDIN is inside either a block or line
   comment; otherwise returns FALSE.
   
   N.B. Because incomment() assigns to ctriple[ 2 ] the return value from getchar(),
   ctriple[] has to be an int in case of EOF. */

////////////////////////////////////////////////////////////////////////////////
// Functions

int incomment( int ctriple[] )
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
	int ctriple[ 3 ]; // Character TRIPLE

	/* ctripple[ 1 ] is assigned ctripple[ 2 ] in main(),
	   and in incomment() ctripple[ 0 ] is assigned ctripple[ 1 ]
	   and ctripple[ 1 ] is assigned ctripple[ 2 ]. By assigning
	   ctriple[ 2 ] a NULL, ctriple[] won't have any funky memory artifacts. */
	ctriple[ 2 ] = '\0';

	while( ctriple[ 2 ] != EOF && ( c = getchar() ) != EOF )
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
