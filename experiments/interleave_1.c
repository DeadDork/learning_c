////////////////////////////////////////////////////////////////////////////////
// Comments

// There is a comment in K & R, 1.5.1 that's odd:

/*	Calls to putchar and printf may be interleaved; the output will appear in the order in which the calls are made. */

// This program explores the term "interleaving" in this context.

// All 'interleaving' means is that they can be used procedurally, one after the other after the other.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
int main()
{
	int c;

	while( ( c = getchar() ) != EOF )
	{
		printf( "printf: c = [%c]\n", c );
		printf( "putchar: c = [" );
		putchar( c );
		printf( "]\n" );
	}

	return 0;
}
