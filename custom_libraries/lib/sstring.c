////////////////////////////////////////////////////////////////////////////////
// Comments

// These functions perform specialized string functions I find myself using on a regular basis.

/* DON'T FORGET TO FREE:
 * d_s
 * substring
 * sub */

// There are serious rounding errors with str2num. Using the DOUBLE type solves them to a large degree, but this should be noted.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <regex.h>
#include "sstring.h"

////////////////////////////////////////////////////////////////////////////////
// Functions

char * d_s( char * s )
{
	int c; // Character
	int mult = 1; // MULTiple
	int sz = 0; // SiZe

	/* Dynamically allocates memory for a string input. */
	s = malloc( sizeof( char ) * BUFSZ );
	while( ( c = fgetc( stdin ) ) != '\n' && c != EOF )
	{
		if( ++sz > ( mult * BUFSZ ) )
		{
			s = realloc( s, sizeof( char ) * BUFSZ * ++mult );
		}
		s[ sz - 1 ] = c;
	}
	s[ sz ] = '\0';

	return s;
}

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

char * sub( char * source, char * substitute, int start, int stop )
{
	char * begin, * end, * tmp, * ttmp, * trgt; // BEGIN string, END string, TeMPorary string, TeMPorary string 2, TaRgEt string

	/* Unless the substitution is at the head of the source string, assigns to `begin` the head of the string */
	if( start > 0 )
	{
		begin = substring( source, 0, start - 1);
	}

	/* Unless the substitution is at the tail of the source string, assigns to `end` the tail of the string */
	if( stop < slength( source ) )
	{
		end = substring( source, stop + 1, slength( source ) );
	}

	trgt = malloc( sizeof( char ) * ( slength( begin ) + slength( substitute ) + slength( end ) ) );

	/* Performs the substitution */
	ttmp = trgt;

	/* Head */
	tmp = begin;
	while( *tmp != '\0' )
	{
		*ttmp++ = *tmp++;
	}

	/* Body */
	tmp = substitute;
	while( *tmp != '\0' )
	{
		*ttmp++ = *tmp++;
	}

	/* Tail */
	tmp = end;
	while( *tmp != '\0' )
	{
		*ttmp++ = *tmp++;
	}
	*ttmp = '\0';

	free( begin );
	free( end );

	return trgt;
}
