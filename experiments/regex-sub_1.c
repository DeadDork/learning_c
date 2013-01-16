////////////////////////////////////////////////////////////////////////////////
// Comments

// This tests using `rematch` to replace regex matches.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include "rematch.h"
#include "sstring.h"

////////////////////////////////////////////////////////////////////////////////
// Function Prototypes

char *substitute( char *source, char *substitute,  int start, int stop );

////////////////////////////////////////////////////////////////////////////////
// Functions

char *substitute( char *source, char *substitute, int start, int stop )
{
	char *begin, *end, *tmp, *ttmp, *trgt;

	if( start > 0 )
	{
		begin = substring( source, 0, start - 1);
	}

	if( stop < slength( source ) )
	{
		end = substring( source, stop, slength( source ) );
	}

	trgt = realloc( source, sizeof( char ) * ( slength( begin ) + slength( substitute ) + slength( end ) ) );
	ttmp = trgt;

	tmp = begin;
	while( *tmp != '\0' )
	{
		*ttmp++ = *tmp++;
	}

	tmp = substitute;
	while( *tmp != '\0' )
	{
		*ttmp++ = *tmp++;
	}

	tmp = end;
	while( *tmp != '\0' )
	{
		*ttmp++ = *tmp++;
	}
	*ttmp = '\0';

	return trgt;
}

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
		printf( "Old source string = [%s]\n", src );
		trgt = substitute( src, sub, pmatch[ 0 ].rm_so, pmatch[ 0 ].rm_eo );
		printf( "New source string = [%s]\n", trgt );
	}
	else
	{
		fprintf( stderr, "Failed to match.\n" );
	}

	return 0;
}
