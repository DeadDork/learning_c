// Replaces a string of tabs with the spaces needed to achieve the same length,
// with the tab_stop width being set via arguments.

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

enum match {
	NO_MATCH,
	MATCH
};

enum match is_number(char *);
enum match is_tab(int);
void print_spaces(int);

int main(int argc, char *argv[]) {
	int character, tab_count = 0, tab_stop = 8;

	if (argc == 2 && is_number(argv[1]))
		tab_stop = (atoi(argv[1]) > 1) ? atoi(argv[1]) : tab_count;

	while ((character = getchar()) != EOF) {
		if (is_tab(character))
			++tab_count;
		else {
			print_spaces(tab_count * tab_stop);
			putchar(character);
			tab_count = 0;
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

enum match is_tab(int character) {
	return (character == '\t') ? MATCH : NO_MATCH;
}

void print_spaces(int space_number) {
	while (space_number-- > 0)
		putchar(' ');
}
