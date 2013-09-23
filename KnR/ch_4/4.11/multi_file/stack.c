////////////////////////////////////////////////////////////////////////////////
// Comments

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <ctype.h>
#include <stdio.h>
#include "calc.h"

////////////////////////////////////////////////////////////////////////////////
// Symbolic Constants

#define MAX_STACK_DEPTH 100

////////////////////////////////////////////////////////////////////////////////
// External Variables

int current_stack_depth = 0;
double number_stack[MAX_STACK_DEPTH];
int last_variable;
double variable_stack[26]; // a - z
double last_expression;

////////////////////////////////////////////////////////////////////////////////
// Functions

void push(double value) {
	if (current_stack_depth < MAX_STACK_DEPTH)
		number_stack[current_stack_depth++] = value;
	else
		printf("push(): number stack full.\n");
}

double pop(void) {
	if (current_stack_depth > 0)
		return number_stack[--current_stack_depth];
	return 0.0;
}

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

void assign_last_expression(double last) {
	last_expression = last;
}

double retrieve_last_expression(void) {
	return last_expression;
}

void stack_print(void) {
	int element;

	for (element = 0; element < current_stack_depth; ++element)
		printf("number_stack[%d] = %f\n", element, number_stack[element]);
}

void duplicate(void) {
	double temp_number;

	if (current_stack_depth < 1)
		printf("duplicate(): empty stack.\n");
	else {
		temp_number = pop();
		push(temp_number);
		push(temp_number);
	}
}

void clear(void) {
	current_stack_depth = 0;
}

void swap(void) {
	double temp_number;

	if (current_stack_depth < 2)
		printf("swap(): you need at least 2 stack elements in order to swap.\n");
	else {
		temp_number = number_stack[current_stack_depth - 1];
		number_stack[current_stack_depth - 1] = number_stack[current_stack_depth - 2];
		number_stack[current_stack_depth - 2] = temp_number;
	}
}

void print_expression(void) {
	printf("\t%.8f\n", last_expression = pop());
	clear();
}
