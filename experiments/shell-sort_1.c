////////////////////////////////////////////////////////////////////////////////
// Comments

// In K & R 3.5, the authors introduce a Shell sort. I couldn't quite follow it,
// so here is a very verbose demonstration.

// OK, I get it: it compares two values separated by n/2; if the former is
// larger than the latter, it switches their places; then it moves one space 
// left and repeats this; when the position of the latter is equal to the
// number of positions, gap is set to 1/2 of it's value; this repeats until
// gap = 1 and the latter position = the number of positions.

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

	for( gap = n / 2; gap > 0; gap /= 2 )
	{
		for( e = gap; e < n; e++ )
		{
			for( ee = e - gap; ee >= 0 && v[ ee ] > v[ ee + gap ]; ee -= gap )
			{
				temp = v[ ee ];
				v[ ee ] = v[ ee + gap ];
				v[ ee + gap ] = temp;

				/* Visualizes sorting */
				printf( "%d)\t", lncnt++ );
				for( eee = 0; eee < n; ++eee )
				{
					printf( "%02d ", v[ eee ] );
				}
				printf( "\n\t" );
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
		printf( "\nUnsorted:\n\t" );
		for( e = 0; e < n; ++e )
		{
			printf( "%02d ", rarray[ e ] = random() & n - 1 );
		}
		putchar( '\n' );

		printf( "Sorting:\n" );
		shellsort( rarray, n );

		printf( "Press ENTER to see the Shell Sort in action again; press ^D to exit: " );
		c = getchar();
	}
	putchar( '\n' );

	return 0;
}
