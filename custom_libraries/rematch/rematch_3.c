////////////////////////////////////////////////////////////////////////////////
// Comments

// Tests out the *rematch* library.

// Specifically, retrieving substrings from pmatch.

// Works!

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include "sstring.h"
#include "rematch.h"

////////////////////////////////////////////////////////////////////////////////
int main()
{
	size_t nm = 2;
	regmatch_t pm[ nm - 1 ];

	char* s;
	printf( "Enter string: " );
	s = d_s( s );

	char* re;
	printf( "Enter regex with parenthesized subexpression: " );
	re = d_s( re );

	if( rematch( re, s, nm, pm ) )
		printf( "Subexpression = [%s]\n", substring( s, pm[ 1 ].rm_so, pm[ 1 ].rm_eo - 1 ) );
	else
		printf( "Couldn't extract substring.\n" );

	free( s );
	free( re );

	return 0;
}
