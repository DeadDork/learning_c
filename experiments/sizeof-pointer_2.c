////////////////////////////////////////////////////////////////////////////////
// Comments

// This was a dead-end. I thought that maybe the sizeof differential was due to some weird, subtle difference between arrays and pointers.

// (It was actually that the function copy of the array/pointer only had the address to the real array, so only was of 8 bytes in length.)

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
// Function prototypes

void a_sizeof( char s[] );
void p_sizeof( char* s );

////////////////////////////////////////////////////////////////////////////////
// Functions

void a_sizeof( char s[] )
{
	printf( "sizeof(s[]) = [%ld]\n", sizeof( s ) );

	printf( "s[] = [%s]\n\n", s );
}

void p_sizeof( char* s )
{
	printf( "sizeof(*s) = [%ld]\n", sizeof( s ) );

	printf( "*s = [%s]\n", s );
}

////////////////////////////////////////////////////////////////////////////////
int main()
{
	char s[] = "hello, world";

	printf( "sizeof(s) = [%ld]\n\n", sizeof( s ) );
	a_sizeof( s );
	p_sizeof( s );

	return 0;
}
