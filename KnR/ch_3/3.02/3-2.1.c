////////////////////////////////////////////////////////////////////////////////
// Comments

// Solution to ex. 3-2.
//
// Reads & prints input, with two possible contingencies:
//
//// 1) If it reads a newline or tab character before a literal '\n' or '\t', 
//// then it prints this newline or tab--and all subsequent newline and tab
//// characters--respectively as a literal '\n' or '\t'.
//
//// 2) If it reads a literal '\n' or '\t' before a newline or tab character,
//// then it prints this literal '\n' or '\t'--and all subsequent literal '\n'
//// and '\t's--respectively as a newline or tab character.

// N.B. I started working on this, worked worked worked, finished--and realized
// I had a solution that printed correct output, but which completely failed
// the exercise. I then wrote a correct version, but didn't have the heart to
// delete what I'd already made. This is that "failure".

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
// no idea how to address it correctly. Ugly workarounds abound, though, and
// I include one in this folder. To use, simply pipe output into it, e.g.
//
//// $./3-2 <test_only-ws_no-term-nl | ./newliner
// or
//// $./3-2 <test_only-ws_term-nl | ./newliner

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
// Symbolic Constants

#define DFLT 0 // DeFauLT (i.e. neither converting white space characters to 
               // literal representations, nor vice versa)
#define WS2L 1 // White Space TO Literal (i.e. convert white space
               // characters to literal representations)
#define L2WS 2 // Literal TO White Space (i.e. convert literal representations
               // to white space characters)

////////////////////////////////////////////////////////////////////////////////
int main( void )
{
	int cdbl[ 2 ], cnvstt = DFLT; // DouBLe Character string, CoNVersion STaTe

	while( ( cdbl[ 1 ] = getchar() ) != EOF )
	{
		/* Reads ahead if the latest input character is a '\' */
		if( cdbl[ 1 ] == '\\' )
		{
			cdbl[ 0 ] = cdbl[ 1 ];
			if( ( cdbl[ 1 ] = getchar() ) == EOF ) // prevents overflow
			{
				putchar( cdbl[ 0 ] );
				break;
			}
		}

		/* Determines conversion state: white space to literal or vice versa */
		if( cnvstt == DFLT )
		{
			if( cdbl[ 0 ] == '\\' && ( cdbl[ 1 ] == 'n' || cdbl[ 1 ] == 't' ) )
			{
				cnvstt = L2WS;
			}
			else if( cdbl[ 1 ] == '\n' || cdbl[ 1 ] == '\t' )
			{
				cnvstt = WS2L;
			}
		}

		/* Prints output */
		if( cdbl[ 0 ] == '\\' )
		{
			if( cnvstt == L2WS && cdbl[ 1 ] == 'n' )
			{
				putchar( '\n' );
			}
			else if( cnvstt == L2WS && cdbl[ 1 ] == 't' )
			{
				putchar( '\t' );
			}
			else
			{
				printf( "%c%c", cdbl[ 0 ], cdbl[ 1 ] );
			}

			cdbl[ 0 ] -= 1; // makes cdbl[ 0 ] != '\'
		}
		else if( cnvstt == WS2L && cdbl[ 1 ] == '\n' )
		{
			printf( "\\n" );
		}
		else if( cnvstt == WS2L && cdbl[ 1 ] == '\t' )
		{
			printf( "\\t" );
		}
		else
		{
			putchar( cdbl[ 1 ] );
		}
	}

	return 0;
}
