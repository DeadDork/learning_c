////////////////////////////////////////////////////////////////////////////////
// Comments

// Solution to exercise 3-1.

// This program does two things:

// 1) It performs two different kinds of binary search, the first with two tests
// and the second with only one.

// 2) It measures and prints the run-time of both binary searches.

// Conclusion: The differences in run-time between the three versions is very,
// very small. That said, it stacks accordingly:
// K & R <= Nimi <= AT, +/-10 or 20 nanoseconds.

// N.B. In order to measure the run time, I used <time.h>, which I'm not
// supposed to "know" about yet. However, as it doesn't matter how I measure
// run-time, so long as I do, I used it regardless.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>
#include <time.h>

////////////////////////////////////////////////////////////////////////////////
// Function Prototypes

int binsearch_knr( int x, int v[], int n );
/* Searches for the position in an ordered number set for the first instance of
   a number.

   `x` = The number being search for in the ordered set.

   `v[]` = The ordered number vector.

   `n` = The number of elements in the number set.

   If `x` matches an element in v[], the function returns the first position
   of the match; if no match, returns -1.
   
   N.B. This version uses three tests total in the loop, and two in the if-then. */

int binsearch_nimi( int x, int v[], int n );
/* Searches for the position in an ordered number set for the first instance of
   a number.

   `x` = The number being search for in the ordered set.

   `v[]` = The ordered number set.

   `n` = The number of elements in the number set.

   If `x` matches an element in v[], the function returns the first position
   of the match; if no match, returns -1.
   
   N.B. This version uses three tests total in the loop, but only one in the
   if-then. */

int binsearch_AT( int x, int v[], int n );
/* Searches for the position in an ordered number set for the first instance of
   a number.

   `x` = The number being search for in the ordered set.

   `v[]` = The ordered number set.

   `n` = The number of elements in the number set.

   If `x` matches an element in v[], the function returns the first position
   of the match; if no match, returns -1.
   
   N.B. This verison uses two tests total in the loop, and only one in the
   if-then.

   N.B. This version is not mine, but was created by Andrew Tesker 
   <http://users.powernet.co.uk/eton/kandr2/krx301.html>. I wish I
   were this clever, as it's the only solution to this exercise I could find
   (let alone discover on my own) that uses--between the while loop & the
   if-then--just two logic tests. Every other one performs at least three tests. */

////////////////////////////////////////////////////////////////////////////////
// Functions

int binsearch_knr( int x, int v[], int n )
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

int binsearch_nimi( int x, int v[], int n )
{
	int low, mid, high;

	low = 0;
	high = n - 1;
	mid = ( low + high ) / 2;

	while( x != v[ mid ] && low <= high )
	{
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

	return ( x == v[ mid ] ) ? mid : -1;
}

int binsearch_AT( int x, int v[], int n )
{
	int low, mid, high;

	low = 0;
	high = n - 1;

	while( low < high )
	{
		mid = ( low + high ) / 2;
		if( x < v[ mid ] )
		{
			high = mid;
		}
		else
		{
			low = mid + 1;
		}
	}

	return ( x == v[ low ] ) ? low : -1;
}

////////////////////////////////////////////////////////////////////////////////
int main( void )
{
	int e, ee, maxe = 10, maxlp = 100000; // Element, Element copy 1, MAXimum number of Elements, MAXimum number LooPs
	int v[ maxe ]; // ordered number Vector
	clock_t timeA, timeB;
	long double runtime;

	/* Populates vector */
	for( e = 0; e < maxe; ++e )
	{
		v[ e ] = e + 10;
	}

	/* Gets average run time of KNR's binary search */
	runtime = 0.0;
	for( e = 0; e < maxlp; ++e )
	{
		timeA = clock();
		for( ee = 10; ee < maxe; ++ee )
		{
			binsearch_knr( ee, v, maxe );
		}
		timeB = clock();
		runtime += timeB - timeA;
	}
	printf( "Average run time for binsearch_knr = [%Lf]\n", runtime / maxlp );

	/* Gets average run time of my binary search */
	runtime = 0.0;
	for( e = 0; e < maxlp; ++e )
	{
		timeA = clock();
		for( ee = 10; ee < maxe; ++ee )
		{
			binsearch_nimi( ee, v, maxe );
		}
		timeB = clock();
		runtime += timeB - timeA;
	}
	printf( "Average run time for binsearch_nimi = [%Lf]\n", runtime / maxlp );

	/* Gets average run time of Andrew Tesker's binary search */
	runtime = 0.0;
	for( e = 0; e < maxlp; ++e )
	{
		timeA = clock();
		for( ee = 10; ee < maxe; ++ee )
		{
			binsearch_AT( ee, v, maxe );
		}
		timeB = clock();
		runtime += timeB - timeA;
	}
	printf( "Average run time for binsearch_AT = [%Lf]\n", runtime / maxlp );

	return 0;
}
