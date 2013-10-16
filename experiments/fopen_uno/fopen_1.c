// Explores opening files in different directories.

#include <stdio.h>

int main(void) {
	FILE *file_local = fopen("local.asc", "w");
	FILE *file_level_uno = fopen("./level_uno/level_uno.asc", "w");
	FILE *file_level_dos = fopen("./level_uno/level_dos/level_dos.asc", "w");
	FILE *file_level_tres = fopen("/Users/deaddork/Programming/projects/DeadDork/learning_c/experiments/fopen_uno/level_uno/level_dos/level_tres/level_tres.asc", "w");

	fputs("Printing to a local file\n", file_local);
	fputs("Printing to a file one directory down from local\n", file_level_uno);
	fputs("Printing to a file two directories down from local\n", file_level_dos);
	fputs("Printering to a file using an absolute address\n", file_level_tres);

	fclose(file_local);
	fclose(file_level_uno);
	fclose(file_level_dos);
	fclose(file_level_tres);

	return 0;
}
