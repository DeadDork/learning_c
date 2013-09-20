////////////////////////////////////////////////////////////////////////////////
// Comments

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include "header.h"

////////////////////////////////////////////////////////////////////////////////
// External Variables

int i, total;

////////////////////////////////////////////////////////////////////////////////
// Functions

void add(int ii) {
	total += ii;
}

void sub(int ii) {
	total -= ii;
}

int abs(int ii) {
	return (ii < 0) ? ii * -1 : ii;
}

void mult(int ii) {
	if (i == 0 || ii == 0)
		total = 0;
	else if (abs(ii) > 1) {
		if (i > 0 && ii > 0)
			add(i);
		else if (i < 0 && ii > 0)
			sub(i);
		else if (i < 0 && ii < 0) {
			i = abs(i);
			ii = abs(ii) + 1;
		} else {
			i = -abs(i);
			ii = abs(i) + 1;
		}
		mult(--ii);
	}
}

void eval(char c, int ii) {
	if (c == '+') 
		add(ii);
	else if (c == '-')
		sub(ii);
	else if (c == '*')
		mult(ii);
}

void exec(void) {
	char c;
	int ii;

	printf("Complete simple expression (i.e. X [+-*] Y):\n\t%d ", total);
	if (scanf("%c%d", &c, &ii) < 2 || !(c == '+' || c == '-' || c == '*'))
		return;
	fpurge(stdin);

	i = total;
	eval(c, ii);

	exec();
}
