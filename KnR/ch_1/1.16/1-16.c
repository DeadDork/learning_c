////////////////////////////////////////////////////////////////////////////////
// Comments

// Solution to ex. 1-16.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
// Symbolic Constants

#define MAXLINE 1000

////////////////////////////////////////////////////////////////////////////////
// Function Prototypes

int getl( char line[], int maxlength );
/* Gets longest line.
   
   *line* = character array that is assigned the longest line from STDIN.
   *maxlength* = the maximum length of the line.

   Returns the length of the longest line. */

void copy( char source[], char target[] );
/* Copies a source character array to a target character array.
 
   *source* = source character arrla you want to copy from.
   *target* = target character array you want to copy to. */

////////////////////////////////////////////////////////////////////////////////
// Functions

int getl( char line[], int maxlength )
{
	int c, e;

	for( e = 0; ( c = getchar() ) != EOF && c != '\n'; ++e )
	{
		if( e < maxlength - 1 )
		{
			line[ e ] = c;
		}
	}

	return e;
}

void copy( char source[], char target[] )
{
	int i, j;

	i = j = 0;
	while ( ( target[ i++ ] = source[ j++ ] ) != '\0' );
	// while( ( *target++ = *source++ ) != '\0' ); // This is much better, but I'm "not" there yet.
}

////////////////////////////////////////////////////////////////////////////////
int main()
{
	int len;
	int max = 0;
	char line[ MAXLINE ];
	char longest[ MAXLINE ];

	while( ( len = getl( line, MAXLINE ) ) > 0 )
	{
		if( len > max )
		{
			max = len;
			copy( line, longest );
		}
	}
	
	if( max > 0 )
	{
		printf( "Longest:\n\tLength = [%d]\n\tFirst %d chars of string = [%s]\n", max, MAXLINE - 1, longest );
	}

	return 0;
}
