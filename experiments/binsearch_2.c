////////////////////////////////////////////////////////////////////////////////
// Comments

// Tests out two binsearch()'s: the first has two tests; the second has one.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>
#include <time.h>

////////////////////////////////////////////////////////////////////////////////
// Function Prototypes

int binsearchA( int x, int v[], int n );
/* Searches for the position in an ordered number set for the first instance of
   a number.

   `x` = The number being search for in the ordered set.

   `v[]` = The ordered number vector.

   `n` = The number of elements in the number set.

   If `x` matches an element in v[], the function returns the first position
   of the match; if no match, returns -1.
   
   N.B. This version uses two tests. */

int binsearchB( int x, int v[], int n );
/* Searches for the position in an ordered number set for the first instance of
   a number.

   `x` = The number being search for in the ordered set.

   `v[]` = The ordered number set.

   `n` = The number of elements in the number set.

   If `x` matches an element in v[], the function returns the first position
   of the match; if no match, returns -1.
   
   N.B. This version uses only one test. */

////////////////////////////////////////////////////////////////////////////////
// Functions

int binsearchA( int x, int v[], int n )
{
	int low, mid, high;

	low = 0;
	high = n - 1;

	while( low <= high )
	{
		mid = ( low + high ) / 2;

		if( x < v[ mid ] )
		{
			high = mid - 1;
		}
		else if( x > v[ mid ] )
		{
			low = mid + 1;
		}
		else
		{
			return mid;
		}
	}

	return -1;
}

int binsearchB( int x, int v[], int n )
{
	int low, mid, high;

	low = 0;
	high = n - 1;
	mid = ( low + high ) / 2;

	//printf( "x = [%d]\n", x );
	while( x != v[ mid ] && low < high )
	{
		//printf( "\tlow = [%d]; mid = [%d][%d]; high = [%d]\n", low, mid, v[ mid ], high );

		if( x < v[ mid ] )
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
		mid = ( low + high ) / 2;
	}

	//printf( "\tlow = [%d]; mid = [%d][%d]; high = [%d]\n", low, mid, v[ mid ], high );

	return ( x == v[ mid ] ) ? mid : -1;
}

////////////////////////////////////////////////////////////////////////////////
int main( void )
{
	int e, maxe = 10; // Element, MAXimum number of Elements
	int v[ maxe + 1 ]; // ordered number Vector

	for( e = 0; e < maxe; ++e )
	{
		v[ e ] = e;
	}
	v[ 5 ] = v[ 6 ]; // error test

	for( e = 0; e <= maxe; ++e ) // error test (i.e. 'e <= maxe' rather than 'e < maxe')
	{
		printf( "binsearchA (%d, v, %d) = %d\n", e, maxe, binsearchA( e, v, maxe ) );
		printf( "binsearchB (%d, v, %d) = %d\n\n", e, maxe, binsearchB( e, v, maxe ) );
	}

	return 0;
}
