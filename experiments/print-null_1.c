////////////////////////////////////////////////////////////////////////////////
// Comments

// Prints out null.

// I mainly want to know if it has any width when printed as a character.

// Nope, null characters do not have any width.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
int main( void )
{
	char c; // Character

	c = 'h';
	printf( "c =[%c]\n", c );

	c = '\0';
	printf( "c =[%c]\n", c );

	return 0;
}
