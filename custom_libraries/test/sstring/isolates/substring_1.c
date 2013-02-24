////////////////////////////////////////////////////////////////////////////////
// Comments

// Tests the slength & substring() functions in isolation.

// Works!

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>
#include <stdlib.h>

////////////////////////////////////////////////////////////////////////////////
// Function Prototypes

int slength( char * string );
/* Measures the length of a string.
 
   `string` = Points to the string that will be measured.

   Returns the length of the string. */

char * substring( char * source, int begin, int end );
/* Returns a substring of a given string.
 
   `source` = The original source that will be sliced.
   `begin` = The begin point of the slice.
   `end` = The end point of the slice.

   Returns the location in the heap where the substring resides. */

////////////////////////////////////////////////////////////////////////////////
// Functions

int slength( char * string )
{
	int e;

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

////////////////////////////////////////////////////////////////////////////////
int main()
{
	char s[] = "Hello, my darling wife.";
	char * ss;

	printf( "string = [%s]\n", s );

	//ss = substring( s, 4, 0 ); // Should return an error.
	//ss = substring( s, 100, 104 ); // Should return an error.
	//ss = substring( s, 0, 400 ); // Should return an error.
	//ss = substring( s, 0, 0 ); // Should return 'H'.
	ss = substring( s, 18, 21 ); // Should return "wife".
	printf( "substring = [%s]\n", ss );

	free( ss );

	return 0;
}
