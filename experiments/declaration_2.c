// Further explores type specifier order.

// Huh, this works. I guess order really doesn't matter.

enum OneToFour {
	ONE,
	TWO,
	THREE,
	FOUR
};

int main(void) {
	const enum OneToFour static x = THREE;

	return 0;
}
