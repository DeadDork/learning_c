////////////////////////////////////////////////////////////////////////////////
// Comments

// Solution to exercise 2-1.

// N.B. My system uses the i386 limits.h, found in </usr/include/i386/limits.h>.

// N.B. My system does not seem to have a <float.h>...

// N.B. I can't figure out a way to determine the min/max of float and double.

// N.B. It would be better to use macros for the *_range functions, but I'm not
	// "there" yet.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>
#include <limits.h>

////////////////////////////////////////////////////////////////////////////////
// Function Prototypes

void printsh( char name[], signed long min, unsigned long max );
/* Prints the signed minimum and the unsigned maximum values of a given type.
 
   `name[]` = The name of the type.

   `min` = The minimum value of the type.

   `max` = The maximum value of the type. */

void char_range( void );
/* Prints out the char unsigned maximum and signed minimum. */

void short_range( void );
/* Prints out the char unsigned maximum and signed minimum. */

void int_range( void );
/* Prints out the char unsigned maximum and signed minimum. */

void long_range( void );
/* Prints out the char unsigned maximum and signed minimum. */

////////////////////////////////////////////////////////////////////////////////
// Functions

void printsh( char name[], signed long min, unsigned long max )
{
	printf( "\t%s:\n", name );
	printf( "\t\tSigned minimum = %ld\n", min );
	printf( "\t\tUnsigned maximum = %lu\n", max );
}

void char_range( void )
{
	unsigned char max = -1; // MAXimum
	signed char min = ( max - 1 ) / 2 + 1; // MINimum

	printf( "\tchar:\n" );
	printf( "\t\tSigned minimum = %d\n", min );
	printf( "\t\tUnsigned maximum = %u\n", max );
}

void short_range( void )
{
	unsigned short max = -1; // MAXimum
	signed short min = ( max - 1 ) / 2 + 1; // MINimum

	printf( "\tshort:\n" );
	printf( "\t\tSigned minimum = %d\n", min );
	printf( "\t\tUnsigned maximum = %u\n", max );
}

void int_range( void )
{
	unsigned int max = -1; // MAXimum
	signed int min = ( max - 1 ) / 2 + 1; // MINimum

	printf( "\tint:\n" );
	printf( "\t\tSigned minimum = %d\n", min );
	printf( "\t\tUnsigned maximum = %u\n", max );
}

void long_range( void )
{
	unsigned long max = -1; // MAXimum
	signed long min = ( max - 1 ) / 2 + 1; // MINimum

	printf( "\tlong:\n" );
	printf( "\t\tSigned minimum = %ld\n", min );
	printf( "\t\tUnsigned maximum = %lu\n", max );
}

////////////////////////////////////////////////////////////////////////////////
int main( void )
{
	printf( "From standard headers:\n" );
	printsh( "char", SCHAR_MIN, UCHAR_MAX );
	printsh( "short", SHRT_MIN, USHRT_MAX );
	printsh( "int", INT_MIN, UINT_MAX );
	printsh( "long", LONG_MIN, ULONG_MAX );

	printf( "\nBy direct computation:\n" );
	char_range();
	short_range();
	int_range();
	long_range();

	return 0;
}
