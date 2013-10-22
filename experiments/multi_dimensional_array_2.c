// Attempts to set part of a multi-dimensional array by parameterizing one
// dimension.

// Conclusion: looks like you can set part of a multi-dim via a sliced
// paramaterized array.

// Universal {{{
#include <stdio.h>

#define DIM1 2
#define DIM2 4
// Universal }}}

// Main {{{
void print_array(char [DIM1][DIM2]);
void shift_array(char *);

int main(void) {
	char array[DIM1][DIM2] = {{'a', 'b', 'c', '\0'}, {'1', '2', '3', '\0'}};

	print_array(array); putchar('\n');
	shift_array(array[0]);
	print_array(array);

	return 0;
}
// Main }}}

// Print array {{{
void print_array(char array[DIM1][DIM2]) {
	int element1;
	for (element1 = 0; element1 < DIM1; ++element1) {
		printf("Dimension %d:\n", element1 + 1);
		int element2;
		for (element2 = 0; array[element1][element2] != '\0'; ++element2)
			printf("\tarray[%d][%d] = %c\n", element1, element2, array[element1][element2]);
	}
}
// Print array }}}

// Shift array {{{
void shift_array(char array[]) {
	int element = 0;
	while (array[element] != '\0')
		array[element++] += 5;
}
// Shift array }}}
