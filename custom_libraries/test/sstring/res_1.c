////////////////////////////////////////////////////////////////////////////////
// Comments

// This tests `res` in sstring.h

// Works!

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include "rematch.h"
#include "sstring.h"

////////////////////////////////////////////////////////////////////////////////
int main()
{
	char *re, *src, *sub, *trgt;
	size_t nmatch = 1;
	regmatch_t pmatch[ nmatch ];

	printf( "Enter source string: " );
	src = d_s( src );

	printf( "Enter regex: " );
	re = d_s( re );

	printf( "Enter regex substitution: " );
	sub = d_s( sub );

	if( rematch( src, re, nmatch, pmatch ) )
	{
		printf( "Source string = [%s]\n", src );
		trgt = res( src, sub, pmatch[ 0 ].rm_so, pmatch[ 0 ].rm_eo );
		printf( "Target string = [%s]\n", trgt );
	}
	else
	{
		fprintf( stderr, "Failed to match.\n" );
	}

	return 0;
}
