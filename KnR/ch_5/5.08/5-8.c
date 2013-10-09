// Demo's error-checking on year_day() & month_day().

// main() {{{
#include <stdio.h>

#define PromptDate(x)\
	printf("Enter " #x ": ");\
	if ((x = get_number()) == EOF)\
		break;

int get_number(void);
int year_day(int, int, int);
int month_day(int, int, int *, int *);

int main() {
	int year, month, day, day_of_year;

	for (;;) {
		PromptDate(year);
		PromptDate(month);
		PromptDate(day);
		day_of_year = year_day(year, month, day);
		if (day_of_year)
			printf("Day of year = [%d]\n", day_of_year);
		else
			printf("Bad date: %d-%02d-%02d\n", year, month, day);

		PromptDate(year);
		PromptDate(day_of_year);
		if (month_day(year, day_of_year, &month, &day))
			printf("Month = [%d], Day = [%d]\n", month, day);
		else
			printf("Bad date: %d-%03d\n", year, day_of_year);
	}
	putchar('\n');

	return 0;
}
// }}}

// get_number() {{{
#include <ctype.h>

#define ERROR 0

int get_number() {
	int character, number = 0;

	while ((character = getchar()) != EOF && !isspace(character)) {
		if (isnumber(character))
			number = number * 10 + character - '0';
		else
			return ERROR;
	}

	return (character == EOF) ? EOF : number;
}
// }}}

// year_day() {{{
static char day_table[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, // leap_year = 0, aka false
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}  // leap_year = 1, aka true
};

int year_day(int input_year, int input_month, int input_day) {
	int month, leap_year, day_of_year;

	if (input_month < 1 || input_month > 13 || input_day < 1 || input_day > 31)
		return ERROR;

	leap_year = input_year % 4 == 0 && (input_year % 100 != 0 || input_year % 400 == 0); // true (1) if leap year, false (0) if not

	day_of_year = input_day;
	for (month = 1; month < input_month; month++)
		day_of_year += day_table[leap_year][month];

	return day_of_year;
}
// }}}

// month_day() {{{
#define NO_ERROR 1

int month_day(int input_year, int input_day_of_year, int *input_month, int *input_day) {
	int month, leap_year;

	if (input_day_of_year < 1 || input_day_of_year > 367 || *input_month < 1 || *input_month > 13 || *input_day < 1 || *input_day > 31)
		return ERROR;

	leap_year = input_year % 4 == 0 && (input_year % 100 != 0 || input_year % 400 == 0); // true (1) if leap year, false (0) if not

	for (month = 1; input_day_of_year > day_table[leap_year][month]; month++)
		input_day_of_year -= day_table[leap_year][month];
	*input_month = month;
	*input_day = input_day_of_year;

	return NO_ERROR;
}
// }}}
