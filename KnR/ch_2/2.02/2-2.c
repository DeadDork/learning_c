////////////////////////////////////////////////////////////////////////////////
// Comments

// Solution to ex. 2-2.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
// Function Prototypes

int getline_orig( char line[], int maxline );
/* Reads a line from input.
 
   `line[]` = The character array to assign the read line to.

   `maxline` = The maximum length of the array.
   
   Returns the length of the line (N.B. '\n' counts as a character, so "empty" lines are
   not quite empty. Only empy files have 0 length). */

int getline_alt( char s[], int lim );
/* Reads a line from input.
 
   `line[]` = The character array to assign the read line to.

   `maxline` = The maximum length of the array.
   
   Returns the length of the line (N.B. '\n' counts as a character, so "empty" lines are
   not quite empty. Only empy files have 0 length). */

////////////////////////////////////////////////////////////////////////////////
// Functions

int getline_orig( char s[], int lim )
{
	int c, i;

	for( i = 0; i < lim - 1 && ( c = getchar() ) != EOF && c != '\n'; ++i )
	{
		s[ i ] = c;
	}
	if( c == '\n' )
	{
		s[ i ] = c;
		++i;
	}
	s[ i ] ='\0';

	return i;
}

int getline_alt( char s[], int lim )
{
	int c, i, ii;

	for( i = 0; i < lim - 1; ++i )
	{
		if( ( c = getchar() ) == EOF )
		{
			ii = i;
			i = lim - 1;
		}
		else if( c == '\n' )
		{
			ii = i;
			i = lim - 1;
		}
		else
		{
			ii = i;
			s[ ii ] = c;
		}
	}
	if( c == '\n' )
	{
		s[ ii ] = c;
		++ii;
	}
	s[ ii ] ='\0';

	return ii;
}

////////////////////////////////////////////////////////////////////////////////
int main( void )
{
	int maxline = 1000;
	int len;
	char line[ maxline ];

	/*
	while( ( len = getline_orig( line, maxline ) ) > 0 )
	{
		printf( "%s", line );
	}
	*/
	while( ( len = getline_alt( line, maxline ) ) > 0 )
	{
		printf( "%s", line );
	}

	return 0;
}
