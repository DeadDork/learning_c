//#include <sys/types.h>
#include <stdlib.h>
#include <regex.h>
#include <stdio.h>

int main( void )
{
	regex_t regex;
	char re[];
	char s[];
	char msgbuf[ 100 ];
	int reti;

/* Get regular expression sequence & test string. */
	printf( "Enter a Regular Expression sequence: " );
	scanf( "%s", re );

	printf( "Enter a test string to check the regex against: " );
	scanf( "%s", s );

/* Compile regular expression */
	reti = regcomp( &regex, re, 0 );
	if( reti )
	{
		fprintf( stderr, "Could not compile regex\n" );
		exit( 1 );
	}

/* Execute regular expression */
	reti = regexec( &regex, re, 0, NULL, 0 );
	if( !reti )
		puts("Match");
	else if( reti == REG_NOMATCH )
		puts("No match");
	else
	{
		regerror( reti, &regex, s, sizeof( msgbuf ) );
		fprintf( stderr, "Regex match failed: %s\n", msgbuf );
		exit( 1 );
	}

/* Free compiled regular expression if you want to use the regex_t again */
regfree( &regex );

	return 0;
}
