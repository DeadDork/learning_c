////////////////////////////////////////////////////////////////////////////////
// Comments

// Tests the unary plus operator.

// Conclusion: I have no idea what it does...

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
int main( void )
{
	int i; // Integer

	printf( "set i to 5\n" );
	i = 5;
	printf( "\ti = [%d]\n", i );
	printf( "\t-i = [%d]\n", -i );
	printf( "\t+i = [%d]\n", +i );

	printf( "set i to -i\n" );
	i = -i;
	printf( "\ti = [%d]\n", i );
	printf( "\t-i = [%d]\n", -i );
	printf( "\t+i = [%d]\n", +i );

	printf( "set i to +i\n" );
	i = +i;
	printf( "\ti = [%d]\n", i );
	printf( "\t-i = [%d]\n", -i );
	printf( "\t+i = [%d]\n", +i );

	printf( "Final:\n\ti = [%d]\n", i );

	return 0;
}
