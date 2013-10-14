// Replaces a string of spaces of length n with a tab starting at column m.

// main() {{{
#include <stdio.h>

void entab(int, int, int);
int set_detab_start_column(int, char *[]);
int set_tab_stop(int, char *[]);

int main(int argc, char *argv[]) {
	int place_holder;
	int start_column = ((place_holder = set_detab_start_column(argc, argv)) > 0) ? place_holder : 0;
	int tab_stop = ((place_holder = set_tab_stop(argc, argv)) > 0) ? place_holder : 8;

	int character;
	while ((character = getchar()) != EOF)
		entab(character, start_column, tab_stop);

	return 0;
}
// main() }}}

// Get arguments {{{
// set_detab_start_column() {{{
#include <stdlib.h>

#define ArgsAssign(argc_count, argv_element, arg_sign) {\
	if (argc == argc_count && argv[argv_element][0] == arg_sign) {\
		argv[argv_element][0] = '0';\
		if (is_number(argv[argv_element]))\
			return atoi(argv[argv_element]);\
	}\
}

enum match {
	NO_MATCH,
	MATCH
};

enum match is_number(char *);

int set_detab_start_column(int argc, char *argv[]) {
	ArgsAssign(2, 1, '-');
	ArgsAssign(3, 1, '-');
	ArgsAssign(3, 2, '-');

	return 0;
}
// set_detab_start_column() }}}

int set_tab_stop(int argc, char *argv[]) {
	ArgsAssign(2, 1, '+');
	ArgsAssign(3, 1, '+');
	ArgsAssign(3, 2, '+');

	return 0;
}

// is_number() {{{
#include <ctype.h>

enum match is_number(char *character) {
	char *start_character = character;

	while (isdigit(*character))
		++character;

	return (character > start_character && isdigit(character[-1])) ? MATCH : NO_MATCH;
}
// is_number() }}}
// Get arguments }}}

// Replace spaces with tabs {{{
// entab() {{{
void print_spaces(int);

void entab(int character, int start_column, int tab_stop) {
	static int column_count, space_count;

	if ((column_count += (character == '\t') ? tab_stop : 1) >= start_column) {
		if (character == ' ') {
			if (++space_count >= tab_stop) {
				putchar('\t');
				space_count = 0;
			}
		} else {
			print_spaces(space_count);
			space_count = 0;
			putchar(character);
		}
	} else
		putchar(character);

	if (character == '\n')
		column_count = space_count = 0;
}
// entab() }}}

void print_spaces(int space_count) {
	while (space_count-- > 0)
		putchar(' ');
}
// Replace spaces with tabs }}}
