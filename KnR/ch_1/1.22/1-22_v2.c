////////////////////////////////////////////////////////////////////////////////
// Comments

// Solution ex. 1-22.

// Works!
// ...Though there is a bug with overflow strings that are prepended with whitespace.

// I've managed to include more robust folding features, but I still feel that the design is weak.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
// Symbolic Constants

#define FALSE 0
#define TRUE 1

////////////////////////////////////////////////////////////////////////////////
// External Variables

int maxstr; // MAXimum STRing
int endarr; // terminal END of ARRay (makes code more readable)

////////////////////////////////////////////////////////////////////////////////
// Function Prototypes

int is_ws( char c );
/* Checks whether the parameter is a whitespace character.
 
   `c` = The character to check.

   Returns FALSE (i.e. 0) if the character is not a whitespace character; returns TRUE (i.e. 1) if it is. */

int println( char s[], char c );
/* Prints an input line so that it folds intelligently.
 
   `s` = The input string to fold.
   `c` = The latest character from input.

   Returns the column number to append to the excess character string. */

////////////////////////////////////////////////////////////////////////////////
// Functions

int is_ws( char c )
{
	int value; // return VALUE

	if( c == ' ' || c == '\t' || c == '\n' || c == '\0' )
	{
		value = TRUE;
	}
	else
	{
		value = FALSE;
	}

	return value;
}

int println( char s[], char c )
{
	extern int maxstr;
	extern int endarr;
	char tmps[ maxstr ]; // TeMPorary String
	int e, lastword, value; // Element, LAST WORD start position, return VALUE

	/* If the string runs over */
	if( !( is_ws( s[ endarr ] ) ) && !( is_ws( c ) ) )
	{
		/* Get the position of the start of the last word substring */
		for( e = endarr; !( is_ws( s[ e ] ) ) && e >= 0; --e );
		lastword = e + 1;

		/* If entire line is a single non-ws word that runs over */
		if( lastword == 0 )
		{
			tmps[ 0 ] = s[ endarr ];
			s[ endarr ] = '-';
			printf( "%s\n", s );

			s[ 0 ] = tmps[ 0 ];
			s[ 1 ] = c;

			value = 2;
		}
		/* If there are multiple words in a string, and the last word runs over */
		/* Or there is one word that runs over that is preceded by white spaces */
		else
		{
			for( e = 0; s[ lastword + e ] != '\0'; ++e )
			{
				tmps[ e ] = s[ lastword + e ];
			}
			tmps[ e ] = '\0';

			for( e = lastword - 1; is_ws( s[ e ] ); --e )
			{
				s[ e ] = '\0';
			}
			if( e > 0 )
			{
				printf( "%s\n", s );
			}

			for( e = 0; tmps[ e ] != '\0'; ++e )
			{
				s[ e ] = tmps[ e ];
			}
			s[ e ] = c;

			value = e + 1;
		}
	}
	/* If the string does not run over */
	else
	{
		for( e = endarr; is_ws( s[ e ] ); --e )
		{
			s[ e ] = '\0';
		}
		printf( "%s\n", s );

		if( c != '\n' )
		{
			s[ 0 ] = c;
			value = 1;
		}
		else
		{
			value = 0;
		}
	}

	return value;
}

////////////////////////////////////////////////////////////////////////////////
int main( void )
{
	maxstr = 80; // number of characters in string
	++maxstr; // + NULL
	endarr = maxstr - 2 ; // array offset + NULL = 2
	char string[ maxstr ]; // STRING
	int c; // Character
	int col = 0; // COLumn in input line

	while( ( c = getchar() ) != EOF )
	{
		if( c == '\n' || col > endarr )
		{
			string[ col ] = '\0';
			col = println( string, c );
		}
		else
		{
			string[ col++ ] = c;
		}
	}

	return 0;
}
