/*
// Kristian Forestier
// 9/27/13
// This program computes the rate of interest on an ammount of money and a period of time.
*/

#include<stdio.h>
#include<math.h>
#define RATE .03
int main (void)

{
	int years;
	int investment;  /*these are variables*/
	double money;
	int i=0;	

	printf("How many years would you like to compute interest?\n\n");
	scanf("%d",&years); /*this prompts the user*/
	
	printf("How much money do you want to invest?\n\n");
	scanf("%lf",&money); /*this also prompts the user*/

	while(i != years){
	money=(money+(money*RATE)); /*this is the while loop*/
	i++;
	printf("In %d years your investment is %lf.\n",i,money);
}
	return 0;
}
