////////////////////////////////////////////////////////////////////////////////
// Comments

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <ctype.h>
#include <stdio.h>
#include "calc.h"

////////////////////////////////////////////////////////////////////////////////
// Functions

enum match num_match(char string[]) {
	int element = 0;

	if (string[element] == '-')
		++element;

	if (string[element] >= '1' && string[element] <= '9' && isdigit(string[element + 1]))
		for (element += 2; isdigit(string[element]); ++element);
	else if (isdigit(string[element]))
		++element;

	if (string[element] == '.')
		++element;

	for (; isdigit(string[element]); ++element);

	return (element > 0 && isdigit(string[element - 1]) && string[element] == '\0') ? MATCH : NOMATCH;
}

enum match str_match(char string1[], char string2[]) {
	int element;

	for (element = 0; string1[element] != '\0' && string2[element] != '\0' && string1[element] == string2[element]; ++element);

	return (string1[element] == string2[element]) ? MATCH : NOMATCH;
}

enum tokens lex_match(char lexeme[]) {
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
	else if (lexeme[0] == EOF)
		return FILE_END;
	else if (islower(lexeme[0]) && lexeme[1] == '\0') {
		return VARIABLE;
	} else if (str_match(lexeme, "last"))
		return LAST;
	else
		return ERROR;
}

enum match is_space(char character) {
	return (character == '\t' || character == ' ') ? MATCH : NOMATCH;
}

void get_word(char word[]) {
	int element;

	while (is_space(word[0] = getch()));

	if (word[0] == '\n' || word[0] == EOF) {
		word[1] = '\0';
		return;
	} else {
		for (element = 1; !is_space(word[element] = getch()) && word[element] != '\n' && word[element] != EOF; ++element);
		if (word[element] == '\n' || word[element] == EOF)
			ungetch(word[element]);
		word[element] = '\0';
	}
}

enum tokens lexer(char lexeme[]) {
	get_word(lexeme);

	return lex_match(lexeme);
}
