////////////////////////////////////////////////////////////////////////////////
// Comments

// These functions perform specialized string functions I find myself using on a regular basis.

// Be sure to free the memory for the dynamic character array!
// Be sure to free the memory for substring!

// There are serious rounding errors with str2num.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <regex.h>
#include "../rematch/rematch.h"
#include "sstring.h"

////////////////////////////////////////////////////////////////////////////////
// Functions

char* d_s( char* s ) // Dynamic String; String
{
	int c;
	int sz = 0;

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
	int st_ln, e;
	char* t;
	char* tt;

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
	int e;

	for( e = 0; string[ e ]; ++e )
		;

	return e;
}

float str2num( char* numstring )
{
	char num_re[] = "^([1-9][0-9]*)\\.?([0-9]*)$";
	size_t nmatch = 3;
	regmatch_t pmatch[ nmatch ];
	char* s;
	float value = 0.0;
	int e;
	int s_l;

	if( rematch( num_re, numstring, nmatch, pmatch ) )
	{
		/* Integer portion of the float */
		s = substring( numstring, pmatch[ 1 ].rm_so, pmatch[ 1 ].rm_eo - 1 );
		printf( "Integer substring = [%s]\n", s );
		s_l = slength( s );
		for( e = 0; s[ e ] != '\0'; ++e )
			value = value + ( s[ e ] - '0' ) * pow( 10, s_l - ( e + 1 ) );

		/* Decimal portion of the float */
		if( ( pmatch[ 2 ].rm_eo - 1 ) - pmatch[ 2 ].rm_so > 0 )
		{
			s = substring( numstring, pmatch[ 2 ].rm_so, pmatch[ 2 ].rm_eo - 1 );
			printf( "Decimal substring = [%s]\n", s );
			s_l = slength( s );
			for( e = 0; s[ e ] != '\0'; ++e )
				value = value + ( s[ e ] - '0' ) * pow( 10, -( e + 1 ) );
		}
	}
	else
	{
		fprintf( stderr, "Source string does not have a good number format: %s\n", numstring );
		exit( 1 );
	}

	return value;
}
