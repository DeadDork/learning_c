#include <stdio.h>
#include <sys/types.h>
#include <math.h>

#define TYPE int

TYPE lengthof( char* i );
TYPE lengthof( char* i )
{
	TYPE j;

	for( j = 0; ( j < ( pow( 2, sizeof( TYPE ) ) ) ) && ( i[ j ] != '\0' ); ++j )
		;

	return j;
}

TYPE psize_of( char* s );
TYPE psize_of( char* s )
{
	int i;

	printf( "for loop printf(s) = [" );
	for( i = 0; s[ i ] != '\0'; ++i )
		printf( "%c", s[ i ] );
	printf( "]\n" );

	printf( "lengthof string = [%d]\n", lengthof( s ) );
	printf( "sizeof string = [%ld]\n", sizeof( s ) );

	return sizeof( s );
}

TYPE asize_of( char s[] );
TYPE asize_of( char s[] )
{
	int i;

	printf( "for loop printf(s) = [" );
	for( i = 0; s[ i ] != '\0'; ++i )
		printf( "%c", s[ i ] );
	printf( "]\n" );

	printf( "lengthof string = [%d]\n", lengthof( s ) );
	printf( "sizeof string = [%ld]\n", sizeof( s ) );

	return sizeof( s );
}

int main()
{
	char s[] = "hello, world";
	int strln;

	printf( "s = [%s]\n\n", s );

	strln = sizeof( s );
	printf( "sizeof(s) = [%d]\n\n", strln );

	strln = psize_of( s );
	printf( "psize_of(s) = [%d]\n\n", strln );

	strln = asize_of( s );
	printf( "asize_of(s) = [%d]\n\n", strln );

	return 0;
}
