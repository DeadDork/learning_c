////////////////////////////////////////////////////////////////////////////////
// Comments

// Functions file for temperature conversion program t_conv.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include "rematch.h"
#include "sstring.h"
#include "tempcon.h"

////////////////////////////////////////////////////////////////////////////////
// Functions

int t_extract( char * in, float * temp )
{
	char re[] = "^(-?[0-9]+\\.?[0-9]*) *([cCfF])$";
	size_t nmatch = 3;
	regmatch_t pmatch[ nmatch ];
	char * temp_type, * temp_val;
	int value;

	if( rematch( in, re, nmatch, pmatch ) )
	{
		temp_val = substring( in, pmatch[ 1 ].rm_so, pmatch[ 1 ].rm_eo - 1 ); // In order to free up at the end.
		*temp = ( float )str2num( temp_val );

		temp_type = substring( in, pmatch[ 2 ].rm_so, pmatch[ 2 ].rm_eo - 1 );
		if( *temp_type == 'c' || *temp_type == 'C' )
			value = CELS;
		if( *temp_type == 'f' || *temp_type == 'F' )
			value = FAHR;
	}
	else
	{
		fprintf( stderr, "t_extract: Bad temperature entry.\n" );
		exit( 1 );
	}

	free( temp_type );
	free( temp_val );

	return value;
}

float t_conv( float * temp, int * temp_type )
{
	float value;

	if( *temp_type == CELS )
	{
		value = ( *temp * ( 9.0 / 5.0 ) ) + 32.0;
		*temp_type = FAHR;
	}
	else if( *temp_type == FAHR )
	{
		value = ( 5.0 / 9.0 ) * ( *temp - 32.0 );
		*temp_type = CELS;
	}

	return value;
}
