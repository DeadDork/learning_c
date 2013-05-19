#include <stddef.h>
#include <regex.h>

#ifndef REMATCH_H
#define REMATCH_H

#define NOMATCH 0
#define MATCH 1

#define MAXBUF 1000

int rematch (char * string, char * regex, size_t nmatch, regmatch_t * pmatch);
/* Performs an extended regular expression match on a string.
 
   `string` = The string upon which the regular expression is going to match against.

   `regex` = The regular expression string that will attempt to match against the string.

   `nmatch` = The number of elements in pmatch.

   `pmatch` = An array of regex structures: [0] the entire regex match; [1] ... [nmatch - 1]
   refers to any parenthesized substrings in the regex. Each of these is a struct that has
   the members rm_so (the Start Offset position in the string where the match begins) and
   rm_eo (the End Offset position in the string where the first non-match begins).

   Returns MATCH if there is a match; otherwise returns NOMATCH. */
   
#endif /* REMATCH_H */
