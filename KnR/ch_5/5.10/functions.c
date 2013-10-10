// Functions file that doesn't have unsafe external variables.

#include "calc.h"
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// lexer() {{{
enum tokens lexer(char *lexeme, enum mode interface) {
	if (interface == INTERACTIVE)
		get_word(lexeme);

	return lex_match(lexeme);
}

// get_word() {{{
void get_word(char *character) {
	char *start_character = character;

	while (is_space(*character = getch()));

	if (*character == '\n' || *character == EOF) {
		*++character = '\0';
		return;
	}

	while (start_character - character < LEXEME_LENGTH_MAX && !is_space(*++character = getch()) && *character != '\n' && *character != EOF);
	if (*character == '\n' || *character == EOF)
		ungetch(*character);
	*character = '\0';
}

enum match is_space(char character) {
	return (character == '\t' || character == ' ') ? MATCH : NOMATCH;
}
// get_word() }}}

// lex_match() {{{
enum tokens lex_match(char *lexeme) {
	if (num_match(lexeme))
		return NUMBER;
	else if (str_match(lexeme, "sin"))
		return SIN;
	else if (str_match(lexeme, "cos"))
		return COS;
	else if (str_match(lexeme, "tan"))
		return TAN;
	else if (str_match(lexeme, "asin"))
		return ASIN;
	else if (str_match(lexeme, "acos"))
		return ACOS;
	else if (str_match(lexeme, "atan"))
		return ATAN;
	else if (str_match(lexeme, "atan2"))
		return ATAN2;
	else if (str_match(lexeme, "sinh"))
		return SINH;
	else if (str_match(lexeme, "cosh"))
		return COSH;
	else if (str_match(lexeme, "tanh"))
		return TANH;
	else if (str_match(lexeme, "exp"))
		return EXP;
	else if (str_match(lexeme, "log"))
		return LOG;
	else if (str_match(lexeme, "log10"))
		return LOG10;
	else if (str_match(lexeme, "pow"))
		return POW;
	else if (str_match(lexeme, "sqrt"))
		return SQRT;
	else if (str_match(lexeme, "ceil"))
		return CEIL;
	else if (str_match(lexeme, "floor"))
		return FLOOR;
	else if (str_match(lexeme, "fabs"))
		return FABS;
	else if (str_match(lexeme, "ldexp"))
		return LDEXP;
	else if (str_match(lexeme, "fmod"))
		return FMOD;
	else if (str_match(lexeme, "+"))
		return PLUS;
	else if (str_match(lexeme, "-"))
		return MINUS;
	else if (str_match(lexeme, "*"))
		return MULT;
	else if (str_match(lexeme, "/"))
		return DIV;
	else if (str_match(lexeme, "%"))
		return MOD;
	else if (str_match(lexeme, "="))
		return ASSIGN;
	else if (str_match(lexeme, "print"))
		return PRINT;
	else if (str_match(lexeme, "duplicate"))
		return DUPLICATE;
	else if (str_match(lexeme, "clear"))
		return CLEAR;
	else if (str_match(lexeme, "swap"))
		return SWAP;
	else if (str_match(lexeme, "\n"))
		return NEW_LINE;
	else if (*lexeme == EOF)
		return FILE_END;
	else if (islower(*lexeme) && *(lexeme + 1) == '\0') {
		return VARIABLE;
	} else if (str_match(lexeme, "last"))
		return LAST;
	else
		return ERROR;
}

enum match num_match(char *character) {
	char *start_character = character;

	if (*character == '-' || *character == '+')
		++character;

	while (isdigit(*character))
		++character;

	if (*character == '.')
		++character;

	while (isdigit(*character))
		++character;

	return (character > start_character && isdigit(*(character - 1)) && *character == '\0') ? MATCH : NOMATCH;
}

enum match str_match(char *character1, char *character2) {
	for (; *character1 != '\0' && *character1 == *character2; ++character1, ++character2);

	return (*character1 == *character2) ? MATCH : NOMATCH;
}
// lex_match() }}}
// lexer() }}}

void compile(char *lexeme, enum tokens token) {
	double temp_number;

	switch (token) {
		case NUMBER:
			push(atof(lexeme));
			break;
		case VARIABLE:
			push(retrieve_variable(*lexeme));
			break;
		case LAST:
			push(retrieve_last_expression());
			break;
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
			temp_number = pop();
			push(pop() - temp_number);
			break;
		case MULT:
			push(pop() * pop());
			break;
		case DIV:
			temp_number = pop();
			if (temp_number != 0.0)
				push(pop() / temp_number);
			else
				printf("compile(), case DIV: zero divisor\n");
			break;
		case MOD:
			temp_number = pop();
			if (temp_number != 0.0)
				push((int)pop() % (int)temp_number);
			else
				printf("compile(), case MOD: zero divisor\n");
			break;
		case ASSIGN:
			pop();
			temp_number = pop();
			assign_variable(temp_number);
			push(temp_number);
			break;
		case PRINT:
			stack_print();
			break;
		case DUPLICATE:
			duplicate();
			break;
		case CLEAR:
			clear();
			break;
		case SWAP:
			swap();
			break;
		case NEW_LINE:
			print_expression();
			break;
		default:
			printf("error: unknown command [%s]\n", lexeme);
			break;
	}
}
