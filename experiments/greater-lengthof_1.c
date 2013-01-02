////////////////////////////////////////////////////////////////////////////////
// Comments

// Tests the functin greater_lengthof, which returns the length of the longer of two strings.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
// Function prototypes

int greater_lengthof( char* a, char* b );

////////////////////////////////////////////////////////////////////////////////
// Functions

int greater_lengthof( char* a, char* b )
{
	int i, j;

	for( i = 0; *( a + i ) != '\0'; ++i )
		;
	++i;
	for( j = 0; *( b + j ) != '\0'; ++j )
		;
	++j;

	return ( i > j) ? i : j;
}

////////////////////////////////////////////////////////////////////////////////
int main()
{
	char a[] = "0123456789";
	char b[] = "01234";

	printf( "a:\n\tString = [%s]\n\tsizeof() = [%ld]\n", a, sizeof( a ) );
	printf( "b:\n\tString = [%s]\n\tsizeof() = [%ld]\n", b, sizeof( b ) );
	printf( "Greater length = [%d]\n", greater_lengthof( a, b ) );

	return 0;
}
