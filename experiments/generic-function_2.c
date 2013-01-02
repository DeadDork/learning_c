// Holy fucking shit. I now get it: you can't copy over one pointer with a second pointer. Use the friggin' heap instead of the stack.
#include <stdio.h>
#include <stdlib.h>
//#include <string.h>

void memcopy( void* a, void* b, int sz );

void memcopy( void* a, void* b, int sz )
{
	char* src = b;
	char* dst = a;

	while( sz-- != 0 )
		*( dst++ ) = *( src++ );
}

void gswap( void* a, void* b, int sz );

void gswap( void* a, void* b, int sz )
{
	char* buf = malloc( sizeof( char ) * sz );

	memcopy( buf, a, sz );
	memcopy( a, b, sz );
	memcopy( b, buf, sz );

	free( buf );
}

int main(int argc, char* argv[] )
{
	int i;

	printf( "Int values of argv[1] = [" );
	for( i = 0; i < 6; ++i )
		printf( "%d, ", argv[ 1 ][ i ] );
	printf( "]\n" );

	printf( "Int values of argv[2] = [" );
	for( i = 0; i < 6; ++i )
		printf( "%d, ", argv[ 2 ][ i ] );
	printf( "]\n" );

	printf( "Before swapping\n\targv[1] = [%s]\n\tPosition of argv[1] = [%p]\n\targv[2] = [%s]\n\tPosition of argv[2] = [%p]\n", argv[ 1 ], &argv[ 1 ][ 0 ], argv[ 2 ], &argv[ 2 ][ 0 ] );
	gswap( argv[ 1 ], argv[ 2 ], ( ( sizeof( argv[ 1 ] ) > sizeof( argv[ 2 ] ) ) ? sizeof( argv[ 1 ] )  : sizeof( argv[ 2 ] ) ) );
	printf( "After swapping\n\targv[1] = [%s]\n\tPosition of argv[1] = [%p]\n\targv[2] = [%s]\n\tPosition of argv[2] = [%p]\n", argv[ 1 ], &argv[ 1 ][ 0 ], argv[ 2 ], &argv[ 2 ][ 0 ] );

	printf( "Int values of argv[1] = [" );
	for( i = 0; i < 6; ++i )
		printf( "%d, ", argv[ 1 ][ i ] );
	printf( "]\n" );

	printf( "Int values of argv[2] = [" );
	for( i = 0; i < 6; ++i )
		printf( "%d, ", argv[ 2 ][ i ] );
	printf( "]\n" );

	return 0;
}
