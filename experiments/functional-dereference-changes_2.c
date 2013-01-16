////////////////////////////////////////////////////////////////////////////////
// Comments

// Tests changing a dereferenced pointer's value in a function (I've been having problems doing this, e.g. d_s()).
// Problem diagnosed: in d_s(), the pointer is reset to a malloc-ed address, to which the main() pointer is not also reset to point to.

// Works!

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
// Functional Prototypes

void memcpy_1( char *source, char *target );

void memcpy_2( char *source, char *target );

////////////////////////////////////////////////////////////////////////////////
// Functions

void memcpy_1( char *source, char *target )
{
	char *src = source;
	char *tgt = target;

	while( *tgt++ = *src++ );
}

void memcpy_2( char *source, char *target )
{
	while( *target++ = *source++ );
}

////////////////////////////////////////////////////////////////////////////////
int main()
{
	char string_1[] = "Hey";
	char string_2[] = "Bye";
	char string_3[] = "Sam";
	char string_4[] = "Liz";

	printf( "memcpy_1:\n\tBefore:\n\t\tstring_1 = [%s]\n\t\tstring_2 = [%s]\n", string_1, string_2 );
	memcpy_1( string_1, string_2 );
	printf( "\tAfter:\n\t\tstring_1 = [%s]\n\t\tstring_2 = [%s]\n", string_1, string_2 );

	printf( "memcpy_2:\n\tBefore:\n\t\tstring_3 = [%s]\n\t\tstring_4 = [%s]\n", string_3, string_4 );
	memcpy_2( string_3, string_4 );
	printf( "\tAfter:\n\t\tstring_3 = [%s]\n\t\tstring_4 = [%s]\n", string_3, string_4 );

	return 0;
}
