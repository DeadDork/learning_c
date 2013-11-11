// Explores strcat (does it cat to end or beginning?)

// Conclusion: strcat() cats s2 to s1, and the output char pointer is for some
// s3.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PrintExpression(x) printf(#x " = [%s]\n", x)

int main(int argc, char *argv[]) {
	char *arg_1 = argv[(argc > 2) ? argc - 2 : argc - 1];
	char *arg_2 = argv[argc - 1];

	char *string;
	string = malloc(strlen(arg_1) + strlen(arg_2));
	strcpy(string, arg_1);

	PrintExpression(string);
	strcat(string, arg_2);
	PrintExpression(string);

	return 0;
}
