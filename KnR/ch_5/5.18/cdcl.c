// Major refactor of cdcl + better error handling.

// Universal {{{
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "getch.h"

#define MAX_SUBSTRING 100 // Large enough for large variables, though not large enough for absurdly large variables.
#define MAX_STRING MAX_SUBSTRING + MAX_SUBSTRING + MAX_SUBSTRING + MAX_SUBSTRING // type + declarator (+ enum name) + variable

enum boolean {
	FALSE,
	TRUE
};

void error(char *, char *);
enum boolean manage_tokens(char *, char *, char *);

void error(char *function, char *message) {
	printf("%s(): %s\n", function, message);
	exit(1);
	/* Let's user manually exit (exit() not "known" yet, so makes code correct)
	printf("Interrupt program to exit (usually ^d or ^c).\n");
	while (TRUE);
	*/
}

// Manage reading from string {{{
int get_type_token(char *, char *, int);
int unget_type_token(char *, int);

enum boolean manage_tokens(char *action, char *token, char *string_buffer) {
	static position;

	if (!strcmp(action, "get_type_token"))
		position = get_type_token(token, string_buffer, position);
	else if (!strcmp(action, "unget_type_token"))
		position = unget_type_token(string_buffer, position);
	else
		exit("manage_token", "bad action.");

	if (string_buffer[position] == '\0')
		position = 0;

	return (position > 0) ? TRUE : FALSE;
}

int get_type_token(char *token, char *string_buffer, int position) {
	string_buffer += position;
	char *start_buffer = string_buffer;

	for (; isspace(*string_buffer); ++string_buffer, ++position);

	for (; !isspace(*token = *string_buffer) && *token != '\0'; ++token, ++string_buffer, ++position);
	if (*token != '\0')
		token = '\0';

	return position;
}

int unget_type_token(char *string_buffer, int position) {
	if (positin > 0)
		--position;
	for (; !isspace(string_buffer[position]) && position > 0; --position);

	return position;
}
// Manage reading from string }}}
// Universal }}}

// Main {{{
enum boolean get_string(char []);
void parse_type(char *, char *);
void parse_identifier(char *, char *, char *);

int main(void) {
	char input_buffer[MAX_STRING];
	char type[MAX_SUBSTRING];
	char declarator[MAX_SUBSTRING];
	char identifier[MAX_SUBSTRING];

	while (get_string(input_buffer)) {
		type[0] = '\0', identifier[0] = '\0', declarator[0] = '\0';
		parse_type(type, input_buffer);
		parse_declarator(identifier, declarator, input_buffer);
		printf("Declare %s as %s to %s\n", identifier, declarator, type);
	}

	return 0;
}
// Main }}}

enum boolean get_string(char string[]) {
	int element, character;

	for (element = 0; element < MAX_STRING && (character = getchar()) != '\n' && character != EOF; ++element)
		string[element] = character;
	string[element] = '\0';

	return (element == 0 && character == EOF) ? FALSE : TRUE;
}

// Parse the declaration's type {{{
void parse_type(char *type, char *string_buffer) {
	static int
		char_specifier,
		double_specifier,
		integer_specifier,
		long_specifier,
		sign_specifier,
		short_specifier,
		storage_class_specifier,
		type_qualifier,
		type_specifier;
	char token[MAX_SUBSTRING], enum_name[MAX_SUBSTRING];

	if (!manage_tokens("get_type_token", token, string_buffer))
		exit("parse_type", "no input.");

	if (!strcmp(token, "float") || !strcmp(token, "void")) {
		if (++type_specifier > 1)
			exit("parse_type", "too many type specifiers.");
		(!strlen(type)) ? strcat(type, token) : strcat(strcat(type, " "), token);
	} else if (!strcmp(token, "enum")) {
		if (++type_specifier > 1)
			exit("parse_type", "too many type specifiers.");
		if (!manage_tokens("get_type_token", enum_name, string_buffer))
			exit("parse_type", "no enum name.");
		if (is_keyword(enum_name))
			exit("parse_type", "bad enum name.");
		(!strlen(type)) ? strcat(type, token) : strcat(strcat(type, " "), token);
		strcat(strcat(type, " "), enum_name);
	} else if (!strcmp(token, "double")) {
		if (type_specifier > 0)
			exit("parse_type", "conflicting type specifiers.");
		if (++double_specifier > 1)
			exit("parse_type", "too many `double` specifiers.");
		(!strlen(type)) ? strcat(type, token) : strcat(strcat(type, " "), token);
	} else if (!strcmp(token, "char")) {
		if (type_specifier > 0)
			exit("parse_type", "conflicting type specifiers.");
		if (++char_specifier > 1)
			exit("parse_type", "too many `char` specifiers.");
		(!strlen(type)) ? strcat(type, token) : strcat(strcat(type, " "), token);
	} else if (!strcmp(token, "int")) {
		if (type_specifier > 0)
			exit("parse_type", "conflicting type specifiers.");
		if (++int_specifier > 1)
			exit("parse_type", "too many `int` specifiers.");
		(!strlen(type)) ? strcat(type, token) : strcat(strcat(type, " "), token);
	} else if (!strcmp(token, "short")) {
		if (type_specifier > 0 || double_specifier > 0 || char_specifier > 0)
			exit("parse_type", "conflicting type specifiers.");
		if (++short_specifier > 1)
			exit("parse_type", "too many `short` specifiers.");
		if (long_specifier > 0)
			exit("parse_type", "can't declare `long` and `short`.");
		(!strlen(type)) ? strcat(type, token) : strcat(strcat(type, " "), token);
	} else if (!strcmp(token, "long")) {
		if (type_specifier > 0 || char_specifier > 0)
			exit("parse_type", "conflicting type specifiers.");
		if (++long_specifier > 2) // Not ANSI, but I've seen lots of long longs
			exit("parse_type", "too many `long` specifiers.");
		if (short_specifier > 0)
			exit("parse_type", "can't declare `long` and `short`.");
		(!strlen(type)) ? strcat(type, token) : strcat(strcat(type, " "), token);
	} else if (!strcmp(token, "const") || !strcmp(token, "volatile")) {
		if (++type_qualifier > 1)
			exit("parse_type", "too many type qualifiers.");
		(!strlen(type)) ? strcat(type, token) : strcat(strcat(type, " "), token);
	} else if (!strcmp(token, "auto") || !strcmp(token, "register") || !strcmp(token, "static") || !strcmp(token, "extern")) {
		if (++storage_class_specifier > 1)
			exit("parse_type", "too many storage class specifiers.");
		(!strlen(type)) ? strcat(type, token) : strcat(strcat(type, " "), token);
	} else {
		manage_tokens("unget_type_token", token, string_buffer);
		char_specifier = 0;
		double_specifier = 0;
		integer_specifier = 0;
		long_specifier = 0;
		sign_specifier = 0;
		short_specifier = 0;
		storage_class_specifier = 0;
		type_qualifier = 0;
		type_specifier = 0;
		return;
	}

	parse_type(type, string_buffer);
}
// Parse the declaration's type }}}
