////////////////////////////////////////////////////////////////////////////////
// Comments

// Tests what happens when a value is greater than the max for the type,
	// for both signed and unsigned.

// Concusion: overflow of a type's boundary resets the counter to 0.
	// E.G. if char = 256, it's value will be reset to 0; 257 to 1, etc.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
int main( void )
{
	signed char c; // Character
	unsigned char cc; // Character

	/* Signed */
	printf( "Signed:\n" );

	c = 126;
	printf( "\tc = 126; d = [%d]; c = [%c]\n", c, c );

	c = 128;
	printf( "\tc = 128; d = [%d]; c = [%c]\n", c, c );

	c = 129;
	printf( "\tc = 129; d = [%d]; c = [%c]\n", c, c );

	c = 254;
	printf( "\tc = 254; d = [%d]; c = [%c]\n", c, c );

	c = 255;
	printf( "\tc = 255; d = [%d]; c = [%c]\n", c, c );

	c = 256;
	printf( "\tc = 256; d = [%d]; c = [%c]\n", c, c );

	c = 257;
	printf( "\tc = 257; d = [%d]; c = [%c]\n", c, c );

	c = 321; // Should equal 'A'
	printf( "\tc = 321; d = [%d]; c = [%c]\n", c, c );

	/* Unsigned */
	printf( "Unsigned:\n" );

	cc = 126;
	printf( "\tcc = 126; d = [%d]; c = [%c]\n", cc, cc );

	cc = 128;
	printf( "\tcc = 128; d = [%d]; c = [%c]\n", cc, cc );

	cc = 129;
	printf( "\tcc = 129; d = [%d]; c = [%c]\n", cc, cc );

	cc = 254;
	printf( "\tcc = 254; d = [%d]; c = [%c]\n", cc, cc );

	cc = 255;
	printf( "\tcc = 255; d = [%d]; c = [%c]\n", cc, cc );

	cc = 256;
	printf( "\tcc = 256; d = [%d]; c = [%c]\n", cc, cc );

	cc = 257;
	printf( "\tcc = 257; d = [%d]; c = [%c]\n", cc, cc );

	cc = 321; // Should equal 'A'
	printf( "\tcc = 321; d = [%d]; cc = [%c]\n", cc, cc );

	return 0;
}
