// I wasn't quite sure what was expected of me in 5-18. Below is the answer
// from the K & R answer book. I figure that running it will make me
// understand.

// Conclusion: the solution is BS. I'm just going to implement my own cdcl
// with sane error handling.

// Universal {{{
#include <stdio.h>
#include <string.h>

#define MAXTOKEN  100

enum {
	NAME,
	PARENS,
	BRACKETS
};

enum {
	NO,
	YES
};

int tokentype;
char token[MAXTOKEN];
char name[MAXTOKEN];
char datatype[MAXTOKEN];
char out[1000];
int prevtoken = NO;

int gettoken(void);

// Return next token {{{
#include <ctype.h>
#include "getch_1.h"

int gettoken(void) {
	int c;
	char *p = token;

	if (prevtoken == YES) {
		prevtoken = NO;
		return tokentype;
	}

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

// Get direct declarator {{{
void errmsg(char *);

void dirdcl(void) {
	int type;

	if (tokentype == '(') {
		dcl();
		if (tokentype != ')')
			errmsg("error: missing ')'\n");
	} else if (tokentype == NAME)
		strcpy(name, token);
	else
		errmsg("error: expected name or (dcl)\n");

	while ((type=gettoken()) == PARENS || type == BRACKETS) // Doesn't need braces?!
		if (type == PARENS)
			strcat(out, " function returning");
		else {
			strcat(out, " array");
			strcat(out, token);
			strcat(out, " of");
		}
}

void errmsg(char *msg) {
	printf("%s", msg);
	prevtoken = YES;
}
// Get direct declarator }}}
// Declarator recursive-descent parser }}}
