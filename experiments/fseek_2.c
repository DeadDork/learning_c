////////////////////////////////////////////////////////////////////////////////
// Comments

// fseek with stdin

////////////////////////////////////////////////////////////////////////////////
// Libraries

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
int main()
{
	int c;

	while( ( c = fgetc( stdin ) ) != EOF )
	{
		fputc( c, stdout );
	}

	return 0;
}
