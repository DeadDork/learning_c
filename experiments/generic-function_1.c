////////////////////////////////////////////////////////////////////////////////
// Comments

// Tests generic funtions in C.

// Generic functions are tricky! You have to use void pointers, so if you want to do anything to the data (as opposed to the address), you have to create variables of a particular kind anyway--which kind of defeats the purpose of a generic function in most cases.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

////////////////////////////////////////////////////////////////////////////////
// Function prototypes

void swap( void* a, void* b, int sz );

////////////////////////////////////////////////////////////////////////////////
// Functions

void swap( void* a, void* b, int sz )
{
	char* buf = malloc( sizeof( char ) * sz );
	memcpy( buf, a, sz );
	memcpy( a, b, sz );
	memcpy( b, buf, sz );
	free( buf );
}

////////////////////////////////////////////////////////////////////////////////
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
