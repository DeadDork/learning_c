////////////////////////////////////////////////////////////////////////////////
// Comments

// Temperature converter, the remix.

// I sacrificed input via arguments for absolute code efficiency.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

////////////////////////////////////////////////////////////////////////////////
// Structs

typedef struct temp {
	double value;
	char type;
} Temp;

////////////////////////////////////////////////////////////////////////////////
// Functional Prototypes

int gettemp (Temp * t);
/* Get the temperature value & type (e.g. "127.45 F").

   `t` = Pointer to temperature data structure.

   If input has no temperature value & type, then this function returns EOF;
   otherwise it returns 2 (the number of matches to the input, i.e. value
   & type. */

void convert (Temp * t);
/* Convert Celsius values to Fahrenheit units, and vice versa.
 
   `t` = Pointer to temperature data structure. */

////////////////////////////////////////////////////////////////////////////////
// Functions

int gettemp (Temp * t) {
	int c, check = 2;

	while (check != EOF) {
		if (check < 2)
			while ((c = getchar ()) != EOF && !isspace (c)); // Walk bad input
		if ((check = scanf ("%lf %c", &(t->value), &(t->type))) == 2 && (t->type == 'c' || t->type == 'C' || t->type == 'f' || t->type == 'F'))
			break; // Essentially, match of regex '(-?[0-9]*.[0-9]+) (*[cCfF])'
	}

	return check;
}

void convert (Temp * t) {
	if (t->type == 'c' || t->type == 'C')
		t->value = t->value * 9.0 / 5.0 + 32; // Celsius to Fahrenheit
	else if (t->type == 'f' || t->type == 'F')
		t->value = (t->value - 32) * (5.0 / 9.0); // Fahrenheit to Celsius
}

////////////////////////////////////////////////////////////////////////////////
int main () {
	Temp t;

	while (gettemp (&t) != EOF) {
		convert (&t);
		printf ("%f %c\n", t.value, (t.type == 'c' || t.type == 'C') ? 'F' : 'C');
	}

	return 0;
}
