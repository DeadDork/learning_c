////////////////////////////////////////////////////////////////////////////////
// Comments

// Tests out the *rematch* library.

// In particular, this attempts to work out why I can't get this verkakt library to work.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include "sstring.h"

////////////////////////////////////////////////////////////////////////////////
// Symbolic Constants

#define MATCH 1
#define NOMATCH 0

////////////////////////////////////////////////////////////////////////////////
// Function Prototypes

int rematch( char* rex, char* string, size_t nmatch, regmatch_t* pmatch );

////////////////////////////////////////////////////////////////////////////////
// Functions

int rematch( char* re, char* string, size_t nmatch, regmatch_t* pmatch )
{
	int re_err;
	regex_t regex;
	int value;

	if( ( re_err = regcomp( &regex, re, REG_EXTENDED ) ) )
	{
		fprintf( stderr, "Could not compile regex\n" );
		exit( 1 );
	}

	if( !( re_err = regexec( &regex, string, nmatch, pmatch, 0 ) ) )
		value = MATCH;
	else if( re_err == REG_NOMATCH )
		value = NOMATCH;
	else
	{
		regerror( re_err, &regex, string, sizeof( string ) );
		fprintf( stderr, "Regex match failed: %s\n", string );
		exit( 1 ); 
	}

	return value;
}

////////////////////////////////////////////////////////////////////////////////
int main()
{
	size_t nm = 2;
	regmatch_t pm[ 2 ];

	char* s;
	printf( "Enter string: " );
	s = d_s( s );

	char* re;
	printf( "Enter regex: " );
	re = d_s( re );

	if( rematch( re, s, nm, pm ) )
		puts( "Match!" );
	else
		puts( "No match..." );

	free( s );
	free( re );

	return 0;
}
