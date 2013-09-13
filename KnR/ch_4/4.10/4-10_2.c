////////////////////////////////////////////////////////////////////////////////
// Comments

// Solution to ex. 4-10.

// Replace getch() & ungetch() with getline().

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

// Read a line from STDIN into a character array.
int getline(char []);

// Determines whether a string matches against the pseudo-regex
// '/-?([1-9][0-9]+|[0-9]?)\.?[0-9]+/'.
int num_match(char []);

// Determines whether two strings match.
int str_match(char string1[], char string2[]);

// Recursively evaluates a math expression.
double evaluate(char [], char [], int, double [], int, double);

// Assigns the next word substring from a string.
int next_word(char s[], char w[], int i);

////////////////////////////////////////////////////////////////////////////////
// Functions

int getline(char s[]) {
	int c, i;

	for (i = 0; i < MAXLEN - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	s[i] = '\0';

	if (c == '\n')
		return ++i; // In case of blank lines
	else
		return i;
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
	w[i] == '\0';
}

double pop(double buf[], int index[], int i) {
	if (index[i] == 0) {
		printf("pop(): Element does not exist.\n");
		return 0.0;
	} else
		return buf[--index[i]];
}

double evaluate(char s[], char sub_s[], double nb[], double vb[], int i[], double l, double d) {
	next_word(s, sub_s, i);
	if (sub_s[0] == '\0')
		return d;
	else {
		if (num_match(sub_s))
			nb[nb_i++] = atof(sub_s);
		else if (islower(sub_s[0]) && sub_string[1] == '\0') // If a variable
			nb[nb_i++] = vb[sub_s[0] - 'a'];
		else if (str_match(sub_s, "last"))
			nb[nb_i++] = l;
		else if (str_match(sub_s, "sin"))
			nb[nb
		case SIN:
			push(sin(pop()));
			break;
		case COS:
			push(cos(pop()));
			break;
		case TAN:
			push(tan(pop()));
			break;
		case ASIN:
			push(asin(pop()));
			break;
		case ACOS:
			push(acos(pop()));
			break;
		case ATAN:
			push(atan(pop()));
			break;
		case ATAN2:
			push(atan2(pop(), pop()));
			break;
		case SINH:
			push(sinh(pop()));
			break;
		case COSH:
			push(cosh(pop()));
			break;
		case TANH:
			push(tanh(pop()));
			break;
		case EXP:
			push(exp(pop()));
			break;
		case LOG:
			push(log(pop()));
			break;
		case LOG10:
			push(log10(pop()));
			break;
		case POW:
			push(pow(pop(), pop()));
			break;
		case SQRT:
			push(sqrt(pop()));
			break;
		case CEIL:
			push(ceil(pop()));
			break;
		case FLOOR:
			push(floor(pop()));
			break;
		case FABS:
			push(fabs(pop()));
			break;
		case LDEXP:
			push(ldexp(pop(), (int)pop()));
			break;
		case FMOD:
			push(fmod(pop(), pop()));
			break;
		case PLUS:
			push(pop() + pop());
			break;
		case MINUS:
			op2 = pop();
			push(pop() - op2);
			break;
		case MULT:
			push(pop() * pop());
			break;
		case DIV:
			op2 = pop();
			if (op2 != 0.0)
				push(pop() / op2);
			else
				printf("error: zero divisor\n");
			break;
		case MOD:
			op2 = pop();
			if (op2 != 0.0)
				push((int)pop() % (int)op2);
			else
				printf("error: zero divisor\n");
			break;
		case ASSIGN:
			if (sp > 1) {
				eat();
				op2 = pop();
				pop();
				var[varname] = op2;
			} else
				printf("error: no value to assign\n");
			break;
		case PRINT:
			eat();
			if (sp > 0)
				for (i = 0; i < sp; ++i)
					printf("\tvalue_stack[%d] = %f\n", i, val[i]);
			else
				printf("error: stack empty\n");
			break;
		case DUP:
			eat();
			if (sp > 1) {
				op2 = pop();
				pop();
				push(op2);
				push(op2);
			} else
				printf("error: not enough values in stack\n");
			break;
		case CLR:
			eat();
			sp = 0;
			break;
		case SWAP:
			eat();
			if (sp > 1) {
				op2 = val[sp - 1];
				val[sp - 1] = val[sp - 2];
				val[sp - 2] = op2;
			} else
				printf("error: not enough values in stack\n");
			break;
		case NL:
			printf("\t%.8g\n", var[26] = pop());
			break;
		default:
			printf("error: unknown command %s\n", s);
			break;

	else if (str_match(s, "sin"))
		return SIN;
	else if (str_match(s, "cos"))
		return COS;
	else if (str_match(s, "tan"))
		return TAN;
	else if (str_match(s, "asin"))
		return ASIN;
	else if (str_match(s, "acos"))
		return ACOS;
	else if (str_match(s, "atan"))
		return ATAN;
	else if (str_match(s, "atan2"))
		return ATAN2;
	else if (str_match(s, "sinh"))
		return SINH;
	else if (str_match(s, "cosh"))
		return COSH;
	else if (str_match(s, "tanh"))
		return TANH;
	else if (str_match(s, "exp"))
		return EXP;
	else if (str_match(s, "log"))
		return LOG;
	else if (str_match(s, "log10"))
		return LOG10;
	else if (str_match(s, "pow"))
		return POW;
	else if (str_match(s, "sqrt"))
		return SQRT;
	else if (str_match(s, "ceil"))
		return CEIL;
	else if (str_match(s, "floor"))
		return FLOOR;
	else if (str_match(s, "fabs"))
		return FABS;
	else if (str_match(s, "ldexp"))
		return LDEXP;
	else if (str_match(s, "fmod"))
		return FMOD;
	else if (str_match(s, "+"))
		return PLUS;
	else if (str_match(s, "*"))
		return MULT;
	else if (str_match(s, "/"))
		return DIV;
	else if (str_match(s, "%"))
		return MOD;
	else if (str_match(s, "="))
		return ASSIGN;
	else if (str_match(s, "prnt"))
		return PRINT;
	else if (str_match(s, "dup"))
		return DUP;
	else if (str_match(s, "clr"))
		return CLR;
	else if (str_match(s, "swp"))
		return SWAP;
	else if (str_match(s, "\n")) // Unnecessary?
		return NL;
	else if (s[0] == EOF)
		return FILEEND;
	else if (s[0] >= 'a' && s[0] <= 'z' && s[1] == '\0') {
		varname = s[0] - 'a'; // Unnecessary?
		return VAR;
	} else if (str_match(s, "_"))
		return LAST;
	else
		return ERROR;
}

////////////////////////////////////////////////////////////////////////////////
int main(void) {
	char s[MAXLEN];
	char sub_s[MAXLEN];
	double num_buf[MAXLEN - 1]; // MAXLEN - 1 numbers, 1 function to bring them
	                            // all and in the darkness bind them.
	double var_buf[26];
	int index[3] = {0, 0, 0};
	double last = 0.0;

	while (getline(s) != 0)
		printf("%s = %f\n", s, last = evaluate(s, sub_s, num_buf, var_buf, index, 0.0, 0.0));

	return 0;
}
