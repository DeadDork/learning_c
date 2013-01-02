#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap( void* a, void* b, int sz );

void swap( void* a, void* b, int sz )
{
	char* buf = malloc( sizeof( char ) * sz );
	memcpy( buf, a, sz );
	memcpy( a, b, sz );
	memcpy( b, buf, sz );
	free( buf );
}

int main()
{
	int a = 44;
	int b = 5;
	int* a_ptr = &a;
	int* b_ptr = &b;
	printf( "Before swapping\n\ta = [%d]\n\tb = [%d]\n", a, b); swap( a_ptr, b_ptr, sizeof( int ) );
	printf( "After swapping\n\ta = [%d]\n\tb = [%d]\n", a, b);

	return 0;
}
