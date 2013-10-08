// string_sort() demo w/o alloc().

// N.B. Initially I tried to do away with LINE_LENGTH_MAX, but setting even two
// char buffers to LINE_BUFFER_MAX led to a segfault.

// main() {{{
#include <stdio.h>

#define LINES_COUNT_MAX 5000
#define LINE_LENGTH_MAX 1000
#define LINES_BUFFER_MAX LINES_COUNT_MAX * LINE_LENGTH_MAX

int read_lines(char *[], char *);
void string_sort(char *[], int, int);
void write_lines(char *[], int);

int main(void) {
	int lines_count;
	char *line_pointer_array[LINES_COUNT_MAX];
	char lines_buffer[LINES_BUFFER_MAX];

	if ((lines_count = read_lines(line_pointer_array, lines_buffer)) >= 0) {
		string_sort(line_pointer_array, 0, lines_count - 1);
		write_lines(line_pointer_array, lines_count);
		return 0;
	} else {
		printf("error: input too big to sort\n");
		return 1;
	}
}
// }}}

// Read lines from input {{{
// read_lines() {{{
#include <string.h>

int get_line(char *, int);

int read_lines(char *line_pointer_array[], char *lines_buffer) {
	char line[LINE_LENGTH_MAX], *lines_buffer_start = lines_buffer;
	int line_length, lines_count = 0;

	while (line_length = get_line(line, LINE_LENGTH_MAX)) {
		if (lines_count < LINES_COUNT_MAX && lines_buffer_start + LINES_BUFFER_MAX > lines_buffer + line_length) {
			line_pointer_array[lines_count++] = lines_buffer;
			lines_buffer = stpcpy(lines_buffer, line);
			++lines_buffer; // Otherwise error: lvalue required as left operand of assignment
		} else
			return -1; // Input too big
	}

	return lines_count;
}
// }}}

// get_line() {{{
int get_line(char *line, int line_length_max) {
	int character, element;

	for (element = 0; element < line_length_max - 1 && (character = getchar()) != EOF && character != '\n'; ++element)
		*line++ = character;
	*line = '\0'; // I don't consider '\n' part of a line
	if (character == '\n') // To distinguish blank lines from EOF 'lines'
		++element;

	return element;
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
void write_lines(char *pointer_array[], int lines_count) {
	while (lines_count-- > 0)
		printf("%s\n", *pointer_array++);
}
// }}}
// }}}
