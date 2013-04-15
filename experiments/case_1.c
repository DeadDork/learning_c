////////////////////////////////////////////////////////////////////////////////
// Comments

// Expores using expressions in a switch statement's case expression.

// Conclusion: you most certainly *can* use expression in a switch statement.

// Bug: if you enter a number, then put in some non-newline white space, then
// EOF (in my implementation, press ^D), this program will not exit.

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
// Symbolic Constants

#define FALSE 0
#define TRUE 1

#define YESERR -1
#define NOERR 1

////////////////////////////////////////////////////////////////////////////////
// Structs

typedef struct num // NUMBer
{
	int err; // ERRor (TRUE if it is an error)
	int val; // VALue ( INT_MIN - INT_MAX )
} Num;

////////////////////////////////////////////////////////////////////////////////
// Function Prototypes

int is_ws ( char c );

int is_num ( char c );

Num getn( void );

////////////////////////////////////////////////////////////////////////////////
// Functions

int is_ws ( char c )
{
	return ( c == '\n' || c == '\t' || c == ' ' ) ? TRUE : FALSE;
}

int is_num ( char c )
{
	return ( c >= '0' && c <= '9' ) ? TRUE : FALSE;
}

Num getn( void )
{
	int c, in_num = FALSE, sign = 1; // Character, IN A NUMber, SIGN (default is positive)
	Num total;

	while( ( c = getchar() ) != EOF )
	{
		/* Legitimate end of number string */
		if( in_num && is_ws( c ) )
		{
			total.val *= sign;
			total.err = NOERR;
			break;
		}
		/* Start of positive number string */
		else if( !in_num && is_num( c ) )
		{
			in_num = TRUE;
			total.val = c - '0';
		}
		/* Start of negative number string */
		else if( !in_num && c == '-' )
		{
			in_num = TRUE;
			sign = -1;
			total.val = 0;
		}
		/* Concatenate latest value to number string */
		else if( in_num && is_num( c ) )
		{
			total.val = total.val * 10 + c - '0';
		}
		/* Chomp white space */
		else if( is_ws( c ) );
		/* Bad number string */
		else
		{
			total.err = YESERR;
			break;
		}
	}

	ungetc( c, stdin ); // To make sure EOF is pushed back into stdin
	return total;
}

////////////////////////////////////////////////////////////////////////////////
int main( void )
{
	Num x; // number variable

	while( TRUE )
	{
		x = getn();

		/* breaks an infinite loop when getn produces an EOF */
		if( getchar() == EOF )
		{
			break;
		}

		/* Determines if the number is negative, positive, or not a number */
		switch( x.err + ( x.val >= 0 ) )
		{
			case 1: // x.err = NOERR & x.val < 0
				printf( "%d is negative\n", x.val );
				break;
			case 2: // x.err = NOERR & x.val >= 0
				printf( "%d is positive\n", x.val );
				break;
			default: // x.err = YESERR & x.val < 0 or >= 0
				printf( "ERROR\n" );
				break;
		}
	}

	return 0;
}
