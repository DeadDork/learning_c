#include <stddef.h>

#ifndef SSTRING_H
#define SSTRING_H

#define TRUE 1
#define FALSE 2

#define BUFSZ 1000 // BUFfer SiZe
#define MAXBUF 1000 // MAXimum BUFfer size

////////////////////////////////////////////////////////////////////////////////
char * d_s( char * string );
/* Creates a character string of arbitary length.

   `string` = The arbitrarily lengthed string.

   Returns the pointer to the arbitrary lengthed string.
   
   N.B. There are limitations to the size of the dynamic character array: 1) physical memory 2) register size.
   
   N.B. This is not a safe function, such that it CAN completely eat up all of the system's memory if there is a memory leak.
   
   N.B. DON'T FORGET TO FREE UP THE MEMORY!!! */
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
int slength( char * string );
/* Measures the length of a string, in array notation.
 
   `string` = The source string to be measured.

   Returns the length of the string. */
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
char * substring( char * source, int begin, int end );
/* Slices a substring from a string.
 
   `source` = The source string that the substring will be extracted from.
   `begin` = The start point of the substring in the string, in array notation (e.g. the first element is at position 0).
   `end` = The end point of the substring in the string, in array notiation.

   Returns the pointer to the target substring.

   N.B. DON'T FORGET TO FREE UP THE MEMORY!!! */
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
double str2num( char * numstring );
/* Converts a string that's a human-readable number into a computer readable number.
 
   `numstring` = The source string that is to be converted into a real number.

   Returns a float of the converted number. */
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
char * sub( char * source, char * substitute, int start, int stop );
/* Substitutes the substring from `start` to `stop` in string `source` with string `substitute`.
   
   `source` = the source string that will have a substring substituted within.
   `substitute` = the string that will substitute the substring within source.
   `start` = the array element in `source` corresponding to the first character of the substring to be substituted, in array notation.
   `stop` = the array element in `source` corresponding to the last character of the substring to be substituted, in array notation.

   Returns the pointer of the new string.

   N.B. `stop` is equal to the last element in the substring + 1.

   N.B. `res` comes from 'Regular Expression Substitution'. The idea is to use `rematch` to get `start` & `stop` on `source`. */
////////////////////////////////////////////////////////////////////////////////

#endif /* SSTRING_H */
