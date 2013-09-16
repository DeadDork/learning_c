////////////////////////////////////////////////////////////////////////////////
// Comments

// Solution to ex. 4-10.

// Replace getch() & ungetch() with getln().

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

////////////////////////////////////////////////////////////////////////////////
// Symbolic Constants

#define MAXLEN 100

#define NOMATCH 0
#define MATCH 1

#define STRING 0
#define NUMBER 1
#define VARIABLE 2

////////////////////////////////////////////////////////////////////////////////
// Function Prototypes

// Read a line from STDIN into a character array
int getln(char []);

// Determines whether a string matches against the pseudo-regex
// '/-?([1-9][0-9]+|[0-9]?)\.?[0-9]+/'
int num_match(char []);

// Determines whether two strings match
int str_match(char [], char []);

// Get next word in a character array
void next_word(char [], char [], int []);

// Get previous word in a character array
void prev_word(char [], char [], int []);

// Pop the value from the top of the number stack
double pop(double [], int []);

// Push a value to the top of the number stack
void push(double [], int [], double);

// Evaluates a math expression.
double evaluate(char [], double [], double [], int [], double);

////////////////////////////////////////////////////////////////////////////////
// Functions

int getln(char s[]) {
	int c, i;

	for (i = 0; i < MAXLEN - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	s[i] = '\0';

	return (c == '\n') ? ++i : i;
}

int num_match(char s[]) {
	int i = 0;

	if (s[i] == '-')
		++i;

	if (s[i] >= '1' && s[i] <= '9' && isdigit(s[i + 1]))
		for (i += 2; isdigit(s[i]); ++i);
	else if (isdigit(s[i]) && s[i + 1] == '.')
		++i;

	if (s[i] == '.')
		for (++i; isdigit(s[i]); ++i);

	return (i > 0 && isdigit(s[i - 1]) && s[i] == '\0') ? MATCH : NOMATCH;
}

int str_match(char s[], char ss[]) {
	int i;

	for (i = 0; s[i] != '\0' && ss[i] != '\0' && s[i] == ss[i]; ++i);

	return (i > 0 && s[i] == ss[i]) ? MATCH : NOMATCH;
}

void next_word(char s[], char w[], int index[]) {
	int i;

	// Skip ws
	for (; isspace(s[index[STRING]]) && s[index[STRING]] != '\0'; ++index[STRING]);

	// Assign next word string
	for (i = 0; !isspace(s[index[STRING]]) && s[index[STRING]] != '\0'; ++index[STRING], ++i)
		w[i] = s[index[STRING]];
	w[i] = '\0';
}

void prev_word(char s[], char w[], int index[]) {
	int i;

	// Go to start of current word
	for (; index[STRING] >= 0 && !isspace(s[index[STRING]]); --index[STRING]);

	// Skip ws
	for (; index[STRING] >= 0 && isspace(s[index[STRING]]); --index[STRING]);

	// Go to start of previous word
	for (; index[STRING] >= 0 && !isspace(s[index[STRING]]); --index[STRING]);

	// Sanity
	if (index[STRING] < 0)
		index[STRING] = 0;

	// Assign next word string
	for (i = 0; !isspace(s[index[STRING]]) && s[index[STRING]] != '\0'; ++index[STRING], ++i)
		w[i] = s[index[STRING]];
	w[i] = '\0';
}

double pop(double nb[], int i[]) {
	if (i[NUMBER] <= 0) {
		printf("pop(): Index out of bounds.\n");
		return 0.0;
	} else
		return nb[--i[NUMBER]];
}

void push(double nb[], int i[], double d) {
	if (i[NUMBER] >= MAXLEN - 1)
		printf("push(): Index out of bounds.\n");
	else
		nb[i[NUMBER]++] = d;
}

double evaluate(char sb[], double nb[], double vb[], int i[], double l) {
	char word[MAXLEN]; 
	double dd;

	while (sb[i[STRING]] == '\0') {
		next_word(sb, word, i);
		if (num_match(word))
			push(nb, i, atof(word));
		else if (islower(word[0]) && word[1] == '\0') // If a variable
			push(nb, i, vb[word[0] - 'a']);
		else if (str_match(word, "last"))
			push(nb, i, l);
		else if (str_match(word, "sin"))
			push(nb, i, sin(pop(nb, i)));
		else if (str_match(word, "cos"))
			push(nb, i, cos(pop(nb, i)));
		else if (str_match(word, "tan"))
			push(nb, i, tan(pop(nb, i)));
		else if (str_match(word, "asin"))
			push(nb, i, asin(pop(nb, i)));
		else if (str_match(word, "acos"))
			push(nb, i, acos(pop(nb, i)));
		else if (str_match(word, "atan"))
			push(nb, i, atan(pop(nb, i)));
		else if (str_match(word, "atan2"))
			push(nb, i, atan2(pop(nb, i), pop(nb, i)));
		else if (str_match(word, "sinh"))
			push(nb, i, sinh(pop(nb, i)));
		else if (str_match(word, "cosh"))
			push(nb, i, cosh(pop(nb, i)));
		else if (str_match(word, "tanh"))
			push(nb, i, tanh(pop(nb, i)));
		else if (str_match(word, "exp"))
			push(nb, i, exp(pop(nb, i)));
		else if (str_match(word, "log"))
			push(nb, i, log(pop(nb, i)));
		else if (str_match(word, "log10"))
			push(nb, i, log10(pop(nb, i)));
		else if (str_match(word, "pow"))
			push(nb, i, pow(pop(nb, i), pop(nb, i)));
		else if (str_match(word, "sqrt"))
			push(nb, i, sqrt(pop(nb, i)));
		else if (str_match(word, "ceil"))
			push(nb, i, ceil(pop(nb, i)));
		else if (str_match(word, "floor"))
			push(nb, i, floor(pop(nb, i)));
		else if (str_match(word, "fabs"))
			push(nb, i, fabs(pop(nb, i)));
		else if (str_match(word, "ldexp"))
			push(nb, i, ldexp(pop(nb, i), pop(nb, i)));
		else if (str_match(word, "fmod"))
			push(nb, i, fmod(pop(nb, i), pop(nb, i)));
		else if (str_match(word, "+"))
			push(nb, i, pop(nb, i) + pop(nb, i));
		else if (str_match(word, "-")) {
			dd = pop(nb, i);
			push(nb, i, pop(nb, i) - dd);
		} else if (str_match(word, "*"))
			push(nb, i, pop(nb, i) * pop(nb, i));
		else if (str_match(word, "/")) {
			dd = pop(nb, i);
			if (dd != 0.0)
				push(nb, i, pop(nb, i) / dd);
			else
				printf("evaluate(): Zero divisor.\n");
		} else if (str_match(word, "%")) {
			dd = pop(nb, i);
			if (dd != 0.0)
				push(nb, i, (int)pop(nb, i) % (int)dd);
			else
				printf("evaluate(): Zero divisor.\n");
		} else if (str_match(word, "=")) {
			dd = pop(nb, i);
			prev_word(sb, word, i);
			prev_word(sb, word, i);
			if (islower(word[0]) && word[1] == '\0')
				vb[word[0] - 'a'] = dd;
			else
				printf("evaluate(): Bad variable assignment.\n");
			next_word(sb, word, i);
			next_word(sb, word, i);
		} else if (str_match(word, "top")) {
			dd = pop(nb, i);
			printf("Top of number stack = %f\n", dd);
			push(nb, i, dd);
		} else if (str_match(word, "dup")) {
			dd = pop(nb, i);
			push(nb, i, dd);
			push(nb, i, dd);
		} else if (str_match(word, "clear")) {
			i[NUMBER] = 0;
			sb[i[STRING]] = '\0';
		} else if (str_match(word, "swap")) {
			dd = pop(nb, i);
			nb[i[NUMBER]] = nb[i[NUMBER] - 1];
			nb[i[NUMBER] - 1] = dd;
		} else
			printf("evaluate(): Unknown command %s\n", word);
	}

	return (i[NUMBER] == 1) ? pop(nb, i) : 0.0;
}

////////////////////////////////////////////////////////////////////////////////
int main(void) {
	char str_buf[MAXLEN];
	double num_buf[MAXLEN - 1]; // MAXLEN - 1 numbers, 1 function to bring them
	                            // all and in the darkness bind them.
	double var_buf[26] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
	int index[3] = {0, 0, 0}; // STRING, NUMBER, VARIABLE
	double last = 0.0;

	while (getln(str_buf) != 0)
		printf("%f\n", last = evaluate(str_buf, num_buf, var_buf, index, last));

	return 0;
}
