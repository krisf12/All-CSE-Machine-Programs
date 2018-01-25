//
// Author: Kristian Forestier
// Date: 9/20/13
// Purpose: This program takes an integer, echo's it back to the user and, depending on the integer inputted, does calculations. // 


#include <stdio.h>
#include <math.h> /*this library is needed to make calculations*/
int main(void)
{
	int x;
	int sqrofneg;   /*these are my variable names*/
	int cubofpos;

	printf("Welcome to Lab3! \n");         /*this will be the first thing to show up*/
	printf("Please enter an integer: \n"); /*this will prompt the user to enter an integer*/
	scanf("%d",&x);
	
	printf("\nYou just typed: %d.",x); /*this is where the integer is echoed back to the user*/
	printf("\n");

	if(x<0){   
	printf("Your number is negative\n");
	sqrofneg=((x)*(x));                /*this is the formula for calculating the square of the negative number*/
	printf("the square of your number is: %d\n",sqrofneg);
}
	else if(x>0){
	printf("Your number is positive\n");
	cubofpos=((x)*(x)*(x));
	printf("the cube of your number is: %d\n",cubofpos);
}
	else printf("Your number is neither positive nor negative\n");

	return 0;
}
