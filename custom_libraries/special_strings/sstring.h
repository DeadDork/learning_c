#include <stddef.h>

#ifndef CSTRING_H
#define CSTRING_H

////////////////////////////////////////////////////////////////////////////////
char* substring( char* source, int begin, int end );
/* Copies a specified substring from a string.
 
   *source* = the source string that the substring will be extracted from.
   *begin* = the start point of the substring in the string, in array notation (e.g. the first element is at position 0).
   *end* = the end point of the substring in the string, in array notiation.

   Returns the pointer to the target substring. */
////////////////////////////////////////////////////////////////////////////////

#endif /* CSTRING_H */
