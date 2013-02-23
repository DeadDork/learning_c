////////////////////////////////////////////////////////////////////////////////
// Comments

// This library lets me use regex.h effectively and easily.

// I researched regfree(). Indeed, ALWAYS free allocated memory.

////////////////////////////////////////////////////////////////////////////////
// Libraries
#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include "rematch.h"

////////////////////////////////////////////////////////////////////////////////
// Function

int rematch( char * string, char * re, size_t nmatch, regmatch_t * pmatch )
{
	int re_err;
	char err_msg[ MAXBUF ];
	regex_t regex;
	int value;

	/* Compiles the regex */
	if( ( re_err = regcomp( &regex, re, REG_EXTENDED ) ) )
	{
		fprintf( stderr, "Could not compile regex\n" );
		exit( 1 );
	}

	/* Matches the regex to string */
	if( !( re_err = regexec( &regex, string, nmatch, pmatch, 0 ) ) )
	{
		value = MATCH;
	}
	else if( re_err == REG_NOMATCH )
	{
		value = NOMATCH;
	}
	else
	{
		regerror( re_err, &regex, err_msg, sizeof( char ) * MAXBUF );
		fprintf( stderr, "Regex match failed: %s\n", err_msg );
		exit( 1 ); 
	}

	regfree( &regex );

	return value;
}
