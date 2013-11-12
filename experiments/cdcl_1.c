// This is the cdcl program from K & R. I've refactored it a bit to get my
// hands dirty.

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
char name[MAXTOKEN];
char datatype[MAXTOKEN];
char out[1000];

int gettoken(void);

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
// Universal }}}

// Main {{{
void dcl(void);

int main(void) {
	while (gettoken() != EOF) {
		strcpy(datatype, token);
		out[0] = '\0';
		dcl();
		if (tokentype != '\n')
			printf("syntax error\n");
		printf("%s: %s %s\n", name, out, datatype);
	}

	return 0;
}
// Main }}}

// Declarator recursive-descent parser {{{
void dirdcl(void);
 
void dcl(void) {
	int ns;
	for (ns = 0; gettoken() == '*'; ++ns);

	dirdcl();

	while (ns-- > 0)
		strcat(out, " pointer to");
}

void dirdcl(void) {
	int type;

	if (tokentype == '(') {
		dcl();
		if (tokentype != ')')
			printf("error: missing )\n");
	} else if (tokentype == NAME)
		strcpy(name, token);
	else
		printf("error: expected name or (dcl)\n");

	while ((type=gettoken()) == PARENS || type == BRACKETS) // Doesn't need braces?!
		if (type == PARENS)
			strcat(out, " function returning");
		else {
			strcat(out, " array");
			strcat(out, token);
			strcat(out, " of");
		}
}
// Declarator recursive-descent parser }}}
