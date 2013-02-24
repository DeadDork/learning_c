////////////////////////////////////////////////////////////////////////////////
// Comments

// This tests sub() function in sstring.h

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
	char * re, * src, * sbst, * trgt; // Regular Expression string, SouRCe string, SuBSTitution string, TaRGT string
	size_t nmatch = 1;
	regmatch_t pmatch[ nmatch ];

	printf( "Enter source string: " );
	src = d_s( src );

	printf( "Enter regex string: " );
	re = d_s( re );

	printf( "Enter regex sbststitution: " );
	sbst = d_s( sbst );

	if( rematch( src, re, nmatch, pmatch ) )
	{
		printf( "Source string = [%s]\n", src );
		trgt = sub( src, sbst, pmatch[ 0 ].rm_so, pmatch[ 0 ].rm_eo - 1 );
		printf( "Target string = [%s]\n", trgt );
	}
	else
	{
		fprintf( stderr, "Failed to match.\n" );
	}

	free( src );
	free( re );
	free( sbst );
	free( trgt );

	return 0;
}
