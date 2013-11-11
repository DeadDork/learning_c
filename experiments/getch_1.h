// K & R uses getch() & ungetch() a lot. This library-fies them.

#ifndef EOF // Best I could think...
#include <stdio.h>
#endif

#define BUFSIZE 100

void ungetch(int);
int getch(void);
