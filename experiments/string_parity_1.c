////////////////////////////////////////////////////////////////////////////////
// Comments

// Determines whether the length of an arbitrarily long string (0 - HARDWARE MAX characters) is even or odd.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../custom_libraries/dynamic_string/d_s.h"

////////////////////////////////////////////////////////////////////////////////
// Symbolic constants

#define odd 1
#define even 2

////////////////////////////////////////////////////////////////////////////////
// Function prototypes

// Returns the number of letters in a string.
int ltr_cnt( char* s );

// Checks an integer's parity.
int parity( int i );

////////////////////////////////////////////////////////////////////////////////
// Functions

int ltr_cnt( char* s )
{
	int i;

	for( i = 0; s[ i ] != '\0'; ++i )
		;

	return i;
}

int parity( int i )
{
	int value;

	if( i == 1 || fmod( i, 2 ) > 0 )
		value = odd;

	else if( i == 0 || fmod( i, 2 ) == 0 )
		value = even;

	return value;
}

////////////////////////////////////////////////////////////////////////////////
int main()
{
	char* str;
	printf( "Enter any string: " ); str = d_s( str );
	int par = parity( ltr_cnt( str ) );

	if( par == even )
		printf( "The length of s is EVEN.\n" );
	else if( par == odd )
		printf( "The length of s is ODD.\n" );

	free( str );

	return 0;
}
