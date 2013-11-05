// Universal {{{
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_LENGTH_MAX 1000
#define LINE_NUMBER_MAX 5000

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
	FIELD_NUMBER,
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
int field_arguments[FIELDS_MAX][FIELD_ARGUMENTS_MAX];
int program_arguments[PROGRAM_ARGUMENTS_MAX];

int compare(int, int, int);
void error(char *, char *);
char *get_field_end(int, int);

// Compare fields {{{
int lexicographical_comparison(int, int, int);
int numerical_comparison(int, int, int);

int compare(int source, int target, int field) {
	if (field_arguments[field][SORT] == NUMERICAL)
		return numerical_comparison(source, target, field);
	else 
		return lexicographical_comparison(source, target, field);
}

int numerical_comparison(int source, int target, int field) {
	int field_number = field_arguments[field][FIELD_NUMBER];
	char *psource = field_pointers_array[source][field_number];
	char *ptarget = field_pointers_array[target][field_number];
	int source_integer, target_integer;

	if (field > ENTIRE_LINE) {
		char *source_end = get_field_end(source, field_number), *target_end = get_field_end(target, field_number);
		char temporary_source_end = *source_end, temporary_target_end = *target_end;
		*source_end = *target_end = '\0'; 
		source_integer = atoi(psource), target_integer = atoi(ptarget);
		*source_end = temporary_source_end, *target_end = temporary_target_end;
	} else {
		source_integer = atoi(psource);
		target_integer = atoi(ptarget);
	}

	if (source_integer > target_integer)
		return 1;
	else if (source_integer < target_integer)
		return -1;
	else
		return 0;
}

// Makes lexicographical comparisons {{{
#define Case(x) ((islower((x))) ? toupper((x)) : (x))
#define IsDirectoryOrder(x) ((isalnum(x) || isspace(x)) ? TRUE : FALSE)

