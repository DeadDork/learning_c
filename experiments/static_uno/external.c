////////////////////////////////////////////////////////////////////////////////
// Comments

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include "header.h"

////////////////////////////////////////////////////////////////////////////////
// External Variables

//int i1 = 1; // The value changes in main(), as expected
static int i1 = 1; // The value also changes in main(), not as expected

////////////////////////////////////////////////////////////////////////////////
// Functions

int *addresser(void) {
	return &i1;
}
