// Replaces a string of tabs with the spaces needed to achieve the same length,
// with the tab_stop width being set via arguments.

// Additionally, the user can set where detabment begins, as well as the tab
// stop, such that `detab -m +n` will begin detabment at column `m` and tab stop
// is `n`.

// There is a bit of trickiness: what if the tab stop & detabbing column don't
// align? I solved this problem by "rounding down" tabs.

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

enum match {
	NO_MATCH,
	MATCH
};

enum match is_number(char *);
void print_spaces(int);
void print_tabs(int);

int main(int argc, char *argv[]) {
	int character, column_count = 0, column_start = 0, tab_stop = 8;

	if (argc == 2 && argv[1][0] == '+') {
		// Set tab stop
		argv[1][0] = '0';
		if (is_number(argv[1]))
			tab_stop = (atoi(argv[1]) > 1) ? atoi(argv[1]) : tab_stop;
	} else if (argc == 3 && argv[1][0] == '-' && argv[2][0] == '+') {
		// Set detabbing start column
		argv[1][0] = '0';
		if (is_number(argv[1]))
			column_start = (atoi(argv[1]) > 0) ? atoi(argv[1]) : column_start;
		// Set tab stop
		argv[2][0] = '0';
		if (is_number(argv[2]))
			tab_stop = (atoi(argv[2]) > 1) ? atoi(argv[2]) : tab_stop;
	}

	while ((character = getchar()) != EOF) {
		if (column_count < column_start) {
			if (character == '\t')
				column_count += tab_stop;
			else
				++column_count;

			if (column_count <= column_start)
				putchar(character);
		} else {
			if (character == '\t')
				print_spaces(tab_stop);
			else
				putchar(character);

			if (character == '\n')
				column_count = 0;
		}
	}

	return 0;
}

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

void print_tabs(int tab_number) {
	while (tab_number-- > 0)
		putchar('\t');
}
