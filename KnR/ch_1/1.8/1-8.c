////////////////////////////////////////////////////////////////////////////////
// Comments

// Solution to ex. 1-8.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
int main()
{
	int c; // single Character
	double b = 0; // Blanks count
	double n = 0; // Newlines count
	double t = 0; // Tabs count

	/* Count blanks, newlines, and tabs */
	while( ( c = getchar() ) != EOF )
	{
		if( c == ' ' )
		{
			++b;
		}

		if( c == '\n' )
		{
			++n;
		}

		if( c == '\t' )
		{
			++t;
		}
	}

	/* Print counts */
	printf( "Counts:\n\tBlanks = [%.0lf]\n\tNewlines = [%.0lf]\n\tTabs = [%.0lf]\n", b, n, t );

	return 0;
}
