// Replaces a string of spaces with the maximum number of tabs and the minimum
// numbers of spaces to achieve the same length, with the tab stop width being
// set via arguments.

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

enum match {
	NO_MATCH,
	MATCH
};

enum match is_number(char *);
enum match is_space(int);
void print_tabs(int);
void print_spaces(int);

int main(int argc, char *argv[]) {
	int character, space_count = 0, tab_stop = 8;

	if (argc == 2 && is_number(argv[1]))
		tab_stop = (atoi(argv[1]) > 0) ? atoi(argv[1]) : tab_stop;

	while ((character = getchar()) != EOF) {
		if (is_space(character))
			++space_count;
		else {
			print_tabs(space_count / tab_stop);
			print_spaces(space_count % tab_stop);
			putchar(character);
			space_count = 0;
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

enum match is_space(int character) {
	return (character == ' ') ? MATCH : NO_MATCH;
}

void print_tabs(int tab_number) {
	while (tab_number-- > 0)
		putchar('\t');
}

void print_spaces(int space_number) {
	while (space_number-- > 0)
		putchar(' ');
}
