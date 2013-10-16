// Explores setting a new file position indicator inside a function.

// Conclusion: works!

#include <stdio.h>

void file_center(FILE *);
void print_file(FILE *);

int main(void) {
	FILE *file = fopen("fseek_test_1.asc", "r");

	file_center(file);
	print_file(file);

	fclose(file);

	return 0;
}

void file_center(FILE *file) {
	long start;
	fseek(file, 0, SEEK_SET);
	start = ftell(file);

	long end;
	fseek(file, 0, SEEK_END);
	end = ftell(file);

	fseek(file, (start + end) / 2, SEEK_SET);
}

void print_file(FILE *file) {
	int character;
	while ((character = fgetc(file)) != EOF)
		putchar(character);
}
