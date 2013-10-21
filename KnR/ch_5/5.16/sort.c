// Sorts lines of input.

// Optional arguments:
//// -r = reverse order
//// -n = numerical comparison of strings
//// -f = case insensitive
//// -d = directory order

// Universal {{{
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#define LINE_NUMBER_MAX 5000
#define LINE_LENGTH_MAX 1000
#define FALSE 0
#define TRUE 1

// Flags {{{
enum Flag {
	REVERSE,
	SORT,
	DIRECTORY_ORDER
};

enum Sort {
	LEXICOGRAPHIC_CASE_SENSITIVE,
	LEXICOGRAPHIC_CASE_INSENSITIVE,
	NUMERIC
};
// Flags }}}

int numcmp(char *, char *);
// Universal }}}

// main {{{
#define BUFFER_MAX LINE_NUMBER_MAX * LINE_LENGTH_MAX
#define FLAG_NUMBER 3

void get_args(int, char *[], int []);
int read_lines(char *[]);
void sort_lines(char *[], int, int, int []);
void print_lines(char *[], int, int []);

int main(int argc, char *argv[]) {
	int flags[FLAG_NUMBER];
	flags[SORT] = LEXICOGRAPHIC_CASE_SENSITIVE;
	flags[REVERSE] = FALSE;
	flags[DIRECTORY_ORDER] = FALSE;
	get_args(argc, argv, flags);

	int line_number;
	char line_buffer[BUFFER_MAX];
	char *line_pointer_array[LINE_NUMBER_MAX];
	line_pointer_array[0] = line_buffer;

	if ((line_number = read_lines(line_pointer_array)) >= 0) {
		sort_lines(line_pointer_array, 0, line_number - 1, flags);
		print_lines(line_pointer_array, line_number, flags);
	} else
		printf("error: too many lines.\n");

	return 0;
}
// main }}}

// Get arguments {{{
void get_args(int argc, char *argv[], int flags[]) {
	if (argc > 1) {
		while (--argc) {
			if (!strcmp(argv[argc], "-n"))
				flags[SORT] = NUMERIC;
			else if (!strcmp(argv[argc], "-f"))
				flags[SORT] = LEXICOGRAPHIC_CASE_INSENSITIVE;
			else if (!strcmp(argv[argc], "-r"))
				flags[REVERSE] = TRUE;
			else if (!strcmp(argv[argc], "-d"))
				flags[DIRECTORY_ORDER] = TRUE;
		}
	}
}
// Get arguments }}}

// Read lines from input {{{
int get_line(char *);

int read_lines(char *line_pointer_array[]) {
	char line[LINE_LENGTH_MAX], *line_pointer = line_pointer_array[0];
	int line_length, line_number = 0;

	while ((line_length = get_line(line)) > 0 && line_number < LINE_NUMBER_MAX)
		line_pointer = line_pointer_array[++line_number] = stpcpy(line_pointer, line) + 1;

	return (line_number < LINE_NUMBER_MAX) ? line_number : -1;
}

int get_line(char *line) {
	int character, line_length;

	for (line_length = 0; (character = getchar()) != '\n' && character != EOF && line_length < LINE_LENGTH_MAX; ++line_length)
		*line++ = character;
	*line = '\0';

	return line_length += (character == '\n') ? 1 : 0;
}
// Read lines from input }}}

// Sort lines {{{
int cmp(char *, char *, int []);
void swap(void *[], int, int);

void sort_lines(char *line_pointer_array[], int left, int right, int flags[]) {
	if (left >= right)
		return;

	int current_left = left, current_right = right - 1, pivot = right;
	while (current_left < current_right) {
		if (cmp(line_pointer_array[current_left], line_pointer_array[pivot], flags) <= 0) {
			++current_left;
			continue;
		} else if (cmp(line_pointer_array[current_right], line_pointer_array[pivot], flags) >= 0) {
			--current_right;
			continue;
		} else
			swap(line_pointer_array, current_left, current_right);
	}
	if (cmp(line_pointer_array[current_right], line_pointer_array[pivot], flags) > 0)
		swap(line_pointer_array, pivot, current_right);

	sort_lines(line_pointer_array, left, current_right, flags);
	sort_lines(line_pointer_array, current_right + 1, right, flags);
}

// Comparisons {{{
#include <ctype.h>

#define Case(x) ((islower((x))) ? toupper((x)) : (x))

int is_directory_order(char);

int cmp(char *source, char *target, int flags[]) {
	while (*source != '\0' && *target != '\0') {
		if (flags[DIRECTORY_ORDER] == TRUE) {
			if (!is_directory_order(*source) || !is_directory_order(*target)) {
				if (!is_directory_order(*source))
					++source;
				if (!is_directory_order(*target))
					++target;
				continue;
			}
		}

		if (flags[SORT] == LEXICOGRAPHIC_CASE_SENSITIVE) {
			if (*source > *target)
				return 1;
			else if (*source < *target)
				return -1;
			else {
				++source;
				++target;
			}
		} else if (flags[SORT] == LEXICOGRAPHIC_CASE_INSENSITIVE) {
			if (Case(*source) > Case(*target))
				return 1;
			else if (Case(*source) < Case(*target))
				return -1;
			else {
				++source;
				++target;
			}
		}
	}

	if (*source > *target)
		return 1;
	else if (*source < *target)
		return -1;
	else
		return 0;
}

int is_directory_order(char character) {
	return (isalnum(character) || isspace(character)) ? TRUE : FALSE;
}
// Comparisons }}}

void swap(void *vector[], int source, int target) {
	void *place_holder = vector[source];
	vector[source] = vector[target];
	vector[target] = place_holder;
}
// Sort lines }}}

// Print sorted lines {{{
void print_lines(char *lines[], int lines_number, int flags[]) {
	if (flags[REVERSE])
		while (--lines_number > 0)
			printf("%s\n", lines[lines_number]);
	else if (flags[REVERSE] == FALSE) {
		int element;
		for (element = 0; element < lines_number; ++element)
			printf("%s\n", lines[element]);
	}
}
// Print sorted lines }}}

// Number comparison {{{
int numcmp(char *string_source, char *string_target) {
	double value_source, value_target;

	value_source = atof(string_source);
	value_target = atof(string_target);

	if (value_source < value_target)
		return -1;
	else if (value_source > value_target)
		return 1;
	else
		return 0;
}
// Number comparison }}}
