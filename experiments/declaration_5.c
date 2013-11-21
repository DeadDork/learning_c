// Explores array declarations of incomplete type (is it legal?).

// Conclusion: it is not legal.

int main(void) {
	char array[]; // error: definition of variable with array type needs an explicit size or an initializer

	return 0;
}
