////////////////////////////////////////////////////////////////////////////////
// Comments

// This is simple C program that demonstrates my preferred C coding style.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
// Symbolic Constants

#define FALSE 0
#define TRUE 1

////////////////////////////////////////////////////////////////////////////////
// Macros

#define PrintExpr( x ) ( printf( "PrintExpr:\n\t%s = [%d]\n", #x, ( x ) ) )

////////////////////////////////////////////////////////////////////////////////
// Function Prototypes

void print_test( int x, int y );
/* Prints out x + y twice: 1) adding the two in the arguments of a normal `printf` 2) letting a macro do the "heavy" lifting.

   *x* = the first integer you are adding.
   *y* = the second integer you are adding. */

////////////////////////////////////////////////////////////////////////////////
// Functions

void print_test( int x, int y )
{
	printf( "printf:\n\tx + y = [%d]\n", x + y );
	PrintExpr( x + y );
}

////////////////////////////////////////////////////////////////////////////////
int main()
{
	int *x, y; // I fully realize how silly it is to make x into a pointer.

	/* Sets x */
	for( *x = 0; *x < 10; ++( *x ) );

	/* Sets y */
	while( y != 90 )
	{
		if( y < 80 )
		{
			y = y + 10;
		}
		else if( y >= 80 )
		{
			++y;
		}
	}

	/* Prints x + y */
	print_test( *x, y );

	return 0;
}
