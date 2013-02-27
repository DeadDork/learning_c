////////////////////////////////////////////////////////////////////////////////
// Comments

// Tests out the sub() function in isolation.

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

char * sub( char * source, char * substitute, int start, int stop );
/* Substitutes the substring from *start* to *stop* in string *source* with string *substitute*.
   
   *source* = the source string that will have a substring substituted within.
   *substitute* = the string that will substitute the substring within source.
   *start* = the array element in *source* corresponding to the first character of the substring to be substituted.
   *stop* = the array element in *source* corresponding to the first character AFTER the last character of the substring to be substituted.

   Returns the pointer of the new string.

   N.B. DON'T FORGET TO FREE UP THE MEMORY!!! */

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

char * sub( char * source, char * substitute, int start, int stop )
{
	char * begin, * end, * tmp, * ttmp, * trgt; // BEGIN string, END string, TeMPorary string, TeMPorary string 2, TaRgEt string

	// Unless the substitution is at the head of the source string, assigns to `begin` the head of the string
	if( start > 0 )
	{
		begin = substring( source, 0, start - 1);
	}

	// Unless the substitution is at the tail of the source string, assigns to `end` the tail of the string
	if( stop < slength( source ) )
	{
		end = substring( source, stop + 1, slength( source ) );
	}

	trgt = malloc( sizeof( char ) * ( slength( begin ) + slength( substitute ) + slength( end ) ) );

	/* Performs the substitution */

	ttmp = trgt;

	// Overwrites the head
	tmp = begin;
	while( *tmp != '\0' )
	{
		*ttmp++ = *tmp++;
	}

	// Overwrites the body
	tmp = substitute;
	while( *tmp != '\0' )
	{
		*ttmp++ = *tmp++;
	}

	// Overwrites the tail
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

////////////////////////////////////////////////////////////////////////////////
int main()
{
	char s[] = "abbbc";
	char * ss;

	printf( "Before:\n\ts = [%s]\n", s );

	ss = sub( s, "lladin ", 1, 3 );
	printf( "After:\n\ts = [%s]\n", ss );

	free( ss );

	/*
	// XXX I don't understand why this doesn't work... XXX
	// I read over K & R 5.3. It's because of the principle difference between arrays and pointers: arrays are not variables, while pointers are.

	char s[] = "abbbc";

	printf( "Before:\n\ts = [%s]\n", s );

	s = sub( s, "lladin ", 1, 3 );
	printf( "After:\n\ts = [%s]\n", s );

	free( ss );
	*/

	return 0;
}
