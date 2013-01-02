#include <stdio.h>
#include <string.h>

int main()
{
	// These two arrays are likely to be adjacent to each other in memory.
	// This is likely to give you funky printf results if you set the array size to 10.
	char array_a[ 11 ] = "0123456789";
	char array_b[ 11 ];

	printf( "array_a (before memcpy) = [%s]\n", array_a );
	printf( "array_b (before memcpy) = [%s]\n", array_b );
	memcpy( array_b, array_a, 10 );
	printf( "array_a (after memcpy) = [%s]\n", array_a );
	printf( "array_b (after memcpy) = [%s]\n", array_b );

	return 0;
}
