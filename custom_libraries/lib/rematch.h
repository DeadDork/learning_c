#include <stddef.h>
#include <regex.h>

#ifndef REMATCH_H
#define REMATCH_H

#define MATCH 1
#define NOMATCH 0
#define MAXBUF 1000

int rematch( char* string, char* regex, size_t nmatch, regmatch_t* pmatch );
/* Performs an extended regular expression match on a string.
 
   `string` = the string upon which the regular expression is going to match against.
   `regex` = the regular expression string that will attempt to match against the string.
   `nmatch` = the number of elements in pmatch.
   `pmatch` = an array of regex structures: [0] the entire regex match; [1] ... [nmatch - 1] refers to any parenthesized substrings in the regex. Each of these is a struct that has the members rm_so (the Start Offset position in the string where the match begins) and rm_eo (the End Offset position in the string where the first non-match begins).

   Returns the value of whether there was a match (return value of 1) or there was no match (return value of 0).
   
   N.B. I barely understand nmatch & pmatch. The regex library bears further investigation. */

#endif /* REMATCH_H */
