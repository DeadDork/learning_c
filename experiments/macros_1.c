////////////////////////////////////////////////////////////////////////////////
// Comments

// Tries out a nifty piece of code I saw online.
// CF: http://pine.cs.yale.edu/pinewiki/C/Macros

// THIS IS CRAZY COOL!

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
// Macros

#define PrintExpr( x ) ( printf( "%s = [%d]\n", #x, ( x ) ) )
////////////////////////////////////////////////////////////////////////////////
int main()
{
	PrintExpr( 4 + 5 );

	return 0;
}
