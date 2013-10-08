// Tests the speed of the new string sort program.

// Because the only real difference is in read_lines(), the test only times
// the execution of that function block.

// This test uses fopen(), fclose(), fgetc(), and clock()--all of which I
// "don't" know.

// main() {{{
#include <stdio.h>

#define LINES_COUNT_MAX 5000
#define LINE_LENGTH_MAX 1000
#define LINES_BUFFER_MAX LINES_COUNT_MAX * LINE_LENGTH_MAX
#define FEW_SMALL 0
#define FEW_LARGE 1
#define MANY_SMALL 2
#define MANY_LARGE 3

#define PrintAverageTime(x) printf(#x "_LINES = [%f]\n", average_time(test_array[(x)], line_pointer_array, lines_buffer))

double average_time(FILE *, char *[], char *);

int main(void) {
	char *line_pointer_array[LINES_COUNT_MAX];
	char lines_buffer[LINES_BUFFER_MAX];

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

int read_lines(char *[], char *, FILE *);

double average_time(FILE *test, char *line_pointer_array[], char *lines_buffer) {
	double time_start, time_stop, time_total = 0.0; // if time_* is very large

	int element;
	for (element = 0; element < ITERATIONS_MAX; ++element) {
		time_start = (double)clock();
		read_lines(line_pointer_array, lines_buffer, test);
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

int read_lines(char *line_pointer_array[], char *lines_buffer, FILE *test) {
	char line[LINE_LENGTH_MAX], *lines_buffer_start = lines_buffer;
	int line_length, lines_count = 0;

	while (line_length = get_line(line, LINE_LENGTH_MAX, test)) {
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
// }}}
