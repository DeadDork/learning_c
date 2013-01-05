////////////////////////////////////////////////////////////////////////////////
// Comments

// This plays further with the regex library.

// Still only matches.

// What makes it unique is the addition of the dynamic string custom library.

////////////////////////////////////////////////////////////////////////////////
// Libraries

//#include <sys/types.h>
#include <stdlib.h>
#include <regex.h>
#include <stdio.h>
#include "../custom_libraries/dynamic_string/d_s.h"

////////////////////////////////////////////////////////////////////////////////
int main( void )
{
	regex_t regex;
	char* re;
	char* s;
	int re_err;

	printf( "Enter a Regular Expression sequence: " );
	re = d_s( re );

	printf( "Enter a test string to check the regex against: " );
	s = d_s( s );

	// Compile regular expression. 
	if( ( re_err = regcomp( &regex, re, 0 ) ) )
	{
		fprintf( stderr, "Could not compile regex\n" );
		exit( 1 );
	}

	// Execute regular expression.
	if( !( re_err = regexec( &regex, s, 0, NULL, 0 ) ) )
		puts( "Match" );
	else if( re_err == REG_NOMATCH )
		puts( "No match" );
	else
	{
		regerror( re_err, &regex, s, sizeof( s ) );
		fprintf( stderr, "Regex match failed: %s\n", s );
		exit( 2 );
	}

	// Free compiled regular expression if you want to use the regex_t again.
	regfree( &regex );

	return 0;
}
