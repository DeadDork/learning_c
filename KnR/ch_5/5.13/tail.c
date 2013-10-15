// Prints out the last n lines of a file (defaulted n = 10).

// Universal {{{
#define LINE_LENGTH_MAX 1000

#define SyncStringArrays(array_source, array_target, array_size) {\
	int element = array_size;\
	while (--element >= 0)\
		array_source[element] = array_target[element];\
}
// Universal }}}

// main {{{
#define IntializeStringArray(array, array_size) {\
	int element = array_size;\
	while (--element >= 0)\
		*array[element] = '\0';\
}

void get_tail(char *[], int);
int get_tail_length(int, char *[]);
void print_tail(char *[], int);

int main(int argc, char *argv[]) {
	int tail_length = get_tail_length(argc, argv);

	char tail_buffer[tail_length][LINE_LENGTH_MAX];
	IntializeStringArray(tail_buffer, tail_length); // Ensures sane output
	char *tail_array[tail_length]; 
	SyncStringArrays(tail_array, tail_buffer, tail_length);

	get_tail(tail_array, tail_length);
	print_tail(tail_array, tail_length);

	return 0;
}
// main }}}

// Get the length of the tail {{{
// get_tail_length() {{{
#include <stdlib.h>

#define LINE_NUMBER_MAX 5000

#define Abs(x) ((x) < 0) ? -(x) : (x)

enum match {
	NO_MATCH,
	MATCH
};

enum match is_number(char *);

int get_tail_length(int argc, char *argv[]) {
	double place_holder;
	if (argc > 1 && argv[1][0] == '-' && is_number(argv[1]) && (place_holder = Abs(atof(argv[1]))) < LINE_NUMBER_MAX)
		return (int)place_holder;
	else
		return 10;
}
// get_tail_length() }}}

// is_number() {{{
#include <ctype.h>

enum match is_number(char *character) {
	char *character_start = character;

	if (*character == '+' || *character == '-')
		++character;

	while (isdigit(*character))
		++character;

	if (character > character_start && isdigit(character[-1]) && *character == '\0')
		return MATCH;
	else
		return NO_MATCH;
}
// is_number() }}}
// Get the length of the tail }}}

// Get the tail lines {{{
// get_tail() {{{
#include <string.h>

int get_line(char *);
int shift_up(char *[], int, int);

void get_tail(char *tail_array[], int tail_length) {
	char line[LINE_LENGTH_MAX];
	char *tail_buffer_array[tail_length];
	SyncStringArrays(tail_buffer_array, tail_array, tail_length);
	int element = tail_length;

	while (get_line(line) > 0) {
		element = shift_up(tail_array, tail_length, element);
		strcpy(tail_buffer_array[element], line);
	}
}
// get_tail() }}}

// get_line() {{{
#include <stdio.h>

int get_line(char *line) {
	int character, element;
	for (element = 0; element < LINE_LENGTH_MAX - 2 && (character = getchar()) != '\n' && character != EOF; ++element)
		*line++ = character;
	*line++ = '\n';
	*line = '\0';

	return element;
}
// get_line() }}}

// shift_up() {{{
int shift_up(char *array[], int array_size, int buffer_element) {
	char *place_holder = array[array_size - 1];
	int element;

	for (element = array_size - 1; element > 0; --element)
		array[element] = array[element - 1];
	array[element] = place_holder;

	return (buffer_element < array_size - 1) ? ++buffer_element : 0;
}
// shift_up() }}}
// Get the tail lines }}}

// Print the tail buffer {{{
void print_tail(char *tail[], int tail_length) {
	int element = 0;
	while (element <tail_length)
		printf("%s", tail[element++]);
}
// Print the tail buffer }}}
