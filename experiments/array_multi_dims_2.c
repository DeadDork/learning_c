// Explores functions with multi-dimensional array arguments.

// Conclusion: C doesn't like passing multi-dim arrays.

// main {{{
//void array_print(double [][]); // error: array type has incomplete element typ
#include <stdio.h>

void array_print(double *[]);

#define PrintArray(array, dim1, dim2) {\
	int element1, element2;\
	for (element1 = 0; element1 < (dim1); ++element1) {\
		for (element2 = 0; element2 < (dim2); ++element2)\
			printf(#array "[%d][%d] = %f\n", element1, element2, array[element1][element2]);\
	}\
}

int main(void) {
	double array[2][2] = {{0.0, 0.1}, {1.0, 1.1}};
	PrintArray(array, 2, 2); putchar('\n');

	// Segfaults
	//array_print(array); // warning: passing argument 1 of 'array_print' from incompatible pointer type

	double *pointer_array[2] = {array[0], array[1]};
	array_print(pointer_array);

	return 0;
}
// main }}}

// array_print() {{{
//void array_print(double array[][]) {
void array_print(double *array[]) {
	PrintArray(array, 2, 2);
}
// array_print() }}}
