////////////////////////////////////////////////////////////////////////////////
// Comments

// Solution to exercise 1-24.

// This program is a series of simple state machines. For the real thing, I
	// would instead have developed a series of functions that test the full
	// grammar of the C language.

// N.B. I hate how this program handles the nesting of parentheses, brackets, and
	// braces. However, without greater complexity (e.g. multidimensional arrays),
	// adding a feature to manage nesting would be a huge PITA.

// N.B. Semicolons are too tricky to handle without expanding this program
	// significantly.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
// Symbolic Constants

#define BRACE 0 // BRACEs
#define BCMNT 1 // Block CoMmeNT
#define LCMNT 2 // Line CoMmeNT
#define PAREN 3 // PARENtheses
#define BRACK 4 // BRACKets
#define SQUOT 5 // Single QUOTations
#define DQUOT 6 // Double QUOTations

#define FALSE 0
#define TRUE  1

////////////////////////////////////////////////////////////////////////////////
// Function Prototypes

void comnt_check( int cquad[], int pnctn_sts[] );
/* Determines if inside a comment.
 
   `cquad[]` = Four character long string array used to check previous input.

   `pnctn_sts[]` = Passes states of various punctuation marks. */

void squot_check( int cquad[], int pnctn_sts[] );
/* Determines if inside a single quote.
 
   `cquad[]` = Four character long string array used to check previous input.

   `pnctn_sts[]` = Passes states of various punctuation marks. */

void dquot_check( int cquad[], int pnctn_sts[] );
/* Determines if inside a double quote.
 
   `cquad[]` = Four character long string array used to check previous input.

   `pnctn_sts[]` = Passes states of various punctuation marks. */

void paren_check( int cquad[], int pnctn_sts[] );
/* Determines if a line has excess parentheses.
 
   `cquad[]` = Four character long string array used to check previous input.

   `pnctn_sts[]` = Passes states of various punctuation marks. */

void brack_check( int cquad[], int pnctn_sts[] );
/* Determines if a line has excess brackets.
 
   `cquad[]` = Four character long string array used to check previous input.

   `pnctn_sts[]` = Passes states of various punctuation marks. */

void brace_check( int cquad[], int pnctn_sts[] );
/* Determines if the total input has excess braces.
 
   `cquad[]` = Four character long string array used to check previous input.

   `pnctn_sts[]` = Passes states of various punctuation marks. */

void linerr( int pnctn_sts[], int row );
/* Prints out any punctuation errors that occur in a given line of input.
 
   `pnctn_sts[]` = Passes states of various punctuation marks.

   `row` = The current row number. */

void multerr( int pnctn_sts[] );
/* Prints out any punctuation errors that occur in the total input.
 
   `pnctn_sts[]` = Passes states of various punctuation marks. */

////////////////////////////////////////////////////////////////////////////////
// Functions

void comnt_check( int cquad[], int pnctn_sts[] )
{
	/* Determine if at start of comment */
	if( pnctn_sts[ LCMNT ] == FALSE && pnctn_sts[ BCMNT ] == FALSE && cquad[ 2 ] == '/' && cquad[ 3 ] == '/' )
	{
		pnctn_sts[ LCMNT ] = TRUE;
	}
	else if( pnctn_sts[ LCMNT ] == FALSE && pnctn_sts[ BCMNT ] == FALSE && cquad[ 2 ] == '/' && cquad[ 3 ] == '*' )
	{
		pnctn_sts[ BCMNT ] = TRUE;
	}
	/* Determine if at end of comment */
	else if( pnctn_sts[ LCMNT ] == TRUE && cquad[ 2 ] != '\\' && cquad[ 3 ] == '\n' )
	{
		pnctn_sts[ LCMNT ] = FALSE;
	}
	else if( pnctn_sts[ BCMNT ] == TRUE && cquad[ 2 ] == '*' && cquad[ 3 ] == '/' )
	{
		pnctn_sts[ BCMNT ] = FALSE;
	}
}

void squot_check( int cquad[], int pnctn_sts[] )
{
	/* Determine if at start of single quote */
	if( pnctn_sts[ SQUOT ] == FALSE && cquad[ 3 ] == '\'' )
	{
		pnctn_sts[ SQUOT ] = TRUE;
	}
	/* Determine if at end of single quote */
	else if( pnctn_sts[ SQUOT ] == TRUE && ( ( cquad[ 0 ] == '\'' && cquad[ 1 ] == '\\' ) || ( cquad[ 1 ] == '\'' && cquad[ 2 ] != '\'' && cquad[ 2 ] != '\\' ) || ( cquad[ 1 ] != '\'' && cquad[ 2 ] == '\'' ) ) && cquad[ 3 ] == '\'' )
	{
		pnctn_sts[ SQUOT ] = FALSE;
	}
}

