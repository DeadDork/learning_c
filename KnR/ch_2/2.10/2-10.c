////////////////////////////////////////////////////////////////////////////////
// Comments

// Solution to exercise 2-10.

// Reads & prints input; if any of it is an alphabetical upper case, lowers it.

// N.B. I've included a out "correct" alternative. However, as it's
// edifying value is nil in this context, it's commented out.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>
//#include <ctype.h>

////////////////////////////////////////////////////////////////////////////////
int main( void )
{
	int c; // Character

	while( ( c = getchar() ) != EOF )
	{
		putchar( ( c >= 'A' && c <= 'Z' ) ? ( c + ( 'a' - 'A' ) ) : c );
		//putchar( tolower( c ) );
	}

	return 0;
}
