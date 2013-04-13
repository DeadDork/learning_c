////////////////////////////////////////////////////////////////////////////////
// Comments

// I wasn't quite sure how the vinary search in K & R 3.3 worked for out of
// bounds values. This program explores just that question.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
// Function Prototypes

int binsearch( int x, int ord_set[], int maxima );
/* Searches for the position in an ordered number set for the first instance of
   a number.

   `x` = The number being search for in the ordered set.

   `ord_set` = The ordered number set.

   `maxima` = The number of elements in the number set.

   If `x` matches an element in ord_set, the function returns the first position
   of the match; if no match, returns -1. */

////////////////////////////////////////////////////////////////////////////////
// Functions

int binsearch( int x, int ord_set[], int maxima )
{
	int low, mid, high;

	low = 0;
	high = maxima - 1;

	while( low <= high )
	{
		mid = ( low + high ) / 2;

		if( x < ord_set[ mid ] )
		{
			high = mid - 1;
		}
		else if( x > ord_set[ mid ] )
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
////////////////////////////////////////////////////////////////////////////////
int main( void )
{
	int maxv = 10; // 10 < 11
	int vector[ maxv + 1 ];
	int e, ee; // Element, Element copy 1

	for( e = 0; e < maxv; ++e )
	{
		vector[ e ] = 20 + e;
	}
	vector[ 5 ] = vector[ 6 ];
	vector[ maxv ] = -1;

	for( e = -5; e < maxv + 5; ++e )
	{
		ee = ( binsearch( e + 20, vector, maxv ) != -1 ) ? binsearch( e + 20, vector, maxv ) : maxv;
		printf( "%d = vector[%d] = %d\n", e, ee, vector[ ee ] );
	}

	return 0;
}
