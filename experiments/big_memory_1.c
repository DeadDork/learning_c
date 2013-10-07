// Attempts to determine why new_string_sort from 5-7 is not working.

// Hypothesis: stack allocation too large.

// Conclusion: did not segfault.

#define BLOCK_SIZE 5000 * 1000

int main(void) {
	char huge_block[BLOCK_SIZE];

	return 0;
}
