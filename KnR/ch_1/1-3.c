////////////////////////////////////////////////////////////////////////////////
// Comments

// Solution to exercise 1-3.

// I kind of went nuts on this one.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include "../../custom_libraries/rematch/rematch.h"
#include "../../custom_libraries/special_strings/sstring.h"

////////////////////////////////////////////////////////////////////////////////
// Symbolic constants

#define CELS 'C'
#define FAHR 'F'

////////////////////////////////////////////////////////////////////////////////
// Function prototypes

int t_extract( char *in, float *temp );
/* Checks for correctness and extracts the number & scale type of temperature input string.
 
   *in* = the pointer to the input string. This will be checked for correct form, and will be from which the temperature value & scale type is extracted.
   *temp* = the pointer to the output temperature. This pointer will be assigned the extracted temperature value.

   Returns the value of the type of temperature scale. */

float t_conv( float *temp, int temp_type );
/* Checks the temperature scale (i.e. Celsius or Fahrenheit), and converts the input temperature to the other temperature scale.
 
   *temp* = the temperature variable. 
   temp_type* = the type of temperature scale. */

////////////////////////////////////////////////////////////////////////////////
// Functions

int t_extract( char *in, float *temp )
{
	char re[] = "^([0-9]+\\.?[0-9]*) *([cCfF])$";
	size_t nmatch = 3;
	regmatch_t pmatch[ nmatch ];
	char *temp_type;
	int value;

	if( rematch( re, in, nmatch, pmatch ) )
	{
		*temp = ( float )str2num( substring( in, pmatch[ 1 ].rm_so, pmatch[ 1 ].rm_eo - 1 ) );

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

	return value;
}

float t_conv( float *temp, int temp_type )
{
	float value;

	if( temp_type == CELS )
		value = ( *temp * ( 9.0 / 5.0 ) ) + 32.0;

	if( temp_type == FAHR )
		value = ( 5.0 / 9.0 ) * ( *temp - 32.0 );

	return value;

	// I was in an obfuscating mood, and came up with an annoying alternative return function:
	// return ( temp_type == FAHR ? ( ( 9 / 5 ) * temp ) + 32 : ( temp_type == CELS ? ( 5 / 9 ) * ( temp - 32 ) ) );
}

////////////////////////////////////////////////////////////////////////////////
int main()
{
	char *temp_string;
	int temp_type;
	float temp;

	printf( "Enter the temperature to convert, with the scale type unit (e.g. '104.3F' or '42.9C'): " );
	temp_string = d_s( temp_string );

	temp_type = t_extract( temp_string, &temp );

	printf( "The converted temperature = %.1f %c\n", t_conv( &temp, temp_type ), temp_type );

	return 0;
}
