////////////////////////////////////////////////////////////////////////////////
// Comments

// Tests whether a string can be tested in a conditional statement.

// Apparently you can't compare strings in C this easily.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
int main( void )
{
	char s[] = "hello"; // String
	char ss[] = "goodbye"; // second String

	if( s == "hello" )
	{
		printf( "[%s] == 'hello'\n", s );
	}
	if( ss == "hello" )
	{
		printf( "[%s] == 'hello'\n", ss );
	}
	if( s == "goodbye" )
	{
		printf( "[%s] == 'goodbye'\n", s );
	}
	if( ss == "goodbye" )
	{
		printf( "[%s] == 'goodbye'\n", ss );
	}

	return 0;
}
