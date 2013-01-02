#include <stdlib.h>
#include <regex.h>
#include <stdio.h>
#include <sys/types.h>

int main()
{
	regex_t re;
	int re_err;
	char s[100] = "abc";

	if( ( re_err = ( regcomp( &re, "b", 0 ) ) ) )
	{
		fprintf( stderr, "Could not compile regex\n" );
		exit( 1 );
	}

	if( !( re_err = ( regexec( &re, s, 0, NULL, 0 ) ) ) )
		puts( "Match" );
	else if( re_err == REG_NOMATCH )
		puts( "No match" );
	else
	{
		regerror( re_err, &re, s, sizeof( s ) );
		fprintf( stderr, "Regex match failed: %s\n", s );
		exit( 1 );
	}

	regfree( &re );

	return 0;
}
