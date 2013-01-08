////////////////////////////////////////////////////////////////////////////////
// Comments

// Tests out the *rematch* library.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include "../dynamic_string/d_s.h"
#include "rematch.h"

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

	return 0;
}
