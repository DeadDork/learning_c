// Functions file for various stack functions with unsafe external variables.

#include "calc.h"
#include <ctype.h>
#include <stdio.h>

#define STACK_DEPTH_MAX 100

// Character stack {{{
static char getch_stack[STACK_DEPTH_MAX];
static int getch_stack_depth;

int getch(void) {
    return (getch_stack_depth > 0) ? getch_stack[--getch_stack_depth] : getchar();
}

void ungetch(int character) {
    if (getch_stack_depth >= STACK_DEPTH_MAX)
        printf("ungetch(): too many characters\n");
    else
        getch_stack[getch_stack_depth++] = character;
}
// Character stack }}}

// Last expression {{{
static double last_expression;

void assign_last_expression(double last) {
	last_expression = last;
}

double retrieve_last_expression(void) {
	return last_expression;
}
// Last expression }}}

// Number stack {{{
static int number_stack_depth = 0;
static double number_stack[STACK_DEPTH_MAX];

void push(double value) {
	if (number_stack_depth < STACK_DEPTH_MAX)
		number_stack[number_stack_depth++] = value;
	else
		printf("push(): number stack full.\n");
}

double pop(void) {
	if (number_stack_depth > 0)
		return number_stack[--number_stack_depth];
	return 0.0;
}

void stack_print(void) {
	int element;

	for (element = 0; element < number_stack_depth; ++element)
		printf("number_stack[%d] = %f\n", element, number_stack[element]);
}

void duplicate(void) {
	double temp_number;

	if (number_stack_depth < 1)
		printf("duplicate(): empty stack.\n");
	else {
		temp_number = pop();
		push(temp_number);
		push(temp_number);
	}
}

void clear(void) {
	number_stack_depth = 0;
}

void swap(void) {
	double temp_number;

	if (number_stack_depth < 2)
		printf("swap(): you need at least 2 stack elements in order to swap.\n");
	else {
		temp_number = number_stack[number_stack_depth - 1];
		number_stack[number_stack_depth - 1] = number_stack[number_stack_depth - 2];
		number_stack[number_stack_depth - 2] = temp_number;
	}
}

void print_expression(void) {
	double temp_number;

	if (number_stack_depth == 1) {
		temp_number = pop();
		assign_last_expression(temp_number);
		printf("%.8f\n", temp_number);
	} else {
		assign_last_expression(0.0);
		printf("print_expression(): bad expression.\n");
		clear();
	}
}
// Number stack }}}

// Variables stack {{{
int last_variable;
double variable_stack[26]; // a - z

void assign_variable(double value) {
	variable_stack[last_variable] = value;
}

double retrieve_variable(char variable) {
	if (islower(variable)) {
		last_variable = variable - 'a';
		return variable_stack[last_variable];
	} else {
		printf("retrieve_variable(): variable name out of range of a - z.\n");
		return 0.0;
	}
}
// Variables stack }}}
