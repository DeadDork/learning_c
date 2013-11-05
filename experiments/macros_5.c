// Explores a two level macro expansion, as well as variadic macros.

#define OneTwoThree \
	ONE,\
	TWO,\
	THREE

#define Tokenize(...) TOKEN_ ## __VA_ARGS__

enum NUMBERS {
	ZERO,
	OneTwoThree,
	FOUR
};

enum NUMBER_TOKENS {
	TOKEN_ZERO,
	Tokenize(OneTwoThree),
	TOKEN_FOUR,
	Tokenize(FIVE);
};
