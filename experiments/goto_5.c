// Explores goto scoping further.

// Conclusion: goto scoping rules are weird: functions are scoped, but not
// {}'s. This is very much unlike var's.

#include <stdio.h>

int main(void) {
	goto label1;
	goto end;

	{
		label1:
		printf("Inside {}'s\n");
	}

	end:
	return 0;
}
