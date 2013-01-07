////////////////////////////////////////////////////////////////////////////////
// Comments

// This library lets me use regex.h effectively and easily.

////////////////////////////////////////////////////////////////////////////////
// Libraries
#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include "rematch.h"

////////////////////////////////////////////////////////////////////////////////
// Symbolic Constants

#define MATCH 1
#define NOMATCH 0

////////////////////////////////////////////////////////////////////////////////
//int rematch( char* rex, char* string, int nmatch, void* pmatch )
int rematch( char* re, char* string )
{
	int value;
	int re_err;
	regex_t regex;
	size_t nmatch = 2;
	regmatch_t pmatch[ 2 ];

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
