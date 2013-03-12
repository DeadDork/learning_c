////////////////////////////////////////////////////////////////////////////////
// Comments

// Tests reversing a string in a void function.

// Works!

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
// External Variables

int maxstr = 10; // MAXimum STRing length

////////////////////////////////////////////////////////////////////////////////
// Function Prototypes

void strassign( char * sconst, char * sarray );
/* Assigns a string constant to a string array.
 
   `sconst` = String constant (e.g. "Goodbye cruel world").
   `sarray` = String array variable. */

void reverse( char orig[] );
/* Reverses a character string array.
 
   `orig` = The original string, which will be reversed. */

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

void reverse( char orig[] )
{
	char tmps[ maxstr ]; // TeMPorary String
	int e, ee; // Element

	for( e = 0; orig[ e ] != '\0'; ++e )
	{
		tmps[ e ] = orig[ e ];
	}
	--e;
	for( ee = 0; ee <= e; ++ee )
	{
		orig[ ee ] = tmps[ e - ee ];
	}
}

////////////////////////////////////////////////////////////////////////////////
int main( void )
{
	char s[ maxstr ]; // String
	char ss[ maxstr ]; // String

	strassign( "Hello\0", s );
	strassign( "Goodbye\0", ss );

	printf( "Original:\n\ts = [%s]\n\tss = [%s]\n", s, ss );
	reverse( s ); reverse( ss );
	printf( "Mutation:\n\ts = [%s]\n\tss = [%s]\n", s, ss );

	return 0;
}
