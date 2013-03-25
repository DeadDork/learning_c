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

#define LINE 0 // LINE comment
#define BLOCK 1 // BLOCK comment

////////////////////////////////////////////////////////////////////////////////
// Function Prototypes

int incomment( int ctriple[], int cmnt[] );
/* Determines if there is a comment.
 
   `ctriple[]` = Three character long string array used to check if there is a comment.

   `cmnt[]` = A safe way to pass whether in a line or block comment (relative to 
   external variables).

   Returns TRUE if the current character from STDIN is inside either a block or line
   comment; otherwise returns FALSE.
   
   N.B. Because incomment() assigns to ctriple[ 2 ] the return value from getchar(),
   ctriple[] has to be an int in case of EOF. */

////////////////////////////////////////////////////////////////////////////////
// Functions

int incomment( int ctriple[], int cmnt[] )
{
	int value; // return VALUE

	/* "Look ahead" in case the latest character is a possible comment character */
	if( ctriple[ 2 ] == '/' )
	{
		ctriple[ 0 ] = ctriple[ 1 ];
		ctriple[ 1 ] = ctriple[ 2 ];
		ctriple[ 2 ] = getchar();
	}

	/* Determine if in a comment */
	if( cmnt[ LINE ] == FALSE && cmnt[ BLOCK ] == FALSE && ctriple[ 1 ] == '/' && ctriple[ 2 ] == '/' )
	{
		cmnt[ LINE ] = TRUE;
	}
	if( cmnt[ LINE ] == FALSE && cmnt[ BLOCK ] == FALSE && ctriple[ 1 ] == '/' && ctriple[ 2 ] == '*' )
	{
		cmnt[ BLOCK ] = TRUE;
	}

	/* Determine if NOT in a comment */
	if( cmnt[ LINE ] == TRUE && ctriple[ 2 ] == '\n' )
	{
		cmnt[ LINE ] = FALSE;
	}
	if( cmnt[ BLOCK ] == TRUE && ctriple[ 0 ] == '*' && ctriple[ 1 ] == '/' )
	{
		cmnt[ BLOCK ] = FALSE;
	}

	if( cmnt[ LINE ] == TRUE || cmnt[ BLOCK ] == TRUE )
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
	int c; // Character
	int ctriple[ 3 ]; // Character TRIPLE
	int cmnt[ 2 ]; // CoMmeNT

	cmnt[ LINE ] = FALSE;
	cmnt[ BLOCK ] = FALSE;

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
		if( !( incomment( ctriple, cmnt ) ) )
		{
			putchar( ctriple[ 2 ] );
		}
	}

	return 0;
}
