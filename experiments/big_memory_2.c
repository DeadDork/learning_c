// Attempts to determine why new_string_sort from 5-7 is not working.

// Hypothesis: stack allocation too large.

// Conclusion: segfault!

#define BLOCK_SIZE 5000 * 1000

int main(void) {
	char huge_block_1[BLOCK_SIZE];
	char huge_block_2[BLOCK_SIZE];
	char huge_block_3[BLOCK_SIZE];
	char huge_block_4[BLOCK_SIZE];

	return 0;
}
