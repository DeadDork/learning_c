////////////////////////////////////////////////////////////////////////////////
// Comments

// Tests whether heap is automatically freed at the end of a function.

// I Googled this topic after writing this program, and the consensus is that you always free memory in C.

// N.B. I pass a string constant via a pointer to a char in stringassign(). I have no idea how this works, but this is how stdio.h does it with printf().

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdlib.h>
#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
// Symbolic Constants

#define H "Hello\0"
#define G "Goodbye\0"

////////////////////////////////////////////////////////////////////////////////
// Function Prototypes

void stringassign( char * string, char * array, int arraysz );
/* Assigns a string constant to an array.
 
   *string* = The string constant that will be assigned to the character array.
   *array* = The character array.
   *arraysz* = The size of the character array. */

char * heapalloc();
/* Allocates memory in the heap.
 
   Returns the address of the pointer. */

////////////////////////////////////////////////////////////////////////////////
// Functions

void stringassign( char * string, char * carray, int carraysz )
{
	int i;

	for( i = 0; i < carraysz ; ++i )
	{
		carray[ i ] = string[ i ];
	}
}

char * heapalloc()
{
	char * ss; // String

	ss = malloc( sizeof( char ) * sizeof( H ) );
	stringassign( H, ss, sizeof( H ) );
	printf( "In heapalloc():\n\tstring = [%s]\n", ss );

	return ss;
}

////////////////////////////////////////////////////////////////////////////////
int main()
{
	char * s;

	s = heapalloc();
	printf( "In main():\n\tBefore malloc string = [%s]\n", s );

	s = malloc( sizeof( char ) * sizeof( G ) );
	stringassign( G, s, sizeof( G ) );
	printf( "\tAfter malloc string = [%s]\n", s );

	return 0;
}