int lexicographical_comparison(int source, int target, int field) {
	char *psource = field_pointers_array[source][field_arguments[field][FIELD_NUMBER]];
	char *ptarget = field_pointers_array[target][field_arguments[field][FIELD_NUMBER]];
	int separator;
	if (field > ENTIRE_LINE)
		separator = program_arguments[SEPARATOR];
	else
		separator = '\0';

	while (*psource != '\0' && *psource != separator && *ptarget != '\0' && *ptarget != separator) {
		if (field_arguments[field][DIRECTORY_ORDER] == TRUE && !IsDirectoryOrder(*psource)) {
				++psource;
				continue;
		} else if (field_arguments[field][DIRECTORY_ORDER] == TRUE && !IsDirectoryOrder(*ptarget)) {
				++ptarget;
				continue;
		} else if (field_arguments[field][SORT] == LEXICOGRAPHICAL_CASE_SENSITIVE) {
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
// Makes lexicographical comparisons }}}
// Compare fields }}}

void error(char *function, char *error_message) {
	printf("%s(): %s\n", function, error_message);
	exit(1);
}

char *get_field_end(int line_number, int field) {
	char *line;
	for (line = field_pointers_array[line_number][field]; *line != program_arguments[SEPARATOR] && *line != '\0'; ++line);
	return line;
}
// Universal }}}

// Main {{{
void get_arguments(int, char *[]);
void sort_lines(int, int, int);
int read_lines(void);
void write_lines(int);

int main(int argc, char *argv[]) {
	get_arguments(argc, argv);

	int line_number;
	char lines_buffer[LINE_LENGTH_MAX * LINE_NUMBER_MAX];
	field_pointers_array[0][ENTIRE_LINE] = lines_buffer;
	if ((line_number = read_lines()) >= 0) {
		sort_lines(0, line_number - 1, (field_arguments[ENTIRE_LINE][FIELD_STATE] == TRUE) ? ENTIRE_LINE : FIRST_FIELD);
		write_lines(line_number);
	} else
		error("main", "too many lines of input.\n");

	return 0;
}
// Main }}}

// Get settings {{{
void get_program_arguments(int, char *[]);
void get_field_arguments(int, char *[]);

void get_arguments(int argc, char *argv[]) {
	get_program_arguments(argc, argv);

	get_field_arguments(argc, argv);
}

// Get non-field program arguments {{{
#define DEFAULT_SEPARATOR ' '

void get_program_arguments(int argc, char *argv[]) {
	int argument;

	program_arguments[SEPARATOR] = DEFAULT_SEPARATOR;

	int program_argument_count[PROGRAM_ARGUMENTS_MAX];
	for (argument = 0; argument < PROGRAM_ARGUMENTS_MAX; ++argument)
		program_argument_count[argument] = 0;

	for (argument = 1, --argc; argument < argc; ++argument) {
		if (!strcmp(argv[argument], "-s")) {
			if (++program_argument_count[SEPARATOR] > 1)
				error("get_program_arguments", "Too many separators.");
			else
				program_arguments[SEPARATOR] = (isprint(*argv[argument + 1]) || *argv[argument + 1] == '\t') ? *argv[argument + 1] : DEFAULT_SEPARATOR;
		}
	}
}
// Get non-field program arguments }}}

// Get field program arguments {{{
void initialize_field_arguments(int []);
void sync_field_arguments(int [], int []);

void get_field_arguments(int argc, char *argv[]) {
	int argument, field, field_number;
	int field_argument_count[FIELD_ARGUMENTS_MAX];
	for (argument = 0; argument < FIELD_ARGUMENTS_MAX; ++argument)
		field_argument_count[argument] = 0;
	for (field = ENTIRE_LINE; field < FIELDS_MAX; ++field)
		initialize_field_arguments(field_arguments[field]);
	int temporary_field[FIELD_ARGUMENTS_MAX];
	initialize_field_arguments(temporary_field);

	for (field = ENTIRE_LINE, argument = 1; argument < argc; ++argument) {
		if (!strcmp(argv[argument], "-d")) {
			if (++field_argument_count[DIRECTORY_ORDER] > 1)
				error("get_field_arguments", "too many directory order arguments.");
			temporary_field[DIRECTORY_ORDER] = TRUE;
		} else if (!strcmp(argv[argument], "-r")) {
			if (++field_argument_count[REVERSE] > 1)
				error("get_field_arguments", "too many reverse arguments.");
			temporary_field[REVERSE] = TRUE;
		} else if (!strcmp(argv[argument], "-f")) {
			if (++field_argument_count[SORT] > 1)
				error("get_field_arguments", "too many sort arguments.");
			temporary_field[SORT] = LEXICOGRAPHICAL_CASE_INSENSITIVE;
		} else if (!strcmp(argv[argument], "-n")) {
			if (++field_argument_count[SORT] > 1)
				error("get_field_arguments", "too many sort arguments.");
			temporary_field[SORT] = NUMERICAL;
		} else if (*argv[argument] == '$') {
			if ((field_number = atoi(argv[argument] + 1)) < ENTIRE_LINE || field_number >= FIELDS_MAX || field >= FIELDS_MAX)
				error("get_field_arguments", "bad field argument.");
			temporary_field[FIELD_STATE] = FALSE;
			for (int argument = FIELD_STATE; argument < FIELD_ARGUMENTS_MAX; ++argument) {
				if (field_argument_count[argument]) {
					temporary_field[FIELD_STATE] = TRUE;
					break;
				}
			}
			sync_field_arguments(field_arguments[field++], temporary_field);
			for (int field_argument = FIELD_STATE; field_argument < FIELD_ARGUMENTS_MAX; ++field_argument)
				field_argument_count[field_argument] = 0;
			initialize_field_arguments(temporary_field);
			temporary_field[FIELD_STATE] = TRUE;
			temporary_field[FIELD_NUMBER] = field_number;
		}
	}
	temporary_field[FIELD_STATE] = TRUE;
	sync_field_arguments(field_arguments[field], temporary_field);
}

void initialize_field_arguments(int field[]) {
	field[FIELD_STATE] = FALSE;
	field[FIELD_NUMBER] = ENTIRE_LINE;
	field[DIRECTORY_ORDER] = FALSE;
	field[REVERSE] = FALSE;
	field[SORT] = LEXICOGRAPHICAL_CASE_SENSITIVE;
}

void sync_field_arguments(int source_field_arguments[], int target_field_arguments[]) {
	int argument;
	for (argument = FIELD_STATE; argument < FIELD_ARGUMENTS_MAX; ++argument)
		source_field_arguments[argument] = target_field_arguments[argument];
}
// Get field program arguments }}}
// Get the sort settings }}}

// Read input {{{
int get_line(char *);

int read_lines(void) {
	char line[LINE_LENGTH_MAX], *line_end;
	int line_length, line_number;
	int field;
	for (line_number = 0; (line_length = get_line(line)) > 0 && line_number < LINE_NUMBER_MAX; ++line_number) {
		field_pointers_array[line_number + 1][ENTIRE_LINE] = stpcpy(field_pointers_array[line_number][ENTIRE_LINE], line) + 1;
		field_pointers_array[line_number][FIRST_FIELD] = field_pointers_array[line_number][ENTIRE_LINE];
		for (field = SECOND_FIELD; field < FIELDS_MAX; ++field) {
			line_end = get_field_end(line_number, field - 1);
			field_pointers_array[line_number][field] = line_end + (*line_end != '\0');
		}
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
// Read input }}}

// Sort input {{{
void field_sort(int, int, int);
void field_swap(int, int);
int get_next_right(int, int, int);
void reverse(int, int);

void sort_lines(int left, int right, int field) {
	if (field_arguments[field][FIELD_STATE] == FALSE || left >= right || field >= FIELDS_MAX)
		return;

	field_sort(left, right, field);
	if (field_arguments[field][REVERSE] == TRUE)
		reverse(left, right);
	int current_left = left;
	int current_right = get_next_right(current_left, right, field);
	for (; current_left < right; current_left = current_right + 1, current_right = get_next_right(current_left, right, field))
		sort_lines(current_left, current_right, field + 1);
}

int get_next_right(int left, int right, int field) {
	int current_right = left;
	for (; current_right < right && !compare(current_right, left, field); ++current_right);

	return (current_right == right && !compare(current_right, left, field)) ? current_right : current_right - 1;
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
