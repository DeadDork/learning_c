////////////////////////////////////////////////////////////////////////////////
// Comments

// Explores the possibility of returning a pointer via array brackets.

// Fails. I don't really understand the error, though. Here:
/* gcc -Wall -Wextra -g    function-return-array_2.c   -o function-return-array_2
 * function-return-array_2.c:20: error: expected identifier or '(' before '[' token
 * function-return-array_2.c:25: error: expected identifier or '(' before '[' token
 * function-return-array_2.c: In function 'main':
 * function-return-array_2.c:39: warning: implicit declaration of function 'test'
 * function-return-array_2.c:39: warning: assignment makes pointer from integer without a cast
 * make: *** [function-return-array_2] Error 1
*/

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
// Symbolic Constants

#define MAXLEN 100 // Maximum string length

////////////////////////////////////////////////////////////////////////////////
// Function Prototypes

// Returns an argument string array
char[] test(char s[]);

////////////////////////////////////////////////////////////////////////////////
// Functions

char[] test(char s[]) {
	return s;
}

////////////////////////////////////////////////////////////////////////////////
int main(void) {
	char a[MAXLEN] = "Hello!";
	char b[MAXLEN] = "Goodbye!";
	char * c;

	printf("Control:\n");
	printf("\t%s\n", a);
	printf("\t%s\n", b);

	c = test(b);
	printf("Test:\n");
	printf("\t%s\n", a);
	printf("\t%s\n", b);
	printf("\t%s\n", c);

	return 0;
}
