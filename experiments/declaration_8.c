// Demo's all of the possible simple direct declarator declarations.

// Conclusion: neither array nor function are valid types. That said, the error
// is not in the form of the declaration, but in the typing.

int main(void) {
	char a;
	char (b);
	char c[1];
	char d();

	char e[1];
	char (f)[1];
	char g[1][1];
	//char h[1](); // error: 'h' declared as array of functions of type 'char ()'

	char i();
	char (j)();
	//char k()[1]; // error: function cannot return array type 'char [1]'
	//char l()(); // error: function cannot return function type 'char ()'

	return 0;
}
