////////////////////////////////////////////////////////////////////////////////
// Comments

// This function lets the user enter a string of arbitrary length (given the limitations of the hardware, of course).

// I might need to adjust the conditions that end the fgetc. For now, though, a newline or end-of-file seem good.

// REMEMBER TO free() s!!!

// Also, I am a little concerned about stack smashing... As best as I can figure, this isn't much of a concern, as the string gets placed in the heap, while the program gets placed in the stack.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>
#include <stdlib.h>
#include "d_s.h"

////////////////////////////////////////////////////////////////////////////////
// Functions

char* d_s( char* s ) // d_s = dynamic string; s = string.
{
	int c; // Character
	int sz = 0; // Size

	s = malloc( sizeof( char ) );
	while( ( c = fgetc( stdin ) ) != '\n' && c != EOF )
	{
		s = realloc( s, sizeof( char ) * ++sz );
		*( s + ( sz - 1 ) ) = c;
	}
	*( s + sz ) = '\0';

	return s;
}
