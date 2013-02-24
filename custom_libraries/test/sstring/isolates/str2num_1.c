////////////////////////////////////////////////////////////////////////////////
// Comments

// Tests out the str2num() function in isolation.

// Works!

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <regex.h>

////////////////////////////////////////////////////////////////////////////////
// Symbolic Constants

#define MAXBUF 1000 // MAXimum BUFfer size

////////////////////////////////////////////////////////////////////////////////
// Function Prototypes

int slength( char *string );
/* Measures the length of a string, in array notation.
 
   `string` = The source string to be measured.

   Returns the length of the string. */

char * substring( char * source, int begin, int end );
/* Slices a substring from a string.
 
   `source` = The source string that the substring will be extracted from.
   `begin` = The start point of the substring in the string, in array notation (e.g. the first element is at position 0).
   `end` = The end point of the substring in the string, in array notiation.

   Returns the pointer to the target substring.

   N.B. DON'T FORGET TO FREE UP THE MEMORY!!! */

double str2num( char *numstring );
/* Converts a string that's a human-readable number into a computer readable number.
 
   *numstring* = the source string that is to be converted into a real number.

   Returns a float of the converted number. */

////////////////////////////////////////////////////////////////////////////////
// Functions

int slength( char * string )
{
	int e; // Element

	/* Get string length */
	for( e = 0; string[ e ]; ++e );

	return e;
}

char * substring( char * source, int begin, int end )
{
	int st_ln, e; // STring LeNgth, Element
	char * t; // Temporary string

	/* Sanity checks */
	if( begin > end )
	{
		fprintf( stderr, "sstring, substring: begin point is after end point.\n" );
		exit( 1 );
	}

	st_ln = slength( source );
	if( begin > st_ln )
	{
		fprintf( stderr, "sstring, substring: begin point is not in string.\n" );
		exit( 1 );
	}
	if( end > st_ln )
	{
		fprintf( stderr, "sstring, substring: end point is not in string.\n" );
		exit( 1 );
	}

	/* Allocate enough memory for the substring */
	t = malloc( sizeof( char ) * ( 1 + ( end - begin ) ) );

	/* Copy the substring */
	for( e = begin; e <= end; ++e )
	{
		t[ e - begin ] = source[ e ];
	}
	t[ e - begin ] = '\0';

	return t;
}

double str2num( char * numstring )
{
	regex_t regex; // REGular EXPression (to be compiled)
	char num_re[] = "^(-?)(0|[1-9][0-9]*)\\.?([0-9]*)$"; // NUMber Regular Expression string
	size_t nmatch = 4; // Number of subexpression MATCHes
	regmatch_t pmatch[ nmatch ]; // number of subexpression PMATCH structs
	int re_err; // Regular Expression ERRor
	char err_msg[ MAXBUF ]; // ERRor MeSsaGe
	int e; // Element
	char * s; // temporary String
	int s_l; // String Length
	double value = 0.0; // return VALUE

	/* Compiles the regex */
	if( ( re_err = regcomp( &regex, num_re, REG_EXTENDED ) ) )
	{
		fprintf( stderr, "Could not compile regex\n" );
		exit( 1 );
	}

	/* Checks string for number-like properties. If it's in the form of a number, it is converted into a number. */
	if( !( re_err = regexec( &regex, numstring, nmatch, pmatch, 0 ) ) )
	{
		/* Integer portion of the float */
		s = substring( numstring, pmatch[ 2 ].rm_so, pmatch[ 2 ].rm_eo - 1 );
		s_l = slength( s );
		for( e = 0; s[ e ] != '\0'; ++e )
		{
			value = value + ( s[ e ] - '0' ) * pow( 10, s_l - ( e + 1 ) );
		}

		/* Decimal portion of the float */
		if( pmatch[ 3 ].rm_eo - pmatch[ 3 ].rm_so > 0 )
		{
			s = substring( numstring, pmatch[ 3 ].rm_so, pmatch[ 3 ].rm_eo - 1 );
			s_l = slength( s );
			for( e = 0; s[ e ] != '\0'; ++e )
			{
				value = value + ( s[ e ] - '0' ) * pow( 10, -( e + 1 ) );
			}
		}

		/* Signage of the float */
		if( pmatch[ 1 ].rm_eo - pmatch[ 1 ].rm_so > 0 )
		{
			value = value * -1;
		}
	}
	else if( re_err == REG_NOMATCH )
	{
		fprintf( stderr, "Source string does not have a good number format: %s\n", numstring );
		exit( 1 );
	}
	else
	{
		regerror( re_err, &regex, err_msg, sizeof( char ) * MAXBUF );
		fprintf( stderr, "Regex match failed: %s\n", err_msg );
		exit( 1 ); 
	}

	free( s );
	regfree( &regex );

	return value;
}

////////////////////////////////////////////////////////////////////////////////
int main()
{
	double num_test = 1234.0;
	double num_a;
	char numstr_a[] = "1234";
	double num_b;
	char numstr_b[] = "1234.1";
	double num_c;
	char numstr_c[] = "1234.11111111111111111111111111111111111";
	double num_d;
	char numstr_d[] = "1234.99999999999999999999999999999999999";
	double num_e;
	char numstr_e[] = "-1234.1";

	printf( "numstr_a = [%s]\n", numstr_a );
	num_a = str2num( numstr_a );
	printf( "\t[%lf] - [%lf] = [%lf]\n", num_a, num_test, num_a - num_test );
	printf( "\tExpected: 0\n" );

	printf( "numstr_b = [%s]\n", numstr_b );
	num_b = str2num( numstr_b );
	printf( "\t[%lf] - [%lf] = [%lf]\n", num_b, num_test, num_b - num_test );
	printf( "\tExpected: 0.1\n" );

	printf( "numstr_c = [%s]\n", numstr_c );
	num_c = str2num( numstr_c );
	printf( "\t[%lf] - [%lf] = [%lf]\n", num_c, num_test, num_c - num_test );
	printf( "\tExpected: 0.11111111111111111111111111111111111\n" );

	printf( "numstr_d = [%s]\n", numstr_d );
	num_d = str2num( numstr_d );
	printf( "\t[%lf] - [%lf] = [%lf]\n", num_d, num_test, num_d - num_test );
	printf( "\tExpected: 0.99999999999999999999999999999999999\n" );

	printf( "numstr_e = [%s]\n", numstr_e );
	num_e = str2num( numstr_e );
	printf( "\t[%lf] - [%lf] = [%lf]\n", num_e, num_test, num_e - num_test );
	printf( "\tExpected: -2468.1\n" );

	return 0;
}
