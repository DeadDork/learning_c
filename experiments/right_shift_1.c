////////////////////////////////////////////////////////////////////////////////
// Comments

// I'm getting some weird values when I right shift. This attempts to work out why.

// OK, I see what's happening. This implementation overflows & underflows by
// moving the bit shifted out of the data structure to the start of the data
// structure.

// Notice, though, that the shift is not done on a rotation, but in multiples of
// the maximum bit length (e.g. '1 >> e' = anything but zero on multiples of 32).

/////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
int main( void )
{
	int e; // Element

	printf( "| %.2s | %.32s | %.32s | %.32s | %.32s | \n", "e", "~0 << e", "~0 >> e", "1 << e", "1 >> e" );
	for( e = 0; e < 66; ++e )
	{
		printf( "| %2d | %32u | %32u | %32u | %32u |\n", e, ~0 << e, ~0 >> e, 1 << e, 1 >> e );
	}

	return 0;
}
