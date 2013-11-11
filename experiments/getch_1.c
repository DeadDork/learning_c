// K & R uses getch() & ungetch() a lot. This library-fies them.

#include "getch_1.h"

char buf[BUFSIZE];
int bufp = 0;

void ungetch(int);
int getch(void);

int getch(void) {
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}
