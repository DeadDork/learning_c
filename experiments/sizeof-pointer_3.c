////////////////////////////////////////////////////////////////////////////////
// Comments

// Tries out different pointer parameters in sizeof().

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
int main()
{
	char c;
	char *pc = &c;

	printf( "sizeof() of char c = [%ld]\n", sizeof( c ) );
	printf( "sizeof() of char *pc = [%ld]\n", sizeof( pc ) );
	printf( "sizeof() of char = [%ld]\n", sizeof( char ) );
	printf( "sizeof() of char * = [%ld]\n", sizeof( char * ) );
	//printf( "sizeof() of * = [%ld]\n", sizeof( * ) ); // yields error: "expected expression before ')' token"

	return 0;
}
