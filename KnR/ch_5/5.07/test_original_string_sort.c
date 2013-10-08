// Tests the speed of the original string sort program.

// Because the only real difference is in read_lines(), the test only times
// that function block.

// This test uses fopen(), fclose(), fgetc(), and <time.h>--all of which I
// "don't" know.

// main() {{{
#include <stdio.h>

#define LINE_COUNT_MAX 5000
#define FEW_SMALL 0
#define FEW_LARGE 1
#define MANY_SMALL 2
#define MANY_LARGE 3

#define PrintAverageTime(x) printf(#x "_LINES = [%f]\n", average_time(test_array[(x)], line_pointer_array))

double average_time(FILE *, char *[]);

int main(void) {
	char *line_pointer_array[LINE_COUNT_MAX];

	FILE *test_array[4];
	test_array[FEW_SMALL] = fopen("test_few_small_lines.asc", "r");
	test_array[FEW_LARGE] = fopen("test_few_large_lines.asc", "r");
	test_array[MANY_SMALL] = fopen("test_many_small_lines.asc", "r");
	test_array[MANY_LARGE] = fopen("test_many_large_lines.asc", "r");

	int element;
	for (element = FEW_SMALL; element <= MANY_LARGE; ++element) {
		switch (element) {
			case FEW_SMALL :
				PrintAverageTime(FEW_SMALL);
				break;
			case FEW_LARGE :
				PrintAverageTime(FEW_LARGE);
				break;
			case MANY_SMALL :
				PrintAverageTime(MANY_SMALL);
				break;
			case MANY_LARGE :
				PrintAverageTime(MANY_LARGE);
				break;
		}
	}

	fclose(test_array[FEW_SMALL]);
	fclose(test_array[FEW_LARGE]);
	fclose(test_array[MANY_SMALL]);
	fclose(test_array[MANY_LARGE]);

	return 0;
}
// }}}

// Get average execution times of read_lines() {{{
// average_time() {{{
#include <time.h>

#define ITERATIONS_MAX 1000000

int read_lines(char *[], FILE *);

double average_time(FILE *test, char *line_pointer_array[]) {
	double time_start, time_stop, time_total = 0.0;

	int element;
	for (element = 0; element < ITERATIONS_MAX; ++element) {
		time_start = (double)clock();
		read_lines(line_pointer_array, test);
		time_stop = (double)clock();
		time_total += time_stop - time_start;
	}

	return time_total;
}
// }}}

// read_lines() {{{
#include <string.h>

#define LINE_LENGTH_MAX 1000

int get_line(char *, int, FILE *);
char *alloc(int);

int read_lines(char *line_pointer_array[], FILE *test) {
	char line[LINE_LENGTH_MAX], *line_pointer;
	int line_length, line_count = 0;

	while (line_length = get_line(line, LINE_LENGTH_MAX, test)) {
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
int get_line(char line[], int line_length_max, FILE *test) {
	int character, element;

	for (element = 0; element < line_length_max - 1 && (character = fgetc(test)) != EOF && character != '\n'; ++element)
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
