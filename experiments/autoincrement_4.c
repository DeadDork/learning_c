// Explores autoincrementing assignments

#include <stdio.h>

int main(void) {
	int array[] = {0, 1, 2, 3, 4, 5}, element;
	int *parray = array;

	for (element = 0; element <= 5; ++element)
		printf("array[%d] = [%d]\n", element, array[element]);

	putchar('\n');
	while ((*parray++ = parray[1]) && *parray < 5);

	for (element = 0; element <= 5; ++element)
		printf("array[%d] = [%d]\n", element, array[element]);

	return 0;
}
