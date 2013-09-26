////////////////////////////////////////////////////////////////////////////////
// Libraries

#include "is_number.h"

////////////////////////////////////////////////////////////////////////////////
// External Variables

static regex_t re_num; // In this file because I want it static
static size_t nmatch = 1; // Only one string should match!
static regmatch_t pmatch[1]; // Ibid.

////////////////////////////////////////////////////////////////////////////////
// Functions

int is_number(char *string) {
	if (regexec(&re_num, string, nmatch, pmatch, 0) == 0)
		return MATCH;
	else
		return NO_MATCH;
}

void compile_re(void) {
	regcomp(&re_num, "^-?([1-9][0-9]+|[0-9]|([1-9][0-9]+|[0-9]?)\.[0-9]+)$", REG_EXTENDED);
}

void match_print(char *string) {
	int element;

	printf("Match string = [");
	for (element = pmatch[0].rm_so; element < pmatch[0].rm_eo; ++element)
		putchar(string[element]);
	printf("]\n");
}
