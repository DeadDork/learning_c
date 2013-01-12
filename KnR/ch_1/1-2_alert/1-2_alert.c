////////////////////////////////////////////////////////////////////////////////
// Comments

// Experiments with the bell character.

// I can't figure out a way to print out more than 1 bell, not in a way I can notice anyway.

#include <stdio.h>

int main()
{
	int c;

	// The below only prints one alert.
	//printf( "\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a" );

	// So does the below.
	/*
	printf( "\a" );
	printf( "\a" );
	printf( "\a" );
	printf( "\a" );
	printf( "\a" );
	printf( "\a" );
	printf( "\a" );
	printf( "\a" );
	printf( "\a" );
	printf( "\a" );
	printf( "\a" );
	printf( "\a" );
	printf( "\a" );
	printf( "\a" );
	printf( "\a" );
	printf( "\a" );
	printf( "\a" );
	printf( "\a" );
	printf( "\a" );
	printf( "\a" );
	printf( "\a" );
	printf( "\a" );
	printf( "\a" );
	printf( "\a" );
	printf( "\a" );
	printf( "\a" );
	printf( "\a" );
	printf( "\a" );
	printf( "\a" );
	printf( "\a" );
	printf( "\a" );
	printf( "\a" );
	printf( "\a" );
	printf( "\a" );
	printf( "\a" );
	printf( "\a" );
	printf( "\a" );
	printf( "\a" );
	printf( "\a" );
	printf( "\a" );
	printf( "\a" );
	printf( "\a" );
	printf( "\a" );
	printf( "\a" );
	printf( "\a" );
	printf( "\a" );
	printf( "\a" );
	printf( "\a" );
	printf( "\a" );
	printf( "\a" );
	printf( "\a" );
	*/

	// So does this
	/*
	printf( "\a\n" );
	printf( "\a\n" );
	printf( "\a\n" );
	printf( "\a\n" );
	printf( "\a\n" );
	printf( "\a\n" );
	printf( "\a\n" );
	printf( "\a\n" );
	printf( "\a\n" );
	printf( "\a\n" );
	printf( "\a\n" );
	printf( "\a\n" );
	printf( "\a\n" );
	printf( "\a\n" );
	printf( "\a\n" );
	printf( "\a\n" );
	printf( "\a\n" );
	printf( "\a\n" );
	printf( "\a\n" );
	printf( "\a\n" );
	printf( "\a\n" );
	*/

	// Kinda works.
	while( ( c = getchar() ) != EOF )
		printf( "\a" );

	return 0;
}