void dquot_check( int cquad[], int pnctn_sts[] )
{
	/* Determine if in a double quote */
	if( pnctn_sts[ DQUOT ] == FALSE && cquad[ 3 ] == '"' )
	{
		pnctn_sts[ DQUOT ] = TRUE;
	}
	/* Determine if at end of double quote */
	else if( pnctn_sts[ DQUOT ] == TRUE && cquad[ 2 ] != '\\' && cquad[ 3 ] == '"' )
	{
		pnctn_sts[ DQUOT ] = FALSE;
	}
}

void paren_check( int cquad[], int pnctn_sts[] )
{
	/* Open parenthesis */
	if( cquad[ 3 ] == '(' )
	{
		++pnctn_sts[ PAREN ];
	}

	/* Close parenthesis */
	if( cquad[ 3 ] == ')' )
	{
		--pnctn_sts[ PAREN ];
	}
}

void brack_check( int cquad[], int pnctn_sts[] )
{
	/* Open bracket */
	if( cquad[ 3 ] == '[' )
	{
		++pnctn_sts[ BRACK ];
	}

	/* Close bracket */
	if( cquad[ 3 ] == ']' )
	{
		--pnctn_sts[ BRACK ];
	}
}

void brace_check( int cquad[], int pnctn_sts[] )
{
	/* Open brace */
	if( cquad[ 3 ] == '{' )
	{
		++pnctn_sts[ BRACE ];
	}

	/* Close brace */
	if( cquad[ 3 ] == '}' )
	{
		--pnctn_sts[ BRACE ];
	}
}

void linerr( int pnctn_sts[], int row )
{
	/* Single quotations error */
	if( pnctn_sts[ SQUOT ] == TRUE )
	{
		printf( "Line %d: single quotation error\n", row );
	}

	/* Double quotations error */
	if( pnctn_sts[ DQUOT ] == TRUE )
	{
		printf( "Line %d: double quotation error\n", row );
	}

	/* Parentheses error */
	if( pnctn_sts[ PAREN ] != 0 )
	{
		printf( "Line %d: parentheses error\n", row );
	}

	/* Brackets error */
	if( pnctn_sts[ BRACK ] != 0 )
	{
		printf( "Line %d: brackets error\n", row );
	}
}

void multerr( int pnctn_sts[] )
{
	/* Block comments error */
	if( pnctn_sts[ BCMNT ] == TRUE )
	{
		printf( "Error: open block comment\n" );
	}

	/* Braces error */
	if( pnctn_sts[ BRACE ] != 0 )
	{
		printf( "Error: open braces\n" );
	}
}

////////////////////////////////////////////////////////////////////////////////
int main( void )
{
	int c; // Character
	int cquad[ 4 ] = { '\0', '\0', '\0', '\0' }; // Character QUINTuple
	int pnctn_sts[ 7 ] = { FALSE, FALSE, FALSE, FALSE, FALSE, FALSE, FALSE }; // PuNCTuatioN STateS
	int row = 1;

	while( ( c = getchar() ) != EOF )
	{
		cquad[ 0 ] = cquad[ 1 ];
		cquad[ 1 ] = cquad[ 2 ];
		cquad[ 2 ] = cquad[ 3 ];
		cquad[ 3 ] = c;

		/* Comments check */
		if( pnctn_sts[ SQUOT ] == FALSE && pnctn_sts[ DQUOT ] == FALSE )
		{
			comnt_check( cquad, pnctn_sts );
		}

		/* Single quotes check */
		if( pnctn_sts[ LCMNT ] == FALSE && pnctn_sts[ BCMNT ] == FALSE && pnctn_sts[ DQUOT ] == FALSE )
		{
			squot_check( cquad, pnctn_sts );
		}

		/* Double quotes check */
		if( pnctn_sts[ LCMNT ] == FALSE && pnctn_sts[ BCMNT ] == FALSE && pnctn_sts[ SQUOT ] == FALSE )
		{
			dquot_check( cquad, pnctn_sts );
		}

		/* Parentheses, brackets, and braces check */
		if( pnctn_sts[ LCMNT ] == FALSE && pnctn_sts[ BCMNT ] == FALSE && pnctn_sts[ SQUOT ] == FALSE && pnctn_sts[ DQUOT ] == FALSE )
		{
			paren_check( cquad, pnctn_sts );
			brack_check( cquad, pnctn_sts );
			brace_check( cquad, pnctn_sts );
		}

		/* Print lines that have bad single & double quotes, parentheses, or brackets */
		if( cquad[ 2 ] != '\\' && cquad[ 3 ] == '\n' )
		{
			linerr( pnctn_sts, row++ );

			pnctn_sts[ SQUOT ] = pnctn_sts[ DQUOT ] = pnctn_sts[ PAREN ] = pnctn_sts[ BRACK ] = FALSE;
		}
	}

	/* Print lines that have bad braces or block comments */
	multerr( pnctn_sts );

	return 0;
}
