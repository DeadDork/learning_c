////////////////////////////////////////////////////////////////////////////////
// Comments

// This program experiments with all of the escape sequences listed in 2.3.

#include <stdio.h>

int main()
{
	printf( "Alert: [\a\a\a\a\a\a]\n" );
	printf( "Backspace: [\b]\n" );
	printf( "Formfeed: [\f]\n" );
	printf( "Newline: [\n]\n" );
	printf( "Carriage return: [\r]\n" );
	printf( "Horizontal tab: [\t]\n" );
	printf( "Vertical tab: [\v]\n" );
	printf( "Backslash: [\\]\n" );
	printf( "Question mark (without escape): [?]\n" );
	printf( "Question mark (with escape): [\?]\n" );
	printf( "Single quote (without escape): [']\n" );
	printf( "Single quote (with escape): [\']\n" );
	printf( "Double quote (with escape, as I can't create a string constant otherwise): [\"]\n" );
	printf( "Octal number: [\127\141\172\172\165\160]\n" );
	printf( "Hexadecimal number: [\x47\x6f\x64\x20\x69\x73\x20\x47\x6f\x64]\n" );

	return 0;
}
