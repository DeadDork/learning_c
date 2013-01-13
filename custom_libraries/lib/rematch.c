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
// Function

int rematch( char* re, char* string, size_t nmatch, regmatch_t* pmatch )
{
	int re_err;
	regex_t regex;
	int value;

	/* Tries to compile the regex */
	if( ( re_err = regcomp( &regex, re, REG_EXTENDED ) ) )
	{
		fprintf( stderr, "Could not compile regex\n" );
		exit( 1 );
	}

	/* Tries to match the regex */
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
		regerror( re_err, &regex, string, sizeof( string ) );
		fprintf( stderr, "Regex match failed: %s\n", string );
		exit( 1 ); 
	}

	regfree( &regex ); // I honestly don't know if this is necessary. I'll have to investigate the regex library to see if this goes into the heap, et al.

	return value;
}
