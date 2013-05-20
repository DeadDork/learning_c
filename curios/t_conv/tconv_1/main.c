////////////////////////////////////////////////////////////////////////////////
// Comments

// Converts a temperature value of one scale (e.g. 98.6 F) into the temperature value of another (e.g. 37 C).

// Note that the STDOUT return value is the converted temperature value, and the STDERR is either 'C' (i.e. 67, which refers to 'Celsius') or 'F' (i.e. 70, which refers to 'Fahrenheit'). All other return values are errors.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include "sstring.h"
#include "tempcon.h"

////////////////////////////////////////////////////////////////////////////////
int main( int argc, char * argv[] )
{
	char * temp_string;
	int temp_type;
	float temp;

	/* Get input */
	if( argc == 1 )
	{
		temp_string = d_s( temp_string );
		temp_type = t_extract( temp_string, &temp );
	}
	else
	{
		temp_type = t_extract( argv[ 1 ], &temp );
	}

	printf( "%.1f\n", t_conv( &temp, &temp_type ) );

	free( temp_string );

	return temp_type;
}
