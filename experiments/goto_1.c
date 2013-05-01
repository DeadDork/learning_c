////////////////////////////////////////////////////////////////////////////////
// Comments

// Explores the use of the goto function.

// I fully realize that this may be the one and only program I ever write that
// uses a goto function. K & R were rather emphatic that it is a useless
// feature.

// N.B. The code block after the goto tag is executed as if the tag wasn't
// there. Accordingly, effective use of goto requires multiple goto tags,
// otherwise undesirable tagged blocks will be executed, too.

// N.B. K & R were absolutely right about goto's easily devolving into spaghetti
// code. Yeesh!

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
int main( void )
{
	int max = 10;
	int a[ max ], aa[ max ], e, ee; // Array (1st, 2nd), Element (1st, 2nd)

	a[ 0 ] = 0;
	aa[ 0 ] = 0;
	/*
	for( e = 1; e < max; ++e )
	{
		a[ e ] = 2 * e;
		aa[ e ] = 3 * e;
	}
	*/
	for( e = 1; e < max; ++e )
	{
		a[ e ] = 31 * e;
		aa[ e ] = 13 * e;
	}

	for( e = 1; e < max; ++e )
	{
		for( ee = 1; ee < max; ++ee )
		{
			if( a[ e ] == aa[ ee ] )
			{
				goto match;
			}
			unmatch:
				;
		}
	}
	goto end;

	match:
		printf( "a[%d] = [%d]\naa[%d] = [%d]\n", e, a[ e ], ee, aa[ ee ] );
		goto unmatch;

	end:
		return 0;
}
