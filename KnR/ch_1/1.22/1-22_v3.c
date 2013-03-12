////////////////////////////////////////////////////////////////////////////////
// Comments

// This is a third attempt to create an elegant solution to 1-22.

// Works!

// This version has robust folding features & I feel that the design is finally half-way decent.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
// Symbolic Constants

#define FALSE 0
#define TRUE 1

////////////////////////////////////////////////////////////////////////////////
// External Variables

int maxstr; // MAXimum STRing length
int endarr; // END of ARRay, i.e. position of last character in string (makes code more readable)

////////////////////////////////////////////////////////////////////////////////
// Function Prototypes

int is_ws( char c );
/* Checks whether a given input character is a whitespace character.
 
   `c` = The input character.

   Returns TRUE if `c` is a whitespace character; otherwise returns FALSE. */

void overflow( char str[], char tmpstr[] );
/* Intelligently handles line overflow.
 
   `str` = The main input string.
   `tmpstr` = The temporary string that carries over any overflow from `str`. */

void despace( char str[] );
/* Removes trailing whitespace from a string.
 
   `str` = The string that will have any trailing whitespace removed. */

int println( char str[], char c );
/* Prints the input line in accord with a few intelligent line folding rules.
 
   `str` = The input string to be formatted, and then printed.
   `c` = The latest input character.

   Returns the position to assign the next input character to the `str` array (in case of overflow, this value will be > 0). */

////////////////////////////////////////////////////////////////////////////////
// Functions

int is_ws( char c )
{
	int value; // return VALUE

	if( c == ' ' || c == '\t' || c == '\n' )
	{
		value = TRUE;
	}
	else
	{
		value = FALSE;
	}

	return value;
}

void overflow( char str[], char tmpstr[] )
{
	extern int endarr;

	int e, lastword, llastword; // Element, LAST WORD, second to LAST WORD

	/* Get the start position of the last word */
	for( e = endarr;  e >= 0 && !( is_ws( str[ e ] ) ); --e );
	lastword = e + 1;

	/* Get the end position of the second to last word */
	for( e = lastword - 1; e >= 0 && is_ws( str[ e ] ); --e );
	llastword = e;

	/* If entire line is a single non-ws word that runs over */
	/* Or if the line is only one word that runs over that is preceded by white spaces */
	//if( lastword == 0 || llastword == -1 ) // More obvious, but less elegant
	if( llastword == -1 )
	{
		tmpstr[ 0 ] = str[ endarr ];
		tmpstr[ 1 ] = '\0';
		str[ endarr ] = '-';
	}

	/* If there are multiple non-ws words, the last of which runs over */
	if( llastword >= 0 )
	{
		for( e = 0; str[ lastword + e ] != '\0'; ++e )
		{
			tmpstr[ e ] = str[ lastword + e ];
		}
		tmpstr[ e ] = '\0';
		str[ llastword + 1 ] = '\0';
	}
}

void despace( char str[] )
{
	int e; // Element

	for( e = 0; str[ e ] != '\0'; ++e );
	for( --e; is_ws( str[ e ] ) && e >= 0; --e );
	str[ e + 1 ] = '\0';
}

int println( char str[], char c )
{
	int e; // Element
	char tmpstr[ maxstr ]; // TeMPorary STRing
	tmpstr[ 0 ] = '\0';

	/* If the line overflows its maximum length */
	if( !( is_ws( str[ endarr ] ) ) && !( is_ws( c ) ) )
	{
		overflow( str, tmpstr );
	}

	despace( str );

	printf( "%s\n", str );

	/* Assign to the next line overflow from the previous line */
	for( e = 0; tmpstr[ e ] != '\0'; ++e )
	{
		str[ e ] = tmpstr[ e ];
	}
	if( c != '\n' )
	{
		str[ e ] = c;
		++e;
	}

	return e;
}

////////////////////////////////////////////////////////////////////////////////
int main( void )
{
	extern int maxstr;
	extern int endarr;
	maxstr = 80; // desired width of output
	++maxstr; // +1 for terminating NULL
	endarr = maxstr - 2; // NULL + array offset

	int c; // Character
	int col = 0; // COLumn
	char line[ maxstr ];

	while( ( c = getchar() ) != EOF )
	{
		if( c == '\n' || col > endarr )
		{
			line[ col ] = '\0';
			col = println( line, c );
		}
		else
		{
			line[ col++ ] = c;
		}
	}

	return 0;
}
