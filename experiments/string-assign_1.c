////////////////////////////////////////////////////////////////////////////////
// Comments

// Tests assigning a string constant to a string array variable.

// Works!

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
// Function Prototypes

void strassign( char * sconst, char * sarray );
/* Assigns a string constant to a string array.
 
   `sconst` = String constant (e.g. "Goodbye cruel world").
   `sarray` = String array variable. */

////////////////////////////////////////////////////////////////////////////////
// Functions

void strassign( char * sconst, char * sarray )
{
	while( *sconst != '\0' )
	{
		*sarray++ = *sconst++;
	}
	*sarray = '\0';
}

////////////////////////////////////////////////////////////////////////////////
int main( void )
{
	int maxstr = 1000; // MAXimum STRing length
	char s[ maxstr ]; // String
	char ss[ maxstr ]; // String

	s[ 0 ] = '\0';
	ss[ 0 ] = '\0';
	printf( "Original:\n\ts = [%s]\n\tss = [%s]\n", s, ss );

	strassign( "How beauteous mankind is! O brave new world, that has such people in it!\0", s );
	strassign( "I hereby declare my wish to die a free man rather than to continue to live as a slave in a prison. And so I leave this world, where the heart must either break or turn to lead.\0", ss );
	printf( "Mutation:\n\ts = [%s]\n\tss = [%s]\n", s, ss );

	return 0;
}
