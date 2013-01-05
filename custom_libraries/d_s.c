////////////////////////////////////////////////////////////////////////////////
// Comments

// This function lets the user enter a string of arbitrary length (given the limitations of the hardware, of course).

// I might need to adjust the conditions that end the fgetc. For now, though, a newline or end-of-file seem good.

// REMEMBER TO free() s!!!

// Having some trouble. The following compiles just fine all alone, but not when split up like a proper library.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>
#include <stdlib.h>
//#include "d_s.h"

////////////////////////////////////////////////////////////////////////////////
// Functions

char* ds( char* s );

char* ds( char* s ) // d_s = dynamic string; s = string.
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

int main()
{
	char* s;
	           
	s = ds( s );                                                                                                                                                       
	printf( "Dynamic string = [%s]\n", s );
           
	return 0;
}        
