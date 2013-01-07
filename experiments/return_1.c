////////////////////////////////////////////////////////////////////////////////
// Comments

// Tests various forms of the *return* function.

// Conclusion: *return* is only good for returning one value.

////////////////////////////////////////////////////////////////////////////////
int main()
{
	//int a = 1;
	//int b = 2;
	//int c;
	//char ch = 'h';
	//char s[] = "hello";

	return 0; // returns 0
	//return 1; // returns 1
	//return 42; // returns 42

	//return 1 * ( 2 - 3 ); // returns 255. That's kinda weird. Is it because this is an unsigned integer?
	//return -1; // Yup!

	//return a b; // Error
	//return a, b; // Only returns b.

	//return a - b - 1 * ( 2 - 3 + 4 + -5 ) * ( 6 - 7 ) / ( 8 - 10 ); // returns 0
	//return b - a - 1 * ( 2 - 3 + 4 + -5 ) * ( 6 - 7 ) / ( 8 - 10 ); // returns 2

	//return ( a > b) ? a : b; // returns 2

	//return ( if( a > b ) a ); // Bunch of errors
	//return ( if( b > a ) b ); // Bunch of errors
	/*
	c = (
		if( b > a )
			b
		);
	return c;
	*/ // Also fails miserably.

	//return ch; // Returns ascii dec value.
	//return s; // Returns pointer.
}
