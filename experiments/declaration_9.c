// Explores the scope of object declarators inside function declarations.

// The scope is limited to just the function prototype.

int main(void) {
	int function(int x, int y);

	x = y; // error: use of undeclared identifier 'x' & 'y'

	return 0;
}
