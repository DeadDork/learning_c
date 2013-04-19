////////////////////////////////////////////////////////////////////////////////
// Comments

// Solution to ex. 3-3.

// Print input. If the input can be expanded, it will be expanded accordingly
// (e.g. '-b-f-7-9-S-U-0-2F-Jh-l-' will expand to '-bcdef-789-STU-012FGHIJhijkl-').

// N.B. This program works well when receiving stdin from file, but not so well
// when receiving stdin from user. That is, it doesn't function well as a REPL,
// wholey as a result of the default STTY setting. A simple solution, then, is
// to just set STTY to RAW. However, as this requires a system call, it
// goes beyond the scope of K & R at this point. Still, brother needs a REPL.
//
// ...OK, I take it all back. Futzing with system IO is an inglorious time suck.
//
// ...Screw this. Learn to live without a REPL.

// Bug: note that in the test file, '-1-b-g-H-I-9-' does not print out as
// '-1-bcdefg-HI-9-'. Fuck.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
// Symbolic Constants

#define FALSE 0
#define TRUE 1

#define ALPHA 26 // number of letters in the ALPHAbet

#define NUL '\0' // NULl character

////////////////////////////////////////////////////////////////////////////////
// Function Prototypes

int expandable( int c );
/* Determines whether a character is in the expansion set.
 
   `c` = The character which will be determined to be in the expansion set or
   not.

   Returns TRUE if `c` is in the expansion set; otherwise returns FALSE. */

void expand( int compacted[], char expanded[] );
/* Expands a compacted string into its full range of the expansion set.
 
   `compacted[]` = The compacted representation of a range in the expansion set.

   `expanded[]` = The full range of the expansion set represented by
   'compacted[]'. */

////////////////////////////////////////////////////////////////////////////////
// Functions

int expandable( int c )
{
	if( ( c >= '0' && c <= '9' ) ||
		( c >= 'A' && c <= 'Z' ) ||
		( c >= 'a' && c <= 'z' ) )
	{
		return TRUE; // c *is* an expandable character
	}
	return FALSE; // c is *not* an expandable character
}

void expand( int compacted[], char expanded[] )
{
	int e, ee; // Element

	/* The number expansion set range */
	if( ( compacted[ 0 ] >= '0' && compacted[ 0 ] <= '9' ) &&
		( compacted[ 2 ] >= '0' && compacted[ 2 ] <= '9' ) &&
		( compacted[ 0 ] <= compacted[ 2 ] ) )
	{
		for( e = compacted[ 0 ], ee = 0; e <= compacted[ 2 ]; ++e, ++ee )
		{
			expanded[ ee ] = e;
		}
		expanded[ ee ] = NUL;
	}
	/* The upper case expansion set range */
	else if( ( compacted[ 0 ] >= 'A' && compacted[ 0 ] <= 'Z' ) &&
			 ( compacted[ 2 ] >= 'A' && compacted[ 2 ] <= 'Z' ) &&
			 ( compacted[ 0 ] <= compacted[ 2 ] ) )
	{
		for( e = compacted[ 0 ], ee = 0; e <= compacted[ 2 ]; ++e, ++ee )
		{
			expanded[ ee ] = e;
		}
		expanded[ ee ] = NUL;
	}
	/* The lower case expansion set range */
	else if( ( compacted[ 0 ] >= 'a' && compacted[ 0 ] <= 'z' ) &&
			 ( compacted[ 2 ] >= 'a' && compacted[ 2 ] <= 'z' ) &&
			 ( compacted[ 0 ] <= compacted[ 2 ] ) )
	{
		for( e = compacted[ 0 ], ee = 0; e <= compacted[ 2 ]; ++e, ++ee )
		{
			expanded[ ee ] = e;
		}
		expanded[ ee ] = NUL;
	}
	/* If compact[] is a false positive of a compact representation of
	   an expansion set, then the expansion string is set to the
	   false positive */
	else
	{
		expanded[ 0 ] = compacted[ 0 ];
		expanded[ 1 ] = compacted[ 1 ];
		expanded[ 2 ] = compacted[ 2 ];
		expanded[ 3 ] = NUL;
	}
}

////////////////////////////////////////////////////////////////////////////////
int main( void )
{
	int triplec[ 3 ] = { NUL, NUL, NUL }; // TRIPLE Character string
	int nextc = NUL, lastc; // NEXT Character, LAST Character
	char expanded[ ALPHA + 1 ]; // EXPANDED compacted string + a terminal null
	                            // (the expansion set is at its largest
	                            // alphabet-sized)

	for( ; ; )
	{
		/* Fill in triplec buffer */
		if( triplec[ 0 ] == NUL )
		{
			triplec[ 0 ] = nextc; // Assign to current the "old" next character

			/* Get next character */
			if( ( nextc = getchar() ) == EOF )
			{
				printf( "%c", triplec[ 0 ] ); // Print previous character if at EOF
				lastc = triplec[ 0 ]; // To determine if a final newline is needed
				break; // End loop if at EOF
			}
		}
		else if( triplec[ 1 ] == NUL )
		{
			triplec[ 1 ] = nextc;

			if( ( nextc = getchar() ) == EOF )
			{
				printf( "%c%c", triplec[ 0 ], triplec[ 1 ] );
				lastc = triplec[ 1 ];
				break;
			}
		}
		else if( triplec[ 2 ] == NUL )
		{
			triplec[ 2 ] = nextc;

			if( ( nextc = getchar() ) == EOF )
			{
				lastc = triplec[ 2 ];
			}
		}
		/* If compaction buffer matches a compact representation of an expansion set */
		else if( expandable( triplec[ 0 ] ) && triplec[ 1 ] == '-' && expandable( triplec[ 2 ] ) )
		{
			/* Expand and print */
			expand( triplec, expanded );
			printf( "%s", expanded );

			/* If at EOF, then exit loop; otherwise clear the compaction buffer */
			if( nextc == EOF )
			{
				break;
			}
			else
			{
				triplec[ 0 ] = triplec[ 1 ] = triplec[ 2 ] = NUL;
			}
		}
		/* If the compaction buffer doesn't match a compact representation, in which
		   case print the first character and shift the buffer to the left */
		else
		{
			printf( "%c", triplec[ 0 ] );
			triplec[ 0 ] = triplec[ 1 ];
			triplec[ 1 ] = triplec[ 2 ];
			triplec[ 2 ] = nextc;
			nextc = getchar();
		}
	}
	if( lastc != '\n' )
	{
		putchar( '\n' );
	}

	return 0;
}
