#include <stdio.h>
#include <stdlib.h>

int main()
{
	char* d_s; // Dynamic character String array.
	int c;
	int sz = 0;

	d_s = malloc( sizeof( char ) );

	while( ( c = fgetc( stdin ) ) != '\n' )
	{
		d_s = realloc( d_s, sizeof( char ) * ++sz );
		*( d_s + ( sz - 1 ) ) = c;
	}
	*( d_s + sz ) = '\0';

	printf( "Dynamic string = [%s]\n", d_s );

	free( d_s );

	return 0;
}
