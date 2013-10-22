// Explores the use of pointers to pointers as multidimensional arrays in
// functions.

// Conclusion: to pass multi-dim arrays
// Universal {{{
#define DIM1 2
#define DIM2 3
// Universal }}}

// Main {{{
void print_array(char [DIM1][DIM2]);

int main(void) {
	char array[DIM1][DIM2] = {{'z', 'y', 'x'}, {'a', 'b', 'c'}};

	print_array(array);

	return 0;
}
// Main }}}

// Print array {{{
#include <stdio.h>

void print_array(char array[DIM1][DIM2]) {
	int element1;
	for (element1 = 0; element1 < DIM1; ++element1) {
		printf("level %d:\n", element1 + 1);
		int element2;
		for (element2 = 0; element2 < DIM2; ++element2)
			printf("\tarray[%d][%d] = [%c]\n", element1, element2, array[element1][element2]);
	}
}
// Print array }}}
