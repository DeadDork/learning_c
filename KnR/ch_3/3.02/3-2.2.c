////////////////////////////////////////////////////////////////////////////////
// Comments

// Solution to ex. 3-2.
//
// Reads & prints input, with two possible contingencies:
//
//// 1) If it reads an escape character before a literal representation of it,
//// then it prints this escape character--and all subsequent escape
//// characters--as the respective literal representation.
//
//// 1) If it reads a literal representation of an escape character before an
//// escape character, then it prints this literal represenation--and all
//// subsequent literal representations--as the respective escape character.

// N.B. I started working on this, worked worked worked, finished--and realized
// I had a solution that printed correct output, but which completely failed
// the exercise. I then wrote a correct version, but didn't have the heart to
// delete what I'd already made. This is the correct version.

// N.B. the wording of the exercise suggests that the input & output strings
// for escape() and descape() should be for an entire line. Without realloc(),
// I would have to use an arbitrary line length, and that opens the code to all
// kinds of horrible PITA. Accordingly, the input and output are both double
// character strings, the input of which reads ahead when necessary and pushes
// the former head to the tail.

// N.B. '\\' i ambiguous: is it an escaped backslash or is it two backslashes?
// I read it as two backslashes.

// Bug: the final newline is very tricky. Depending on the source of the stdin,
// the terminal will either add it's own newline automatically or not. For
// example,
//
//// $printf 'hello\\n\ngoodbye' | ./3-2
// or
//// $./3-2 <test_only-ws_no-term-nl
//
// *will not* receive a final newline. However,
//
//// $echo -e 'hello\\n\ngoodbye' | ./3-2
// or
//// $./3-2 <test_only-ws_term-nl
//
// *will* receive a final newline. This is a function of the system, and I have
// no idea how to address this correctly. Ugly workarounds abound, though, and
// I include one in this folder. To use, simply pipe output into it, e.g.
//
//// $./3-2 <test_only-ws_no-term-nl | ./newliner
// or
//// $./3-2 <test_only-ws_term-nl | ./newliner

// Bug (?): this program will neither escape() nor descape() octal or hex
// number. Frankly, I can't quite figure out what that even means, considering
// that input is ASCII...

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
// Symbolic Constants

#define FALSE 0
#define TRUE 1

#define DFLT 0 // DeFauLT (i.e. neither convert white space characters to 
               // literal representations, nor vice versa)
#define EC2LR 1 // Escape Character TO Literal Representation (i.e. convert
                // escape characters to their respective literal representation)
#define LR2EC 2 // Literal Representation TO Escape Character (i.e. convert
                // literal representations of escape characters to their
                // respective escape character)

////////////////////////////////////////////////////////////////////////////////
// Function Prototypes

int escape( int in[], int out[] );
/* Converts an escape character to its literal representation
   (e.g. BELL = '\a').

   `in[]` = in[ 1 ] is the potential escape character.

   `out[]` = The literal representation of the escape character.

   Returns TRUE if in[ 1 ] is an escape character; returns FALSE otherwise. */

int descape( int in[], int out[] );
/* Converts a literal representation of an escape character to its respective
   escape character (e.g. '\a' = BELL).

   `in[]` = A short input string beginning with '\'.

   `out[]` = A short output string beginning with '\'.

   Returns TRUE if in[ 1 ] is an escape character; returns FALSE otherwise. */

////////////////////////////////////////////////////////////////////////////////
// Functions

int escape( int in[], int out[] )
{
	switch( in[ 1 ] )
	{
		case '\a':
			out[ 0 ] = '\\';
			out[ 1 ] = 'a';
			return TRUE;
		case '\b':
			out[ 0 ] = '\\';
			out[ 1 ] = 'b';
			return TRUE;
		case '\f':
			out[ 0 ] = '\\';
			out[ 1 ] = 'f';
			return TRUE;
		case '\n':
			out[ 0 ] = '\\';
			out[ 1 ] = 'n';
			return TRUE;
		case '\r':
			out[ 0 ] = '\\';
			out[ 1 ] = 'r';
			return TRUE;
		case '\t':
			out[ 0 ] = '\\';
			out[ 1 ] = 't';
			return TRUE;
		case '\v':
			out[ 0 ] = '\\';
			out[ 1 ] = 'v';
			return TRUE;
		case '\?':
			out[ 0 ] = '\\';
			out[ 1 ] = '?';
			return TRUE;
		case '\'':
			out[ 0 ] = '\\';
			out[ 1 ] = '\'';
			return TRUE;
		case '\"':
			out[ 0 ] = '\\';
			out[ 1 ] = '"';
			return TRUE;
	}

	return FALSE;
}

int descape( int in[], int out[] )
{
	if( in[ 0 ] == '\\' )
	{
		switch( in[ 1 ] )
		{
			case 'a':
				out[ 1 ] = '\a';
				return TRUE;
			case 'b':
				out[ 1 ] = '\b';
				return TRUE;
			case 'f':
				out[ 1 ] = '\f';
				return TRUE;
			case 'n':
				out[ 1 ] = '\n';
				return TRUE;
			case 'r':
				out[ 1 ] = '\r';
				return TRUE;
			case 't':
				out[ 1 ] = '\t';
				return TRUE;
			case 'v':
				out[ 1 ] = '\v';
				return TRUE;
			case '?':
				out[ 1 ] = '\?';
				return TRUE;
			case '\'':
				out[ 1 ] = '\'';
				return TRUE;
			case '"':
				out[ 1 ] = '\"';
				return TRUE;
		}
	}

	out[ 0 ] = in[ 0 ]; out[ 1 ] = in[ 1 ];
	return FALSE;
}

////////////////////////////////////////////////////////////////////////////////
int main( void )
{
	int prec[ 2 ], pstc[ 2 ]; // PRE-Conversion, POST-Conversion 
	int cnvstt = DFLT; // CoNVersion STaTe

	while( ( prec[ 1 ] = getchar() ) != EOF )
	{
		/* Reads ahead if the latest input character is a '\' */
		if( prec[ 1 ] == '\\' )
		{
			prec[ 0 ] = prec[ 1 ];
			if( ( prec[ 1 ] = getchar() ) == EOF ) // prevents overflow
			{
				putchar( prec[ 0 ] );
				break;
			}
		}

		/* Determines conversion state: escape character to literal
		   representation, or vice versa */
		if( cnvstt == DFLT )
		{
			if( prec[ 0 ] == '\\' )
			{
				switch( prec[ 1 ] )
				{
					case 'a': case 'b': case 'f': case 'n': case 'r':
					case 't': case 'v': case '?': case '\'': case '"':
						cnvstt = LR2EC;
				}
			}
			else
			{
				switch( prec[ 1 ] )
				{
					case '\a':  case '\b': case '\f': case '\n': case '\r':
					case '\t': case '\v': case '\?': case '\'': case '\"':
						cnvstt = EC2LR;
				}
			}
		}

		/* Prints output */
		if( prec[ 0 ] == '\\' )
		{
			if( descape( prec, pstc ) && cnvstt == LR2EC )
			{
				putchar( pstc[ 1 ] );
			}
			else
			{
				printf( "%c%c", pstc[ 0 ], pstc[ 1 ] );
			}
			prec[ 0 ] = 'X'; // prec[ 0 ] must be set to anything but '\\'
		}
		else if( cnvstt == EC2LR && escape( prec, pstc ) )
		{
			printf( "%c%c", pstc[ 0 ], pstc[ 1 ] );
		}
		else
		{
			putchar( prec[ 1 ] );
		}
	}

	return 0;
}
