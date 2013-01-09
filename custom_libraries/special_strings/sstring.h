#include <stddef.h>

#ifndef SSTRING_H
#define SSTRING_H

#define TRUE 1
#define FALSE 2

////////////////////////////////////////////////////////////////////////////////
char* d_s( char* string );
/* Creates a character string of arbitary length.

   *string* = the arbitrary lengthed string.

   Returns the pointer to the arbitrary lengthed string. */
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
char* substring( char* source, int begin, int end );
/* Copies a specified substring from a string.
 
   *source* = the source string that the substring will be extracted from.
   *begin* = the start point of the substring in the string, in array notation (e.g. the first element is at position 0).
   *end* = the end point of the substring in the string, in array notiation.

   Returns the pointer to the target substring. */
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
int slength( char* string );
/* Measures the length of a string, in array notation.
 
   *string* = the source string to be measured.

   Returns the length of the string. */
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
double str2num( char* numstring );
/* Converts a string that's a human-readable number into a computer readable number.
 
   *numstring* = the source string that is to be converted into a real number.

   Returns a float of the converted number. */
////////////////////////////////////////////////////////////////////////////////

#endif /* SSTRING_H */
