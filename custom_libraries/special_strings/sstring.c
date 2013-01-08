////////////////////////////////////////////////////////////////////////////////
// Comments

// These functions perform specialized string functions I find myself using on a regular basis.

// Be sure to free the memory for the dynamic character array!
// Be sure to free the memory for substring!

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>
#include <stdlib.h>
#include "sstring.h"

////////////////////////////////////////////////////////////////////////////////
// Functions

char* d_s( char* s ) // Dynamic String; String
{
	int c; // Character
	int sz = 0; // Size

	/* Dynamically allocates memory for a string input. */
	s = malloc( sizeof( char ) );
	while( ( c = fgetc( stdin ) ) != '\n' && c != EOF )
	{
		s = realloc( s, sizeof( char ) * ++sz );
		*( s + ( sz - 1 ) ) = c;
	}
	*( s + sz ) = '\0';

	return s;
}

char* substring( char* source, int begin, int end )
{
	int st_ln; // String Length
	char* t; // Target
	char* tt;
	int e; // Element

	/* Sanity checks */
	if( begin > end )
	{
		fprintf( stderr, "specprint:substring -- begin substring point is larger than the end point.\n" );
		exit( 1 );
	}

	st_ln = slength( source );
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
	t = malloc( sizeof( char ) * ( end - begin ) );
	tt = t;

	/* Copy the substring */
	for( e = begin; e <= end; ++e )
		*tt++ = source[ e ];
	*tt = '\0';

	return t;
}

int slength( char* string )
{
	int e; // Element

	for( e = 0; string[ e ]; ++e )
		;

	return e;
}
