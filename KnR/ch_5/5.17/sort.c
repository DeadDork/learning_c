// Universal {{{
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_LENGTH_MAX 1000
#define LINE_NUMBER_MAX 5000
#define FIRST_ARGUMENT 1

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
	END_FIELDS
};

enum PROGRAM_ARGUMENTS {
	SEPARATOR,
	END_PROGRAM_ARGUMENTS
};

enum FIELD_ARGUMENTS {
	FIELD_STATE,
	FIELD_NUMBER,
	DIRECTORY_ORDER,
	REVERSE,
	SORT,
	END_FIELD_ARGUMENTS
};

enum SORT_ARGUMENTS {
	LEXICOGRAPHICAL_CASE_SENSITIVE,
	LEXICOGRAPHICAL_CASE_INSENSITIVE,
	NUMERICAL,
	END_SORT_ARGUMENTS
};
 
enum BOOLEAN {
	FALSE,
	TRUE
};

char *field_pointers_array[LINE_NUMBER_MAX][END_FIELDS];
int field_arguments[END_FIELDS][END_FIELD_ARGUMENTS];
int program_arguments[END_PROGRAM_ARGUMENTS];

int compare(int, int, int);
void error(char *, char *);
void initialize_count_array(int [], int);

// Compare fields {{{
int lexicographical_comparison(int, int, int);
int numerical_comparison(int, int, int);

int compare(int source, int target, int field) {
	if (field_arguments[field][SORT] == NUMERICAL)
		return numerical_comparison(source, target, field);
	else 
		return lexicographical_comparison(source, target, field);
}

// Compare two strings numerically {{{
char *get_field_end(int, int);

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

char *get_field_end(int line_number, int field) {
	char *line = field_pointers_array[line_number][field];
	for (; *line != program_arguments[SEPARATOR] && *line != '\0'; ++line);

	return line;
}
// Compare two strings numerically }}}

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

void error(char *function, char *error_message) {
	printf("%s(): %s\n", function, error_message);
	exit(1);
}

void initialize_count_array(int count_array[], int max_count) {
	for (int count = 0; count < max_count; ++count)
		count_array[count] = 0;
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
		error("main", "too many lines of input.");

	return 0;
}
// Main }}}

// Get settings {{{
void parse_arguments(int, char *[]);
void compile_arguments(int, char *[]);

void get_arguments(int argc, char *argv[]) {
	parse_arguments(argc, argv);
	compile_arguments(argc, argv);
}

// Parse the arg's {{{
void parse_program_arguments(int, char *[]);
void parse_field_arguments(int, char *[]);

void parse_arguments(int argc, char *argv[]) {
	parse_program_arguments(argc, argv);
	parse_field_arguments(argc, argv);
}

void parse_program_arguments(int argc, char *argv[]) {
	int program_argument_count[END_PROGRAM_ARGUMENTS - SEPARATOR] = {/*-s*/ 0};

	int argument = argc;
	while (--argument > 0) {
		if (!strcmp(argv[argument], "-s")) {
			if (++program_argument_count[0] > 1)
				error("parse_program_argument_counts", "too many [-s]'s.");
			if (argument == argc - 1 || strlen(argv[argument]) > 1 || !isprint(*argv[argument]) || *argv[argument] != '\t')
				error("parse_program_argument_counts", "bad [-s] assignment.");
		}
	}
}

void parse_field_arguments(int argc, char *argv[]) {
	int field_arguments_count[4] = { /*-d*/ 0, /*-[fn]*/ 0, /*-r*/ 0, /*$x*/ 0};

	for (int argument = 1; argument < argc; ++argument) {
		field_arguments_count[0] = 0;
		field_arguments_count[1] = 0;
		field_arguments_count[2] = 0;

		for (; argument < argc && argv[argument][0] != '$'; ++argument) {
			if (!strcmp(argv[argument], "-d")) {
				if (++field_arguments_count[0] > 1)
					error("parse_field_sentences", "Too many -d's");
			} else if (!strcmp(argv[argument], "-f") || !strcmp(argv[argument], "-n")) {
				if (++field_arguments_count[1] > 1)
					error("parse_field_sentences", "Too many sort arguments (-f or -n)");
			} else if (!strcmp(argv[argument], "-r")) {
				if (++field_arguments_count[2] > 1)
					error("parse_field_sentences", "Too many -r's");
			}
		}
		if (argv[argument -= (argument == argc) ? 1 : 0][0] == '$') {
			if (++field_arguments_count[3] > END_FIELDS)
				error("parse_field_sentences", "Too many search fields.");

			int field_number = atoi(argv[argument] + 1);
			if (argv[argument][1] != '0' && field_number <= 0)
				error("parse_field_sentences", "Bad field number.");
		}
	}
}
// Parse the arg's }}}

