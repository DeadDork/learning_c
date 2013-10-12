// Replaces tabs with spaces.

// Solves the problem of a detab start column not aligning well with tabstop by
// "rounding" up tabstops.

// N.B. Demonstrates the design idea of begining with a broad-level main()
// makes for a much clearer program.

// main() {{{
#include <stdio.h>

void detab(int, int, int);
int set_detab_start_column(int, char *[]);
int set_tabstop(int, char *[]);

int main(int argc, char *argv[]) {
	int place_holder;
	int column_start = ((place_holder = set_detab_start_column(argc, argv)) > 0) ? place_holder : 0;
	int tabstop = ((place_holder = set_tabstop(argc, argv)) > 0) ? place_holder : 8;

	int character;
	while ((character = getchar()) != EOF)
		detab(column_start, tabstop, character);

	return 0;
}
// }}}

// detab() {{{
void print_spaces(int);

void detab(int column_start, int tabstop, int character) {
	static int column_count;
	int tab_space;

	if (character == '\t') {
		tab_space = tabstop - column_count % tabstop;
		column_count += tab_space;
		if (column_count < column_start)
			putchar(character);
		else if (column_count - tab_space < column_start)
			print_spaces(tab_space);
		else
			print_spaces(tab_space);
	} else {
		putchar(character);
		++column_count;
	}

	if (character == '\n')
		column_count = 0;
}
// detab() }}}

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

int set_tabstop(int argc, char *argv[]) {
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

void print_spaces(int space_number) {
	while (space_number-- > 0)
		putchar(' ');
}
