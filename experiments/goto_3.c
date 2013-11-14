// Further explores goto scoping.

// Conclusion: this program suggests that goto's are not scoped by {}'s.

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int x = arc4random() % 2;

	if (x)
		goto label1;
	else
		goto label2;

	label1:
	printf("Lable1, outside\n");
	goto label3;

	label2:
	printf("Label2, outside\n");
	
	{
		if (x)
			goto label2;
		else
			goto label1;

		label1: // error: redefinition of label 'label1'
		printf("Lable1, inside\n");
		goto label3;

		label2: // error: redefinition of label 'label2'
		printf("Label2, inside\n");
	}

	label3:
	return 0;
}
