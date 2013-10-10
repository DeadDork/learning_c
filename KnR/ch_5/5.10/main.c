#include "calc.h"

int main(int argc, char *argv[]) {
    enum tokens token;
    char lexeme[LEXEME_LENGTH_MAX];

	if (argc == 1)
		while ((token = lexer(lexeme, INTERACTIVE)) != FILE_END)
			compile(lexeme, token);
	else {
		while (argc-- > 1) {
			token = lexer(*++argv, NOTINTERACTIVE);
			compile(*argv, token);
		}
		print_expression();
	}

    return 0;
}
