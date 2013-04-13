////////////////////////////////////////////////////////////////////////////////
// Comments

// Tests out clock().

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>
#include <time.h>

////////////////////////////////////////////////////////////////////////////////
int main( void )
{
	int e; // Element
	int loopn = 10000000; // Number of LOOPs
	clock_t timeA, timeB;
	double runtime = 0; // total average RUN TIME

	for( e = 0; e < 10; ++e )
	{
		printf( "Random clock() value %d = [%d]\n", e, ( int )clock() );
	}
	putchar( '\n' );

	timeA = clock();
	for( e = 0; e < loopn; ++e )
	{
		timeB = clock();
		runtime = ( runtime + ( double )( timeB - timeA ) ) / 2;
		timeA = clock();
	}
	printf( "\nAverage run-time of a fairly simple for loop = [%f] microseconds\n", runtime );

	return 0;
}
