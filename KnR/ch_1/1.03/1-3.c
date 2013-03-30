////////////////////////////////////////////////////////////////////////////////
// Comments

// Prints a limited Fahrenheit - Celsius table.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
int main()
{
	float fahr, cels;

	int cold = -80; // Coldest temperature to convert
	int hot = 300; // Hottest temperature to convert
	int step = 20; // Step size

	printf( "+----------------------+\n" );
	printf( "| %s | %s |\n", "Fahrenheit", "Celsius" );
	printf( "+----------------------+\n" );
	for( fahr = cold; fahr <= hot; fahr = fahr + step )
	{
		cels = ( 5.0 / 9.0 ) * ( fahr - 32.0 );
		printf( "| %10.1f | %7.1f |\n", fahr, cels );
	}
	printf( "+----------------------+\n" );

	return 0;
}
