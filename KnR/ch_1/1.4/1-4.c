////////////////////////////////////////////////////////////////////////////////
// Comments

// Prints a limited Celsius-to-Fahrenheit table.

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
	printf( "| %s | %s |\n", "Celsius", "Fahrenheit" );
	printf( "+----------------------+\n" );
	for( cels = cold; cels <= hot; cels = cels + step )
	{
		fahr = ( cels * ( 9.0 / 5.0 ) ) + 32;
		printf( "| %7.1f | %10.1f |\n", cels, fahr );
	}
	printf( "+----------------------+\n" );

	return 0;
}
