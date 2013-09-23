////////////////////////////////////////////////////////////////////////////////
// Comments

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include "calc.h"

////////////////////////////////////////////////////////////////////////////////
// Symbolic Constants

#define MAX_LEXEME 100

////////////////////////////////////////////////////////////////////////////////
int main(void) {
    enum tokens token;
    char lexeme[MAX_LEXEME];

    while ((token = lexer(lexeme)) != FILE_END)
        compile(lexeme, token);

    return 0;
}
