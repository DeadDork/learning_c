////////////////////////////////////////////////////////////////////////////////
// Comments

// Explores the order stdin reads input.

// Conclusion: reads input from the head to the tail, as expected.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
int main( void )
{
	int c, order = 1; // Character, ORDER read

	while( ( c = getchar() ) != EOF && c != '\n' )
	{
		printf( "[ %c | %d ] ", c, order++ );
	}
	putchar( '\n' );

	return 0;
}