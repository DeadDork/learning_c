////////////////////////////////////////////////////////////////////////////////
// Comments

// Found a snippet of enum. Hopefully it will work as advertised.

// Didn't work.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h> 

////////////////////////////////////////////////////////////////////////////////
int main( void )
{
	enum Days { Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday };

	Days TheDay;
	int j = 0;
	printf( "Please enter the day of the week (0 to 6)\n" );
	scanf( "%d", &j );
	TheDay = Days( j );

	if( TheDay == Sunday || TheDay == Saturday )
	{
		printf( "Hurray it is the weekend\n" );
	}
	else
	{
		printf( "Curses still at work\n" );
	}

	return 0;
}
