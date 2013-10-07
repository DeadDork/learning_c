// Refactored 'original' version.

#include <stdio.h>
#include <string.h>

// main() {{{
#define LINE_COUNT_MAX 5000
int read_lines(char *[]);
void string_sort(char *[], int, int);
void write_lines(char *[], int);

int main(void) {
	int line_count;
	char *line_pointer_array[LINE_COUNT_MAX];

	if ((line_count = read_lines(line_pointer_array)) >= 0) {
		string_sort(line_pointer_array, 0, line_count - 1);
		write_lines(line_pointer_array, line_count);
		return 0;
	} else {
		printf("error: input too big to sort\n");
		return 1;
	}
}
// }}}

// Read lines from input {{{
// read_lines() {{{
#define LINE_LENGTH_MAX 1000
int get_line(char *, int);
char *alloc(int);

int read_lines(char *line_pointer_array[]) {
	char line[LINE_LENGTH_MAX], *line_pointer;
	int line_length, line_count = 0;

	while (line_length = get_line(line, LINE_LENGTH_MAX)) {
		if (line_count < LINE_COUNT_MAX && (line_pointer = alloc(line_length)) != NULL) {
			strcpy(line_pointer, line);
			line_pointer_array[line_count++] = line_pointer;
		} else
			return -1; // Input too big
	}

	return line_count;
}
// }}}

// get_line() {{{
int get_line(char line[], int line_length_max) {
	int character, element;

	for (element = 0; element < line_length_max - 1 && (character = getchar()) != EOF && character != '\n'; ++element)
		line[element] = character;
	line[element] = '\0'; // I don't consider '\n' part of a line
	if (character == '\n') // To distinguish blank lines from EOF 'lines'
		++element;

	return element;
}
// }}}

// alloc() {{{
#define ALLOC_MAX LINE_COUNT_MAX * LINE_LENGTH_MAX
static char alloc_buffer[ALLOC_MAX];
static char *alloc_next_free = alloc_buffer;

char *alloc(int alloc_new) {
	if (alloc_buffer + ALLOC_MAX - alloc_next_free >= alloc_new) {
		alloc_next_free += alloc_new;
		return alloc_next_free - alloc_new;
	} else
		return NULL; // Not enough room
}
// }}}
// }}}

// Sort lines {{{
// string_sort() {{{
void char_pointer_array_swap(char *[], int, int);

void string_sort(char *string_pointer_array[], int left, int right) {
	int element, last;

	// Do nothing if array contains fewer than 2 elements
	if (left >= right)
		return;

	// Move pivot to the left
	char_pointer_array_swap(string_pointer_array, left, (left + right) / 2);

	// Organize: low left of pivot, high to right
	last = left;
	for (element = left + 1; element <= right; element++)
		if (strcmp(string_pointer_array[element], string_pointer_array[left]) < 0)
			char_pointer_array_swap(string_pointer_array, ++last, element);

	// Move pivot back to its original position
	char_pointer_array_swap(string_pointer_array, left, last);

	// Quicksort recursively to the left of pivot until fully ordered
	string_sort(string_pointer_array, left, last - 1);

	// Quicksort recursively to the right of pivot until fully ordered
	string_sort(string_pointer_array, last + 1, right);
}
// }}}

// char_pointer_array_swap() {{{
void char_pointer_array_swap(char *char_pointer_array[], int source, int target) {
	char *place_holder = char_pointer_array[source];

	char_pointer_array[source] = char_pointer_array[target];
	char_pointer_array[target] = place_holder;
}
// }}}
// }}}

// Print lines {{{
// write_lines() {{{
void write_lines(char *pointer_array[], int line_count) {
	while (line_count-- > 0)
		printf("%s\n", *pointer_array++);
}
// }}}
// }}}
