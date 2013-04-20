////////////////////////////////////////////////////////////////////////////////
// Comments

// Solution to ex. 3-3.

// Print input to output. If the input is in the form of compact expansion set,
// then expand the set appropriately (e.g. '-b-f-7-9-S-U-0-2F-Jh-l-' will expand
// to '-bcdef-789-STU-012FGHIJhijkl-').

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

   `expanded[]` = The full range of the expansion set represented by
   'compacted[]'. */

////////////////////////////////////////////////////////////////////////////////
// Functions

void expand( char compacted[], char expanded[] )
{
	int e, ee; // Element (1st, 2nd)

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
}

////////////////////////////////////////////////////////////////////////////////
int main( void )
{
	int c, lastc; // Character, LAST Character
	char triplec[ 4 ] = { NUL, NUL, NUL, NUL }; // triple Character string + a terminal null
	char expanded[ ALPHA + 1 ]; // EXPANDED compacted string + a terminal null

	while( ( c = getchar() ) != EOF )
	{
		/* If triple is a compact expansion set */
		if( ( triplec[ 0 ] >= '0' && triplec[ 0 ] <= triplec[ 2 ] && triplec[ 2 ] <= '9' && triplec[ 1 ] == '-' ) ||
		    ( triplec[ 0 ] >= 'A' && triplec[ 0 ] <= triplec[ 2 ] && triplec[ 2 ] <= 'Z' && triplec[ 1 ] == '-' ) ||
		    ( triplec[ 0 ] >= 'a' && triplec[ 0 ] <= triplec[ 2 ] && triplec[ 2 ] <= 'z' && triplec[ 1 ] == '-' ) )
		{
			expand( triplec, expanded );
			printf( "%s", expanded );
			triplec[ 0 ] = triplec[ 1 ] = triplec[ 2 ] = NUL;
		}

		if( c != '\n' ) // Keeps '\n' from being assigned to the triple
		{
			/* Populates triple */
			if( triplec[ 0 ] == NUL || triplec[ 1 ] == NUL || triplec[ 2 ] == NUL )
			{
				if( triplec[ 0 ] == NUL )
				{
					triplec[ 0 ] = c;
				}
				else if( triplec[ 1 ] == NUL )
				{
					triplec[ 1 ] = c;
				}
				else if( triplec[ 2 ] == NUL )
				{
					triplec[ 2 ] = c;
				}
			}
			/* Print the tail character if triple is full (by extension, also not expandable) */
			else
			{
				printf( "%c", triplec[ 0 ] );
				triplec[ 0 ] = triplec[ 1 ];
				triplec[ 1 ] = triplec[ 2 ];
				triplec[ 2 ] = c;
			}
		}
		/* If c = '\n' */
		else
		{
			printf( "%s\n", triplec );
			triplec[ 0 ] = triplec[ 1 ] = triplec[ 2 ] = NUL;
		}

		lastc = c; // Assign c to lastc to know whether to print a terminal newline
	}
	if( lastc != '\n' )
	{
		putchar( '\n' );
	}

	return 0;
}
