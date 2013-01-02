////////////////////////////////////////////////////////////////////////////////
// Comments

// Converts a string that's in the form of an integer (e.g. "1234") into an actual integer.

// A return value of 1 means that one of the string values did not have an ascii value between '0' and '9'.

// A return value of 2 means that the string value of the left most array element did not have an ascii value between '1' and '9'.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/////////////////////////////////////////////////////////////////////////////////
// Function prototypes

int length_of( char* x );

int num_con( char s[] );

/////////////////////////////////////////////////////////////////////////////////
// Functions

int length_of( char s[] )
{
	int i;

	for( i = 0; s[ i ] != '\0'; ++i )
		;

	return i;
}

int num_con( char s[] )
{
	int i;
	int l = length_of( s );
	int ll = l;
	int num = 0;

	if( s[ 0 ] - '0' >= 1 && s[ 0 ] - '0' <= 9 )
	{
		for( i = 0; i < l; ++i )
		{
			if( s[ i ] - '0' >= 0 && s[ 0 ] - '0' <= 9 )
				num = num + ( s[ i ] - '0' ) * pow( 10, --ll );
			else
				exit( 1 );
		}
	}
	else
		exit( 2 );

	return num;
}

/////////////////////////////////////////////////////////////////////////////////
int main()
{
	char s[] = "1234567890";
	int x = num_con( s );

	printf( "s = [%s]\n", s );
	printf( "x = [%d]\n", x );
	printf( "x-5 = [%d]\n", x - 5 );

	return 0;
}
