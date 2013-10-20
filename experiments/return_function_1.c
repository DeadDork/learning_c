// Explores the possibility of a function returning a function.

// Conclusion: holy shit hahahahahahahahahahaaaaaaaaa!

// main {{{
#include <stdio.h>
#include <stdlib.h>

int operation(int, int (*)(int, int), int);
void *operand(char *);

int main(int argc, char *argv[]) {
	printf("%d\n", operation(atoi(argv[1]), operand(argv[2]), atoi(argv[3])));

	return 0;
}
// main }}}

int operation(int left, int (*operation)(int, int), int right) {
	return operation(left, right);
}

// operand {{{
#include <strings.h>

int add(int, int);
int sub(int, int);

void *operand(char *op_string) {
	if (!strcmp(op_string, "-"))
		return sub;
	else if (!strcmp(op_string, "+"))
		return add;
}

int add(int x, int y) {
	return x + y;
}

int sub(int x, int y) {
	return x - y;
}
// operand }}}
