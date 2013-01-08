////////////////////////////////////////////////////////////////////////////////
// Comments

// These functions perform printing functions I find myself reusing on a regular basis.

// Be sure to free the memory for substring.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>
#include <stdlib.h>

////////////////////////////////////////////////////////////////////////////////
// Functions

char* substring( char* source, int begin, int end )
{
	int cnt;
	int st_ln;
	char* s = source;
	char* target;
	char* t;

	/* Sanity checks */
	if( begin > end )
	{
		fprintf( stderr, "specprint:substring -- begin substring point is larger than the end point.\n" );
		exit( 1 );
	}

	for( st_ln = 0; source[ st_ln ] != '\0'; ++st_ln )
		;
	if( begin > st_ln )
	{
		fprintf( stderr, "specprint:substring -- begin substring point is larger than the length of the string.\n" );
		exit( 1 );
	}
	if( end > st_ln )
	{
		fprintf( stderr, "specprint:substring -- end substring point is larger than the length of the string.\n" );
		exit( 1 );
	}

	/* Allocate enough memory for the substring */
	target = malloc( sizeof( char ) * ( end - begin ) );
	t = target;

	/* Copy over the substring */
	for( cnt = begin; cnt <= end; ++cnt )
		*t++ = s[ cnt ];
	*t = '\0';

	return target;
}
