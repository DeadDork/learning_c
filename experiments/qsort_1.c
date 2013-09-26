////////////////////////////////////////////////////////////////////////////////
// Comments

// Visualizes a quick sort.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>
#include <stdlib.h>

////////////////////////////////////////////////////////////////////////////////
// Symbolic Constants

#define VECTOR_LENGTH 20

////////////////////////////////////////////////////////////////////////////////
// External Variables

static int line_number;

////////////////////////////////////////////////////////////////////////////////
// Function Prototypes

// Sort vector from left to right
void quick_sort(int [], int, int);

// Interchange vector elements
void swap(int [], int, int);

// Prints the current values of the vector
void print_vector(int[]);

// Print the values being compared around the pivot
void print_left_right(int, int);

////////////////////////////////////////////////////////////////////////////////
// Functions

void print_vector(int vector[]) {
	int element;

	printf("%-7d", ++line_number);
	for (element = 0; element < VECTOR_LENGTH; ++element)
		printf("%d", vector[element]);
	putchar('\n');
}

void print_left_right(int left, int right) {
	int element;

	printf("       ");
	for (element = 0; element < VECTOR_LENGTH; ++element) {
		if (element == left || element == right)
			putchar('^');
		else
			putchar(' ');
	}
	putchar('\n');
}

void swap(int vector[], int element_a, int element_b) {
	int place_holder;

	if (vector[element_a] > vector[element_b]) {
		print_vector(vector);
		print_left_right(element_a, element_b);

		place_holder = vector[element_a];
		vector[element_a] = vector[element_b];
		vector[element_b] = place_holder;
	}
}

void quick_sort(int vector[], int left, int right) {
	int element, last;

	// Do nothing if array contains fewer than two elements
	if (left >= right)
		return;

	swap(vector, left, (left + right)/2); // Move partition element

	last = left;
	for (element = left + 1; element <= right; element++)
		if (vector[element] < vector[left])
			swap(vector, ++last, element);

	swap(vector, left, last); // Restore partition element

	quick_sort(vector, left, last - 1);

	quick_sort(vector, last + 1, right);
}

////////////////////////////////////////////////////////////////////////////////
int main(void) {
	int vector[VECTOR_LENGTH], element;

	for (element = 0; element < VECTOR_LENGTH; ++element) {
		srandomdev();
		vector[element] = random() % 10;
	}

	quick_sort(vector, 0, VECTOR_LENGTH - 1);
	print_vector(vector);

	return 0;
}
