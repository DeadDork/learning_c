////////////////////////////////////////////////////////////////////////////////
// Comments

// Solution to ex. 3-3.

// Print input to output. If the input is in the form of a compact expansion
// set, then expand the set appropriately (e.g. '-b-f-7-9-S-U-0-2F-Jh-l-' will
// expand to '-bcdef-789-STU-012FGHIJhijkl-').

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

void expand( char compacted[], char expanded[] );
/* Expands a compacted string into its full range of the expansion set.
 
   `compacted[]` = The compacted representation of a range in the expansion set.

   `expanded[]` = The expanded array of the compacted representation. */

////////////////////////////////////////////////////////////////////////////////
// Functions

void expand( char compacted[], char expanded[] )
{
	int e, ee; // Element (1st, 2nd)

	/* Number expansion */
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
	/* Upper case expansion */
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
	/* Lower case expansion */
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
}

////////////////////////////////////////////////////////////////////////////////
int main( void )
{
	int c, lastc; // Character, LAST Character
	char compacted[ 4 ] = { NUL, NUL, NUL, NUL }; // COMPACTED buffer
	                                              // (3 chars + terminal null) 
	char expanded[ ALPHA + 1 ]; // EXPANDED buffer
	                            // (max expansion is a, b..., z + terminal null)

	while( ( c = getchar() ) != EOF )
	{
		/* Expand compaction buffer */
		if( ( compacted[ 0 ] >= '0' && compacted[ 0 ] <= compacted[ 2 ] && compacted[ 2 ] <= '9' && compacted[ 1 ] == '-' ) ||
		    ( compacted[ 0 ] >= 'A' && compacted[ 0 ] <= compacted[ 2 ] && compacted[ 2 ] <= 'Z' && compacted[ 1 ] == '-' ) ||
		    ( compacted[ 0 ] >= 'a' && compacted[ 0 ] <= compacted[ 2 ] && compacted[ 2 ] <= 'z' && compacted[ 1 ] == '-' ) )
		{
			expand( compacted, expanded );
			printf( "%s", expanded );
			compacted[ 0 ] = compacted[ 1 ] = compacted[ 2 ] = NUL;
		}

		/* Print & clear unexpanded compaction buffer every newline */
		if( c == '\n' )
		{
			printf( "%s\n", compacted );
			compacted[ 0 ] = compacted[ 1 ] = compacted[ 2 ] = NUL;
		}
		/* Populate compaction buffer */
		else if( compacted[ 0 ] == NUL )
		{
			compacted[ 0 ] = c;
		}
		else if( compacted[ 1 ] == NUL )
		{
			compacted[ 1 ] = c;
		}
		else if( compacted[ 2 ] == NUL )
		{
			compacted[ 2 ] = c;
		}
		/* Else print the buffer tail & shift it by one space to the left */
		else
		{
			printf( "%c", compacted[ 0 ] );
			compacted[ 0 ] = compacted[ 1 ];
			compacted[ 1 ] = compacted[ 2 ];
			compacted[ 2 ] = ( c == '\n' ) ? NUL : c;
		}

		lastc = c;
	}
	if( lastc != '\n' )
	{
		putchar( '\n' ); // Add a terminal newline if necessary
	}

	return 0;
}
