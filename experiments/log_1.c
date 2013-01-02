#include <stdio.h>
#include <math.h>

int main()
{
	int x = 320000;
	char s[ 100 ];
	int i;

	sprintf( s, "%.5f", log( x ) / log( 2 ) );

	printf( "x = [" );
	for( i = 0; s[ i ] != '.'; ++i )
		printf( "%c", s[ i ] );
	printf( "]\n" );

	return 0;
}
