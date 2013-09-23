////////////////////////////////////////////////////////////////////////////////
// Comments

// SRPC = Simple Reverse Polish Calculator

////////////////////////////////////////////////////////////////////////////////
// Enums

// Match
enum match {
	NOMATCH,
	MATCH
};

// Tokens
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

////////////////////////////////////////////////////////////////////////////////
// Function Prototypes

// Stores the value of the last expression
void assign_last_expression(double);

// Assigns a value to a variable in the range of a - z
void assign_variable(double);

// Clears the number stack
void clear(void);

// Compiles token
void compile(char [], enum tokens);

// Pushes to the number stack a duplicate of the topmost number in the stack
void duplicate(void);

// Get a (possibly pushed-back) character
int getch(void);

// Reads a word from stdin
void get_word(char []);

// Matches against horizontal white space
enum match is_space(char);

// Lexical analysis
enum tokens lexer(char []);

// Simple lex matching
enum tokens lex_match(char []);

// Determines whether a string matches against the following regex:
//// '/-?([1-9][0-9]+|[0-9]?)\.?[0-9]+/'
enum match num_match(char []);

// Pop and return top value from stack
double pop(void);

// Prints & clears the current value of the expression
// (N.B. This is not safe, as a poorly written expression will still print)
void print_expression(void);

// Push a float onto value stack
void push(double);

// Retrieves the value of the last expression
double retrieve_last_expression(void);

// Returns the value of a given variable name
double retrieve_variable(char);

// Prints all of the values in the number stack
void stack_print(void);

// Determines whether two strings are identical
enum match str_match(char [], char []);

// Swaps the values of the two topmost stack elements
void swap(void);

// Push character back on input
void ungetch(int);
