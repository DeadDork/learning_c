// Sorts lines of input.

// Optional arguments:
//// -d = directory order
//// -f = fold cases (i.e. case insensitive; default case sensitive)
//// -n = numerical comparison of strings
//// -r = reverse order
//// -s = separator (defaults to '\n')
//// $n = sort fields (up to 10; defaults to $0 [full line]; quote correcty)

// To sort lines, select the field and comparison method, and do so again for
// any sub-sorting of the previous sort, e.g.
//
//// sort '$1' -f -d '$6' -n
//
// would sort input according to case-insensitive directory order in the first
// field, and numerically by the sixth, e.g.
//
//// a z y x w 7
//// b a b c d 9
//// a a b c d 8
//// b z y x w 4
//
// would sort to
//
//// a z y x w 7
//// a a b c d 8
//// b z y x w 4
//// b a b c d 9

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_LENGTH_MAX 1000
#define LINE_NUMBER_MAX 5000
#define DEFAULT_SEPARATOR ' '

#define Case(x) ((islower((x))) ? toupper((x)) : (x))
#define IsDirectoryOrder(x) ((isalnum(x) || isspace(x)) ? TRUE : FALSE)

enum FIELDS {
	ENTIRE_LINE,
	FIRST_FIELD,
	SECOND_FIELD,
	THIRD_FIELD,
	FOURTH_FIELD,
	FIFTH_FIELD,
	SIXTH_FIELD,
	SEVENTH_FIELD,
	EIGHTH_FIELD,
	NINTH_FIELD,
	TENTH_FIELD,
	FIELDS_MAX
};

enum PROGRAM_ARGUMENTS {
	SEPARATOR,
	PROGRAM_ARGUMENTS_MAX
};

enum FIELD_ARGUMENTS {
	FIELD_STATE,
	DIRECTORY_ORDER,
	REVERSE,
	SORT,
	FIELD_ARGUMENTS_MAX
};

enum SORT_ARGUMENTS {
	LEXICOGRAPHICAL_CASE_SENSITIVE,
	LEXICOGRAPHICAL_CASE_INSENSITIVE,
	NUMERICAL,
	SORT_ARGUMENTS_MAX
};

enum BOOLEAN {
	FALSE,
	TRUE
};

char *field_pointers_array[LINE_NUMBER_MAX][FIELDS_MAX];
int program_arguments[PROGRAM_ARGUMENTS_MAX], field_arguments[FIELDS_MAX][FIELD_ARGUMENTS_MAX];

int compare(int, int, int);
void field_sort(int, int, int);
void field_swap(int, int);
void get_arguments(int, char *[]);
char *get_field_end(int, int);
int get_line(char *);
int get_next_right(int, int, int);
void initialize_field_arguments(int []);
int lexicographical_comparison(int, int, int);
int numerical_comparison(int, int, int);
int read_lines(void);
void reverse(int, int);
void sort_lines(int, int, int);
void sync_field_arguments(int [], int []);
void write_lines(int);

int main(int argc, char *argv[]) {
	get_arguments(argc, argv);

	int line_number;
	char lines_buffer[LINE_LENGTH_MAX * LINE_NUMBER_MAX];
	field_pointers_array[0][ENTIRE_LINE] = lines_buffer;
	if ((line_number = read_lines()) >= 0) {
		sort_lines(0, line_number - 1, ENTIRE_LINE);
		write_lines(line_number);
	} else
		printf("main(): too many lines in input.\n");

	return 0;
}

