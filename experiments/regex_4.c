////////////////////////////////////////////////////////////////////////////////
// Comments

// This plays further with the regex library.

// Returns match values.

////////////////////////////////////////////////////////////////////////////////
// Libraries

//#include <sys/types.h>
#include <stdlib.h>
#include <regex.h>
#include <stdio.h>
#include "../custom_libraries/dynamic_string/d_s.h"

////////////////////////////////////////////////////////////////////////////////
// Function prototypes

// Offset Printer -- prints a substring from the begin point to the end point in a string.
void o_printer( char* string, int begin, int end );

////////////////////////////////////////////////////////////////////////////////
// Functions

void o_printer( char* string, int begin, int end )
{
	int i;

	for( i = begin; i <= end; ++i )
		printf( "%c", string[ i ] );
	printf( "\n" );
}

////////////////////////////////////////////////////////////////////////////////
int main( void )
{
	regex_t regex;
	char* re;
	char* s;
	int re_err;
	size_t nmatch = 2;
	regmatch_t pmatch[ 2 ];

	printf( "Enter a Regular Expression sequence: " );
	re = d_s( re );

	printf( "Enter a test string to check the regex against: " );
	s = d_s( s );

	if( ( re_err = regcomp( &regex, re, REG_EXTENDED ) ) )
	{
		fprintf( stderr, "Could not compile regex\n" );
		exit( 1 );
	}

	if( !( re_err = regexec( &regex, s, nmatch, pmatch, 0 ) ) )
	{
		puts( "Match" );
		o_printer( s, pmatch[ 1 ].rm_so, pmatch[ 1 ].rm_eo - 1 );
	}
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

	// Always free heap pointers!
	free( re );
	free( s );

	return 0;
}
