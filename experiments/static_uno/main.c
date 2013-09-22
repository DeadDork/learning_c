////////////////////////////////////////////////////////////////////////////////
// Comments

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include "header.h"

////////////////////////////////////////////////////////////////////////////////
int main(void) {
	int *i2;
	*i2 = 2;

	printf("Addresses:\n");
	printf("\ti1 = [%p]\n", addresser());
	printf("\t12 = [%p]\n", i2);

	printf("Values:\n");
	printf("\ti1 = [%d]\n", *addresser());
	printf("\t12 = [%d]\n\n", *i2);

	i2 = addresser();
	*i2 = 3;

	printf("Addresses:\n");
	printf("\ti1 = [%p]\n", addresser());
	printf("\t12 = [%p]\n", i2);

	printf("Values:\n");
	printf("\ti1 = [%d]\n", *addresser());
	printf("\t12 = [%d]\n", *i2);

	return 0;
}
