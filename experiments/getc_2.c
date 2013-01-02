#include <stdio.h>

int main()
{
	int c;

	while( ( c = fgetc( stdin ) ) != '\n' )
		putchar( c );

	return 0;
}
