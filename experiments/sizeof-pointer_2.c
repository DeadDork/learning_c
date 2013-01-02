#include <stdio.h>

void a_sizeof( char s[] );
void a_sizeof( char s[] )
{
	int i;

	printf( "sizeof(s[]) = [%ld]\n", sizeof( s ) );

	printf( "s[] = [" );
	for( i = 0; s[ i ] != '\0'; ++i )
		printf( "%c", s[ i ] );
	printf( "]\n" );
}

void p_sizeof( char* s );
void p_sizeof( char* s )
{
	int i;

	printf( "sizeof(*s) = [%ld]\n", sizeof( s ) );

	printf( "*s = [" );
	for( i = 0; s[ i ] != '\0'; ++i )
		printf( "%c", s[ i ] );
	printf( "]\n" );
}

int main()
{
	char s[] = "hello, world";

	printf( "sizeof(s) = [%ld]\n", sizeof( s ) );
	a_sizeof( s );
	p_sizeof( s );

	return 0;
}