// Assign to program_arguments & field_arguments {{{
void initialize_field(int []);
void sync_fields(int [], int []);

void compile_arguments(int argc, char *argv[]) {
	program_arguments[SEPARATOR] = ' ';

	int field_number_max = 0;
	for (int argument = 1; argument < argc; ++argument) 
		if (argv[argument][0] == '$')
			++field_number_max;

	int temporary_field_arguments[END_FIELD_ARGUMENTS];
	initialize_field(temporary_field_arguments);

	int argument = argc;
	while (--argument > 0) {
		if (!strcmp(argv[argument], "-d"))
			temporary_field_arguments[DIRECTORY_ORDER] = TRUE;
		else if (!strcmp(argv[argument], "-f"))
			temporary_field_arguments[SORT] = LEXICOGRAPHICAL_CASE_INSENSITIVE;
		else if (!strcmp(argv[argument], "-n"))
			temporary_field_arguments[SORT] = NUMERICAL;
		else if (!strcmp(argv[argument], "-r"))
			temporary_field_arguments[REVERSE] = TRUE;
		else if (!strcmp(argv[argument], "-s"))
			program_arguments[SEPARATOR] = *argv[argument + 1];
		else if (*argv[argument] == '$') {
			temporary_field_arguments[FIELD_STATE] = TRUE;
			temporary_field_arguments[FIELD_NUMBER] = atoi(argv[argument] + 1);
			sync_fields(field_arguments[field_number_max--], temporary_field_arguments);
			initialize_field(temporary_field_arguments);
		}
	}
	temporary_field_arguments[FIELD_STATE] = (argc == 1 || (argc > 1 && argv[1][0] != '$')) ? TRUE : FALSE; // e.g. "./sort -f $5 <file" or "./sort <file"
	temporary_field_arguments[FIELD_NUMBER] = ENTIRE_LINE;
	sync_fields(field_arguments[field_number_max], temporary_field_arguments);
}

void initialize_field(int field[]) {
	field[FIELD_STATE] = FALSE;
	field[FIELD_NUMBER] = ENTIRE_LINE;
	field[DIRECTORY_ORDER] = FALSE;
	field[REVERSE] = FALSE;
	field[SORT] = LEXICOGRAPHICAL_CASE_SENSITIVE;
}

void sync_fields(int source[], int target[]) {
	for (int argument = FIELD_STATE; argument < END_FIELD_ARGUMENTS; ++argument)
		source[argument] = target[argument];
}
// Assign to program_arguments & field_arguments }}}
// Get the settings }}}

// Read input {{{
int get_line(char *);
char *get_field(int, int);

int read_lines(void) {
	char line[LINE_LENGTH_MAX];
	int line_length, line_number;

	int field = (field_arguments[ENTIRE_LINE][FIELD_STATE] == TRUE) ? ENTIRE_LINE : FIRST_FIELD;
	for (; field < END_FIELD_ARGUMENTS && field_arguments[field][FIELD_STATE] != FALSE; ++field);
	int last_field = field - 1;

	for (line_number = 0; (line_length = get_line(line)) > 0 && line_number < LINE_NUMBER_MAX; ++line_number) {
		field_pointers_array[line_number + 1][ENTIRE_LINE] = stpcpy(field_pointers_array[line_number][ENTIRE_LINE], line) + 1;
		for (field = FIRST_FIELD; field <= last_field; ++field)
			field_pointers_array[line_number][field] = get_field(line_number, field);
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

char *get_field(int line_number, int field) {
	char *line = field_pointers_array[line_number][ENTIRE_LINE];
	int separator = program_arguments[SEPARATOR];

	for (int field_number_current = 1; field_number_current < field_arguments[field][FIELD_NUMBER]; ++field_number_current) {
		for (; *line != separator && *line != '\0'; ++line);
		line += (*line != '\0');
	}

	return line;
}
// Read input }}}

// Sort input {{{
void field_sort(int, int, int);
void field_swap(int, int);
int get_next_right(int, int, int);
void reverse(int, int);

void sort_lines(int left, int right, int field) {
	if (field_arguments[field][FIELD_STATE] == FALSE || left >= right || field >= END_FIELDS)
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
	for (field_element = ENTIRE_LINE; field_element < END_FIELDS; ++field_element) {
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
