////////////////////////////////////////////////////////////////////////////////
// Comments

// Compiling math expressions in reverse polish notation is easy: you
// recursively push numbers or the results of functions (the arguments of which
// you pop). The exception is assignment: if in the form "x y =", where x is a
// variable name and y is a value, you need a parser for complex expressions
// like "x y 7 + =", where y is a previously assigned variable. A simpler
// solution is to put the variable name on the right of the value,
// e.g. "y 7 + x =". This way no matter how complex the value, it is the topmost
// value on the stack that is assigned to the variable.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

////////////////////////////////////////////////////////////////////////////////
// Functions

void compile(char lexeme[], enum tokens token) {
	double temp_number;

	switch (token) {
		case NUMBER:
			push(atof(lexeme));
			break;
		case VARIABLE:
			push(retrieve_variable(lexeme[0]));
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
