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
char *get_field_end(int, int);

// Compare fields {{{
int lexicographical_comparison(int, int, int);
int numerical_comparison(int, int, int);

int compare(int source, int target, int field) {
	field = field_arguments[field][FIELD_NUMBER];
	if (field_arguments[field][SORT] == NUMERICAL)
		return numerical_comparison(source, target, field);
	else 
		return lexicographical_comparison(source, target, field);
}

int numerical_comparison(int source, int target, int field) {
	char *psource = field_pointers_array[source][field];
	char *ptarget = field_pointers_array[target][field];
	int source_integer, target_integer;

	if (field > ENTIRE_LINE) {
		char *source_end = get_field_end(source, field), *target_end = get_field_end(target, field);
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
	char *psource = field_pointers_array[source][field];
	char *ptarget = field_pointers_array[target][field];
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
		printf("main(): too many lines in input.\n");

	return 0;
}
// Main }}}

// Get settings {{{
void get_program_arguments(int, char *[]);
void get_field_arguments(int, char *[]);
void bad_argument(void);

void get_arguments(int argc, char *argv[]) {
	get_program_arguments(argc, argv);

	get_field_arguments(argc, argv);
}

void bad_argument(void) {
	printf("Usage:\n\tsort [-s DELIMITER] [-f] [-r] [-n] [-d] [$FIELD_NUMBER] [-frnd] ... [FILE_STREAM]\n");
	exit(1); // Yes, yes, I don't "know" this function yet
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
				bad_argument();
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
	int temporary_field[FIELD_ARGUMENTS_MAX];
	initialize_field_arguments(temporary_field);

	for (field = ENTIRE_LINE; field < FIELDS_MAX; ++field)
		initialize_field_arguments(field_arguments[field]);

	for (field = ENTIRE_LINE, argument = 1; argument < argc; ++argument) {
		if (!strcmp(argv[argument], "-d")) {
			if (++field_argument_count[DIRECTORY_ORDER] > 1)
				bad_argument();
			temporary_field[DIRECTORY_ORDER] = TRUE;
		} else if (!strcmp(argv[argument], "-r")) {
			if (++field_argument_count[REVERSE] > 1)
				bad_argument();
			temporary_field[REVERSE] = TRUE;
		} else if (!strcmp(argv[argument], "-f")) {
			if (++field_argument_count[SORT] > 1)
				bad_argument();
			temporary_field[SORT] = LEXICOGRAPHICAL_CASE_INSENSITIVE;
		} else if (!strcmp(argv[argument], "-n")) {
			if (++field_argument_count[SORT] > 1)
				bad_argument();
			temporary_field[SORT] = NUMERICAL;
		} else if (*argv[argument] == '$') {
			if ((field_number = atoi(argv[argument] + 1)) >= ENTIRE_LINE && field_number < FIELDS_MAX)
				temporary_field[FIELD_NUMBER] = field_number;
			else if (field_number < ENTIRE_LINE || field_number >= FIELDS_MAX || ++field_argument_count[FIELD_NUMBER] > 1 || field >= FIELDS_MAX)
				bad_argument();
			temporary_field[FIELD_STATE] = (argument > 1) ? TRUE : FALSE; // sort $n should not activate $0
			sync_field_arguments(field_arguments[field], temporary_field);
			initialize_field_arguments(temporary_field);
			for (int field = FIELD_STATE; field < FIELD_ARGUMENTS_MAX; ++field)
				field_argument_count[field] = 0;
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
	int current_right;

	for (current_right = left; current_right < right && !compare(current_right, left, field); ++current_right);

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
