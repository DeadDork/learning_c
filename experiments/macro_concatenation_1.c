// Explores macro cats (cpp wasn't catting appropriately on my Mac)

// Under Linux (with a real cpp), this expanded in unexpected ways.
// Consequently, I've read the cpp info, and it's clear why: you can append
// and prepend to the expanded tokens, but not recursively through the
// list of tokens. Makes sense. Damn you weakass pre-processor...

#define OneTwoThree\
	ONE,\
	TWO,\
	THREE

#define Tokenize(...) __VA_ARGS__ ## _TOKEN

enum NUMBERS {
	ZERO,
	OneTwoThree,
	FOUR
};

enum NUMBER_TOKENS {
	ZERO_TOKEN,
	Tokenize(OneTwoThree),
	FOUR_TOKEN,
	Tokenize(FIVE, SIX, SEVEN)
};
