// Prints out the last n lines of input (where n defaults to 10).

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

FILE *create_temporary_file(void);
long get_tail_length(int, char *[]);
int is_number(char *);
void print_file(FILE *);
void print_tail(long, FILE *);
int read_file_backwards(FILE *);
void set_file_position(long, FILE *);

FILE *create_temporary_file(void) {
	FILE *temporary_file = fopen("/tmp/tail_temporary_file", "w+");

	int character;
	while ((character = getchar()) != EOF)
		(void)fputc(character, temporary_file);

	return temporary_file;
}

long get_tail_length(int argc, char *argv[]) {
	if (argc > 1 && argv[1][0] == '-' && is_number(argv[1]))
		return -atol(argv[1]);
	else
		return 10L;
}

int is_number(char *character) {
	char *character_start = character;

	if (*character == '+' || *character == '-')
		++character;

	while (isdigit(*character))
		++character;

	return (character > character_start && isdigit(character[-1]) && *character == '\0') ? 1 : 0;
}

void print_file(FILE *input) {
	int character;
	while ((character = fgetc(input)) != EOF)
		(void)putchar(character);
}

void print_tail(long tail_length, FILE *input) {
	if (input == NULL)
		input = create_temporary_file();

	set_file_position(tail_length, input);

	print_file(input);
}

int read_file_backwards(FILE *input) {
	(void)fseek(input, -2L, SEEK_CUR);
	return fgetc(input);
}

void set_file_position(long tail_length, FILE *input) {
	int character;
	(void)fseek(input, 0L, SEEK_END);
	while ((character = read_file_backwards(input)) != EOF && tail_length > 0L)
		if (character == '\n')
			--tail_length;
	(void)fseek(input, 1L, SEEK_CUR); // skip first '\n'
}

int main(int argc, char *argv[]) {
	long tail_length = get_tail_length(argc, argv);
	FILE *input = (argc > 1) ? fopen(argv[argc - 1], "r") : NULL;

	print_tail(tail_length, input);

	(void)fclose(input);

	return 0;
}
