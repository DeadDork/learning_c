#include <stdio.h>

int main( int count, char *argv[] )
{
	FILE *pf = fopen( argv[ 1 ], "r" );
	int c;

	while ( ( c = fgetc( pf ) ) != EOF )
		( c == '\n' ) ? printf( "%c", c ) : printf( "[%c]", c );

	return 0;
}
