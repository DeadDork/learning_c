#include <stdio.h>

void memcopy( void* a, void* b, int sz );

void memcopy( void* a, void* b, int sz )
{
	char* src = a;
	char* dst = b;

	while( sz-- != 0 )
		*src++ = *dst++;
}

int main()
{
	char s1[] = "abcdefg";
	char s2[] = "lmnop";

	printf( "Before memcopy:\n\ts1 = [%s]\n\ts2 = [%s]\n", s1, s2 );
	memcopy( s1, s2, sizeof( s2 ) - 1 );
	printf( "After memcopy:\n\ts1 = [%s]\n\ts2 = [%s]\n", s1, s2 );

	return 0;
}
