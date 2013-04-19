////////////////////////////////////////////////////////////////////////////////
// Comments

// Tests concatenating string literals with a space in a printf().

// Works! I gather from this that string literals separated by a space are
// concatenated.
// Indeed, K & R explicitly states this rule in <2.3>.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
int main( void )
{
	printf( "Hi\n" "\tMy name is\n" "Who?\n" "\tMy name is\n" "What?\n" "\tMy name is\n" "<chicky chicky chicky> Slim Shady!\n" );

	return 0;
}
