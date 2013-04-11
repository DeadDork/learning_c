////////////////////////////////////////////////////////////////////////////////
// Comments

// Tests left shifting all they way.

// Apparently overshifting results in the value of the final bit shifting to the
// first bit. I have no idea whether this is implementation specific or not.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>
#include <limits.h>

////////////////////////////////////////////////////////////////////////////////
int main( void )
{
	int e; // Element

	for( e = 0; e < 65; ++e ) // This should shift even 64 bit unsigned ints.
	{
		printf( "[%u] << [%u] = [%u]\n", 1, e, 1 << e );
	}
	printf( "UINT_MAX = [%u]\n", UINT_MAX );

	return 0;
}
