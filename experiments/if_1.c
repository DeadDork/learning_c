////////////////////////////////////////////////////////////////////////////////
// Comments

// This demonstrates that the function IF (and presumably the other control flow
// functions) evaluate truth as any non-zero value (even negative numbers).

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
int main()
{
	int var;

	printf( "Enter an int: " );
	scanf( "%d", &var );

	if( var )
		printf( "IF\n" );
	else
		printf( "ELSE\n" );

	return 0;
}
