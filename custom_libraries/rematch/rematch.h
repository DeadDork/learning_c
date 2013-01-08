#include <stddef.h>
#include <regex.h>

#ifndef REMATCH_H
#define REMATCH_H

#define MATCH 1
#define NOMATCH 0

int rematch( char*, char*, size_t, regmatch_t* );

#endif /* REMATCH_H */
