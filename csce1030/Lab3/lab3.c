#include <stdio.h>
int main(void)
{
	int x;

	printf("Welcome to Lab3! \n");
	printf("Please enter an integer: \n");
	scanf("%d",&x);
	printf("\nYou just typed: %d.",x);
	printf("\n");
	if(x<0)
	printf("Your number is negative\n");

	else if(x>0)
	printf("Your number is positive\n");

	else printf("Your number is neither positive nor negative\n");

	return 0;
}
