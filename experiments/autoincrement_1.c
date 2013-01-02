#include <stdio.h>

int main()
{
	int x = 5;
	int y = 15;

	printf( "x = [%d]\n", x );
	printf( "--x = [%d]\n", --x );
	printf( "--x = [%d]\n", --x );
	printf( "y = [%d]\n", y );
	printf( "y-- = [%d]\n", y-- );
	printf( "y-- = [%d]\n", y-- );

	return 0;
}
