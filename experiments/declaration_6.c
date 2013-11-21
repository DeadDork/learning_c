// Explores freaky array declarations.

// Conclusion: K & R A8.6.2 multidim example refers only to array subscripting,
// not to array declarations. Thank god--the world still makes sense!

int main(void) {
	static int x3d[3][5][7]; // Normal multidim array
	static int *(y3d[3][5] + 7); // Freaky multidim array; error: expected ')'

	return 0;
}
