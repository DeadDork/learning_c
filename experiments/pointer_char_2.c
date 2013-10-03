////////////////////////////////////////////////////////////////////////////////
// Comments

// Examines the difference between a character pointer pointing to a character
// constant and an array being initialized with an array.

// What's going on: a character pointer initialized pointing to a character
// constant points to a part in memory that is not volatile. Attempting to
// change that constant results in a crash. Meanwhile, an array initialized
// to a character constant is actually a copy in the stack of the character
// constant. Given that the stack is volatile, changing values there does not
// the computer crash.

////////////////////////////////////////////////////////////////////////////////
// Global Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
// Code

int main(void) {
	char *string_pointer = "What's up??";
	char string_array[] = "Whatshoo lookin' at?!";

	/*
	// Will fail
	printf("%s\n", string_pointer);
	string_pointer[10] = '!';
	printf("%s\n", string_pointer);
	*/

	// Will work
	printf("%s\n", string_array);
	string_array[4] = ' ';
	string_array[5] = 'y';
	string_array[6] = 'o';
	string_array[7] = 'u';
	printf("%s\n", string_array);

	return 0;
}