// Get the sort settings {{{
void get_arguments(int argc, char *argv[]) {
	program_arguments[SEPARATOR] = DEFAULT_SEPARATOR;
	int field;
	for (field = ENTIRE_LINE; field < FIELDS_MAX; ++field)
		initialize_field_arguments(field_arguments[field]);

	int temporary_field[FIELD_ARGUMENTS_MAX], field_count;
	initialize_field_arguments(temporary_field);
	for (field_count = 0, --argc; argc >= 0; --argc) {
		if (!strcmp(argv[argc], "-d"))
			temporary_field[DIRECTORY_ORDER] = TRUE;
		else if (!strcmp(argv[argc], "-r"))
			temporary_field[REVERSE] = TRUE;
		else if (!strcmp(argv[argc], "-f"))
			temporary_field[SORT] = LEXICOGRAPHICAL_CASE_INSENSITIVE;
		else if (!strcmp(argv[argc], "-n"))
			temporary_field[SORT] = NUMERICAL;
		else if (*argv[argc] == '$') {
			if ((field = atoi(argv[argc] + 1)) >= ENTIRE_LINE && field < FIELDS_MAX) {
				temporary_field[FIELD_STATE] = TRUE;
				sync_field_arguments(field_arguments[field], temporary_field);
				++field_count;
			}
			initialize_field_arguments(temporary_field);
		} else if (!strcmp(argv[argc], "-s")) {
			int separator = *argv[argc + 1];
			program_arguments[SEPARATOR] = (isprint(separator) || isspace(separator)) ? separator : DEFAULT_SEPARATOR;
		} else if (argc == 0 && field_count == 0) {
			temporary_field[FIELD_STATE] = TRUE;
			sync_field_arguments(field_arguments[ENTIRE_LINE], temporary_field);
		}
	}
}

void initialize_field_arguments(int field[]) {
	field[FIELD_STATE] = FALSE;
	field[DIRECTORY_ORDER] = FALSE;
	field[REVERSE] = FALSE;
	field[SORT] = LEXICOGRAPHICAL_CASE_SENSITIVE;
}

void sync_field_arguments(int source_field_arguments[], int target_field_arguments[]) {
	int argument;
	for (argument = FIELD_STATE; argument < FIELD_ARGUMENTS_MAX; ++argument)
		source_field_arguments[argument] = target_field_arguments[argument];
}
// Get the sort settings }}}

// Read input {{{
int read_lines(void) {
	char line[LINE_LENGTH_MAX], *line_end;
	int line_length, line_number;
	int field;
	for (line_number = 0; (line_length = get_line(line)) > 0 && line_number < LINE_NUMBER_MAX; ++line_number) {
		field_pointers_array[line_number + 1][ENTIRE_LINE] = stpcpy(field_pointers_array[line_number][ENTIRE_LINE], line) + 1;
		field_pointers_array[line_number][FIRST_FIELD] = field_pointers_array[line_number][ENTIRE_LINE];
		for (field = SECOND_FIELD; field < FIELDS_MAX; ++field)
			field_pointers_array[line_number][field] = (line_end = get_field_end(line_number, field - 1)) + (line_end != '\0');
	}

	return (line_number == LINE_NUMBER_MAX) ? -1 : line_number;
}

int get_line(char *string) {
	int character, line_length;
	for (line_length = 0; (character = getchar()) != '\n' && character != EOF && line_length < LINE_LENGTH_MAX; ++line_length)
		*string++ = character;
	*string = '\0';

	return line_length + (character == '\n');
}

char *get_next_field_pointer(int line_number, int field) {
	char *line;
	for (line = field_pointers_array[line_number][field]; *line != '\0' && *line != program_arguments[SEPARATOR]; ++line);

	return line + (*line != '\0');
}
// Read input }}}

// Sort input {{{
void sort_lines(int left, int right, int field) {
	if (left >= right || field >= FIELDS_MAX)
		return;

	if (field_arguments[field][FIELD_STATE] == FALSE)
		sort_lines(left, right, field + 1);
	else {
		field_sort(left, right, field);
		if (field_arguments[field][REVERSE] == TRUE)
			reverse(left, right);
		int current_left = left;
		int current_right = get_next_right(current_left, right, field);
		for (; current_left < right; current_left = current_right + 1, current_right = get_next_right(current_left, right, field))
			sort_lines(current_left, current_right, field + 1);
	}
}

