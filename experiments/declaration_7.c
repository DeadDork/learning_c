// Explores a declarator that I thought was impossible...

// Conclusion: the universe still makes sense.

int main(void) {
	//char fn_1()[4]; // error: function cannot return array type 'char [4]'
	char fn_2[4](); // error: 'fn_2' declared as array of functions of type 'char ()'

	return 0;
}
