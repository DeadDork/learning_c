// Explores declaration order.

// Conclusion: it doesn't matter what order the specifiers go in.

int main(void) {
	static int x = 1;
	int static y = 1;

	return 0;
}
