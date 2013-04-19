////////////////////////////////////////////////////////////////////////////////
// Comments

// In K & R 3.5, the authors introduce the Shell sort. I couldn't quite follow
// it, so I created a program that visualizes the sorting.

// OK, I get it:
//
// 1) It compares two values separated by n/2; if the former is
// larger than the latter, it switches their values; then it moves one space 
// right and repeats this.
//
// 2) When the position of the latter comparison passes the position extrema,
// the gap is set to 1/2 of it's former value. Step (1) is then repeated; step
// (2) is repeated everytime the latter comparison passes the position extrema.
//
// 3) When the gap between comparisons is 1 and the right comparision position
// passes the position extrema, then the vector is sorted!
//
// Pretty clever!

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>
#include <stdlib.h>

////////////////////////////////////////////////////////////////////////////////
// Function Prototypes

void shellsort( int vector[], int n );
/* Shell sorts a vector.
 
   `vector[]` = The array of numbers to sort.

   `n` = The number of elements in `vector[]`.

   N.B. Visualizes the sorting. */

////////////////////////////////////////////////////////////////////////////////
// Functions

void shellsort( int v[], int n )
{
	int gap, temp; // GAP between element comparison, TeMPorary number
	int e, ee, eee, lncnt = 1; // Element (first, second, third), LiNe CouNT

	/* Sets the distance of the gap, and halves it every loop until gap is
	   less than one (remember, one divided by two equals zero for integers) */
	for( gap = n / 2; gap > 0; gap /= 2 )
	{
		/* Sets the right comparison position, and shifts it to the right every
		   loop until the right position is past the right extrema. */
		for( e = gap; e < n; e++ )
		{
			/* "Looks" gap number of spaces to the left from the right
			   comparison position. If the left comparison position is at least
			   0 and the element value is greater than the element value of the
			   right comparison, then switches their values */
			/* N.B. This is essentially a glorified if-then expression */
			for( ee = e - gap; ee >= 0 && v[ ee ] > v[ ee + gap ]; ee -= gap )
			{
				temp = v[ ee ];
				v[ ee ] = v[ ee + gap ];
				v[ ee + gap ] = temp;

				/* VISUALIZE SORTING */
				printf( "%d)\t", lncnt++ ); // Step number
				/* Current array values */
				for( eee = 0; eee < n; ++eee )
				{
					printf( "%02d ", v[ eee ] ); 
				}
				printf( "\n\t" );
				/* points out switches */
				for( eee = 0; eee < n; ++eee )
				{
					if( eee == ee || eee == ee + gap )
					{
						printf( " ^ " );
					}
					else
					{
						printf( "   " );
					}
				}
				printf( "\n" );
			}
		}
	}
}

////////////////////////////////////////////////////////////////////////////////
int main( void )
{
	int c = '0', e, n = 16; // Character, element, Number of elements in rarray[]
	int rarray[ n ]; // Random nummber ARRAY

	while( c != EOF )
	{
		/* Assign--and print out--random numbers to an array */
		printf( "\nUnsorted:\n\t" );
		for( e = 0; e < n; ++e )
		{
			printf( "%02d ", rarray[ e ] = random() & ( n - 1 ) );
		}
		putchar( '\n' );

		/* Sort array */
		printf( "Sorting:\n" );
		shellsort( rarray, n );

		/* Repeat? */
		printf( "Press ENTER to see the Shell Sort in action again; press ^D to exit: " );
		c = getchar();
	}
	putchar( '\n' );

	return 0;
}
