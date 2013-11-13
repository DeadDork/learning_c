// K & R's undcl program. I did some minor refactoring to get my hands dirty.

// Universal {{{
#include <stdio.h>
#include <string.h>

#define MAXTOKEN  100

enum {
	NAME,
	PARENS,
	BRACKETS
};

int tokentype;
char token[MAXTOKEN];
char datatype[MAXTOKEN];
char out[1000];
// Universal }}}

// Main {{{
int gettoken(void);

int main(void) {
	int type;
	char temp[MAXTOKEN];

	while (gettoken() != EOF) {
		strcpy(out, token);
		while ((type = gettoken()) != '\n')
			if (type == PARENS || type == BRACKETS)
				strcat(out, token);
			else if (type == '*') {
				sprintf(temp, "(*%s)", out);
				strcpy(out, temp);
			} else if (type == NAME) {
				sprintf(temp, "%s %s", token, out);
				strcpy(out, temp);
			} else
				printf("invalid input at %s\n", token);
		printf("%s\n", out);
	}

	return 0;
}
// Main }}}

// Return next token {{{
#include <ctype.h>
#include "getch_1.h"

int gettoken(void) {
	int c;
	char *p = token;

	while ((c = getch()) == ' ' || c == '\t');

	if (c == '(') {
		if ((c = getch()) == ')') {
			strcpy(token, "()");
			return tokentype = PARENS;
		} else {
			ungetch(c);
			return tokentype = '(';
		}
	} else if (c == '[') {
		for (*p++ = c; (*p++ = getch()) != ']'; );
		*p = '\0';
		return tokentype = BRACKETS;
	} else if (isalpha(c)) {
		for (*p++ = c; isalnum(c = getch()); )
			*p++ = c;
		*p = '\0';
		ungetch(c);
		return tokentype = NAME;
	} else
		return tokentype = c;
}
// Return next token }}}
