////////////////////////////////////////////////////////////////////////////////
// Comments

// Tests out the malloc function.

// From _A Little C Primer_.

// I can't get this verkakte program to ever display an error. Makes me wonder if the program is correct...

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>
#include <stdlib.h> /*For "malloc", "exit" functions. */

////////////////////////////////////////////////////////////////////////////////
int main()
{
	char* p; /*Pointer to array. */
	unsigned count; /*Size of array. */
    
	puts( "Size of array?" );
	scanf( "%d", &count ); /*Get size in bytes. */
	p = malloc( sizeof( char ) * count ); /*Allocate array. */
	if( p == NULL ) /*Check for failure. */
	{
		puts( "Can't allocate memory!" );
		exit( 1 );
	}
	puts( "Allocated array!" );
	free( p ); /*Release memory. */
	return 0;
}