int get_next_right(int left_extrema, int right_extrema, int field) {
	int current_right;

	for (current_right = left_extrema; current_right < right_extrema && !compare(current_right, left_extrema, field); ++current_right);

	return current_right;
}

// Sort by fields {{{
void field_sort(int left, int right, int field) {
	if (left >= right)
		return;

	int current_left = left, current_right = right - 1, pivot = right;
	while (current_left < current_right) {
		if (compare(current_left, pivot, field) <= 0) {
			++current_left;
			continue;
		} else if (compare(current_right, pivot, field) >= 0) {
			--current_right;
			continue;
		} else
			field_swap(current_left, current_right);
	}
	if (compare(current_right, pivot, field) > 0)
		field_swap(pivot, current_right);

	field_sort(left, current_right, field);
	field_sort(current_right + 1, right, field);
}

// Compare fields {{{
int compare(int source, int target, int field) {
	if (field_arguments[field][SORT] == NUMERICAL)
		return numerical_comparison(source, target, field);
	else 
		return lexicographical_comparison(source, target, field);
}

int numerical_comparison(int source, int target, int field) {
	char *source_end = get_field_end(source, field), *target_end = get_field_end(target, field);
	char temporary_source_end = *source_end, temporary_target_end = *target_end;
	*source_end = *target_end = '\0'; 
	int source_integer = atoi(field_pointers_array[source][field]), target_integer = atoi(field_pointers_array[target][field]);
	*source_end = temporary_source_end, *target_end = temporary_target_end;

	if (source_integer > target_integer)
		return 1;
	else if (source_integer < target_integer)
		return -1;
	else
		return 0;
}

int lexicographical_comparison(int source, int target, int field) {
	char *psource = field_pointers_array[source][field];
	char *ptarget = field_pointers_array[target][field];
	int separator = program_arguments[SEPARATOR];
	while (*psource != '\0' && *psource != separator && *ptarget != '\0' && *ptarget != separator) {
		if (field_arguments[field][DIRECTORY_ORDER] == TRUE && !IsDirectoryOrder(*psource)) {
				++psource;
				continue;
		}
		if (field_arguments[field][DIRECTORY_ORDER] == TRUE && !IsDirectoryOrder(*ptarget)) {
				++ptarget;
				continue;
		}

		if (field_arguments[field][SORT] == LEXICOGRAPHICAL_CASE_SENSITIVE) {
			if (*psource > *ptarget)
				return 1;
			else if (*psource < *ptarget)
				return -1;
			else {
				++psource;
				++ptarget;
			}
		} else if (field_arguments[field][SORT] == LEXICOGRAPHICAL_CASE_INSENSITIVE) {
			if (Case(*psource) > Case(*ptarget))
				return 1;
			else if (Case(*psource) < Case(*ptarget))
				return -1;
			else {
				++psource;
				++ptarget;
			}
		}
	}

	if (*psource > *ptarget)
		return 1;
	else if (*psource < *ptarget)
		return -1;
	else
		return 0;
}

char *get_field_end(int line_number, int field) {
	char *line;
	for (line = field_pointers_array[line_number][field]; *line != program_arguments[SEPARATOR] && *line != '\0'; ++line);
	return line;
}
// Compare fields }}}

void field_swap(int left, int right) {
	char *field_pointer;
	int field_element;
	for (field_element = ENTIRE_LINE; field_element < FIELDS_MAX; ++field_element) {
		field_pointer = field_pointers_array[left][field_element];
		field_pointers_array[left][field_element] = field_pointers_array[right][field_element];
		field_pointers_array[right][field_element] = field_pointer;
	}
}
// Sort by fields }}}

void reverse(int left, int right) {
	for (; left < right; ++left, --right)
		field_swap(left, right);
}
// Sort input }}}

// Write input to output {{{
void write_lines(int last_line_number) {
	int line_number;
	for (line_number = 0; line_number < last_line_number; ++line_number)
		printf("%s\n", field_pointers_array[line_number][ENTIRE_LINE]);
}
// Write input to output }}}
