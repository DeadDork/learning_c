////////////////////////////////////////////////////////////////////////////////
// Comments

// Solution to exercise 3-1.

// This program does two things:
//
// 1) It performs three different kinds of binary search:
//
//// (a) K & R's original version, which employs a loop with two tests in the
//// if-then, and only one test in the loop head;
////
//// (b) my version, which employs a loop with only one test in the if-then,
//// but two tests in the loop head;
////
//// (c) Andrew Tesker's version, which employs a loop with only one test in
//// the if-then *and* only one test in the loop head.
//
// 2) It measures and prints the run time of all three binary searches.

// Conclusion: K & R's < Nimi's, and Nimi's < AT's in terms of run time, but the
// difference is ~150 nanoseconds between each on my implementation. Trying to
// optimize such a small difference is pointless in my opinion. Instead, the
// question should be which is easier to reason about, debug, and maintain. Of
// the three, I think K & R's version does this best--it also has the best run
// times! (While I admire the simplicity of AT's function, holy crap was it
// tricky to reason about. Also, its pretty wasteful.)

// N.B. In order to measure the run time, I used <time.h>, which I'm not
// supposed to "know" about yet. However, as it doesn't matter how I measure
// run time, just that I do, I used it regardless.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>
#include <time.h>

////////////////////////////////////////////////////////////////////////////////
// Function Prototypes

int binsearch_knr( int x, int v[], int n );
/* Retrieves from an ordered number set the position of the first match.
 
   `x` = The number being matched against in the ordered set.

   `v[]` = The ordered number set (a vector).

   `n` = The number of elements in the number set.

   If `x` matches an element in v[], the function returns the first position
   of the match; if there is no match, it returns -1. */

int binsearch_nimi( int x, int v[], int n );
/* Retrieves from an ordered number set the position of the first match.
 
   `x` = The number being matched against in the ordered set.

   `v[]` = The ordered number set (a vector).

   `n` = The number of elements in the number set.

   If `x` matches an element in v[], the function returns the first position
   of the match; if there is no match, it returns -1. */

int binsearch_at( int x, int v[], int n );
/* Retrieves from an ordered number set the position of the first match.
 
   `x` = The number being matched against in the ordered set.

   `v[]` = The ordered number set (a vector).

   `n` = The number of elements in the number set.

   If `x` matches an element in v[], the function returns the first position
   of the match; if there is no match, it returns -1.
   
   N.B. This version was created by Andrew Tesker 
   <http://users.powernet.co.uk/eton/kandr2/krx301.html>. I wish I
   were as clever, because this is the only solution to this exercise I could
   find--let alone come up with on my own--that uses a total of just two tests.
   All other solutions perform at least three tests. */

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

int binsearch_at( int x, int v[], int n )
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
	int e, ee, maxe = 100, maxlp = 100000; // Element 1, Element 2, MAXimum number of Elements, MAXimum number LooPs
	int v[ maxe ]; // ordered number Vector
	clock_t start, stop; // stopwatch START time, stopwatch STOP time
	long double runtime_knr = 0, runtime_nimi = 0, runtime_at = 0;

	/* Populates vector */
	for( e = 0; e < maxe; ++e )
	{
		v[ e ] = e;
	}

	/* Gets average run time */
	for( e = 0; e < maxlp; ++e )
	{
		/* KNR's binary search */
		start = clock();
		for( ee = 0; ee < maxe; ++ee )
		{
			binsearch_knr( ee, v, maxe );
		}
		stop = clock();
		runtime_knr += stop - start;

		/* My binary search */
		start = clock();
		for( ee = 0; ee < maxe; ++ee )
		{
			binsearch_nimi( ee, v, maxe );
		}
		stop = clock();
		runtime_nimi += stop - start;

		/* Andrew Tesker's binary search */
		start = clock();
		for( ee = 0; ee < maxe; ++ee )
		{
			binsearch_at( ee, v, maxe );
		}
		stop = clock();
		runtime_at += stop - start;
	}
	printf( "Average run time for binsearch_knr = [%Lf]\n", runtime_knr / maxlp );
	printf( "Average run time for binsearch_nimi = [%Lf]\n", runtime_nimi / maxlp );
	printf( "Average run time for binsearch_at = [%Lf]\n", runtime_at / maxlp );

	return 0;
}
