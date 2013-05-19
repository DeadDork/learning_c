////////////////////////////////////////////////////////////////////////////////
// Comments

// This library simplifies the use of regex.h

////////////////////////////////////////////////////////////////////////////////
// Libraries
#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include "rematch.h"

////////////////////////////////////////////////////////////////////////////////
// Functions

int rematch (char * string, char * re, size_t nmatch, regmatch_t * pmatch) {
	int re_err;
	char err_msg[MAXBUF];
	regex_t regex;
	int value;

	// Compile the regex
	if ((re_err = regcomp (&regex, re, REG_EXTENDED))) {
		fprintf (stderr, "Could not compile regex: [%s]\n", re);
		exit (1);
	}

	// Match the regex to string
	if (!(re_err = regexec (&regex, string, nmatch, pmatch, 0)))
		value = MATCH;
	else if (re_err == REG_NOMATCH)
		value = NOMATCH;
	else {
		regerror (re_err, &regex, err_msg, MAXBUF);
		fprintf (stderr, "Regex match failed: %s\n", err_msg);
		exit (1); 
	}

	regfree (&regex);

	return value;
}
