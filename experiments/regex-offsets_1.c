////////////////////////////////////////////////////////////////////////////////
// Comments

// Prints out the pmatch offset values from rematch.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stddef.h>
#include <stdio.h>
#include <regex.h>
#include "rematch.h"
#include "sstring.h"

////////////////////////////////////////////////////////////////////////////////
int main()
{
	char *src, *re;
	size_t nmatch = 1;
	regmatch_t pmatch[ nmatch ];

	printf( "Enter the source string: " );
	src = d_s( src );

	printf( "Enter the regular expression: " );
	re = d_s( re );

	if( rematch( src, re, nmatch, pmatch ) )
	{
		printf( "rm_so = [%d], rm_eo = [%d]\n", ( int )pmatch[ 0 ].rm_so, ( int )pmatch[ 0 ].rm_eo );
	}
	else
	{
		fprintf( stderr, "No match:\n\tsource string = [%s]\n\tregex = [%s]\n", src, re );
	}

	return 0;
}
