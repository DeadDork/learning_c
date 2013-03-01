////////////////////////////////////////////////////////////////////////////////
// Comments

// Solution to ex. 1-21.

// Works!

// To answer the question: is it better to use a tab or a single space when one space away from the next tab stop? I don't know. I chose to go with a space, as it makes for a more elegant solution in my opinion.

// N.B. I hate using external variables. Therein lies madness...

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
// External Variables

/* For spacer(), I need to change two variables passed to it (if it was only one variable, I could simply set it to the return value of a function that takes that variable as an argument). Alternatively, I could use pointers. However, as this is ch.1 & I still don't "know" how to use pointers, I have to use external variables instead. */
int offset = 0; // OFFSET from tab stop
int spnum = 0; // white SPace NUMber

////////////////////////////////////////////////////////////////////////////////
// Function Prototypes

void offsetter( char c, int tabstop );
/* Sets the space offset number as needed.
 
   `c` = The current character from STDIN.

   `tabstop` = The fixed length of a tabstop. */
 
void spacer( char c, int tabstop );
/* Generates white space using the fewest number of tab and space characters, in accord with the tab stop ruler.
 
   `c` = The current character from STDIN.

   `tabstop` = The fixed length of a tabstop. */

////////////////////////////////////////////////////////////////////////////////
// Functions

void offsetter( char c, int tabstop )
{
	if( c == '\n' || c == '\t' )
	{
		offset = 0;
	}
	else
	{
		++offset;
	}

	if( offset == tabstop )
	{
		offset = 0;
	}
}

void spacer( char c, int tabstop )
{
	while( spnum > 0 )
	{
		if( spnum >= tabstop && offset == 0 )
		{
			putchar( '\t' );
			spnum = spnum - tabstop;
		}
		else
		{
			--spnum;
			putchar( ' ' );
			offsetter( c, tabstop );
		}
	}
}

////////////////////////////////////////////////////////////////////////////////
int main( void )
{
	int c; // Character
	int tabstop = 4; // TAB STOP (default is usually every 8 columns, but I prefer 4)

	while( ( c = getchar() ) != EOF )
	{
		if( c == ' ' )
		{
			++spnum;
		}
		else
		{
			spacer( c, tabstop );
			putchar( c );
			offsetter( c, tabstop );
		}
	}

	return 0;
}
