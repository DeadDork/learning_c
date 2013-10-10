// Demo's `expr`, which evaluates reverse polish expression.
// If there are any args, then it is executed in non-interactive mode.
// If there aren't, then it is executed in interactive mode.

// N.B. Strange bug: some args are not interpreted as strings (e.g. '*'). These
// have to be individually quoted or escaped for expr to work
// (e.g. `./expr 1 2 "*"`).

#define LEXEME_LENGTH_MAX 100

enum match {
	NOMATCH,
	MATCH
};

enum mode {
	NOTINTERACTIVE,
	INTERACTIVE
};

enum tokens {
    NUMBER,
    VARIABLE,
    LAST,
    ASSIGN,
    SIN,
    COS,
    TAN,
    ASIN,
    ACOS,
    ATAN,
    ATAN2,
    SINH,
    COSH,
    TANH,
    EXP,
    LOG,
    LOG10,
    POW,
    SQRT,
    CEIL,
    FLOOR,
    FABS,
    LDEXP,
    FMOD,
    PLUS,
    MINUS,
    MULT,
    DIV,
    MOD,
    PRINT,
    DUPLICATE,
    CLEAR,
    SWAP,
    NEW_LINE,
    FILE_END,
    ERROR
};

void assign_last_expression(double);
void assign_variable(double);
void clear(void);
void compile(char *, enum tokens);
void duplicate(void);
int getch(void);
void get_word(char *);
enum match is_space(char);
enum tokens lexer(char *, enum mode);
enum tokens lex_match(char *);
enum match num_match(char *);
double pop(void);
void print_expression(void);
void push(double);
double retrieve_last_expression(void);
double retrieve_variable(char);
void stack_print(void);
enum match str_match(char *, char *);
void swap(void);
void ungetch(int);
