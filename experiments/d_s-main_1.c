////////////////////////////////////////////////////////////////////////////////
// Comments

// Testing out the d_s() function, but as a void return.

// Doesn't work. When you think about it for a minute, though, it becomes obvious: in main, s points to one particular address; in d_s, s initially points to that address, but then it points to a malloc-ed address; however, back in main, s isn't reset to point to the malloc-ed address.
// This is also why to make this main work, free( s ) has to be commented out--because s has not been malloc-ed.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdlib.h>
#include <stdio.h>
#include "d_s-head_1.h"

////////////////////////////////////////////////////////////////////////////////
int main()
{
	char *s;

	printf( "main: before d_s, s = [%s]\n", s );
	d_s( s );
	printf( "main: after d_s, s = [%s]\n", s );

	//free( s );

	return 0;
}
