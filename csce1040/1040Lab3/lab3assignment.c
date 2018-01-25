/*
// Kristian Forestier
// Lab 3
// 2/7/14
*/

#include<stdio.h>
#include<stdlib.h>
#define MAX 23

int  liarliar(int); //function prototype

int main(void)
{
	int number, sum, i;

	printf("Enter a number between 1 and 23: ");
	scanf("%d", &number);  //scans for user input

	if(number <= MAX && number >0)
		{
			for(i=1; i<=number; i++) //makes the user input the max size and loops that ammount of times
			{
				sum = liarliar(i); //calls the function liarliar
				printf("Liar-Liar(%d) =       %d\n", i, sum);
			}
		}

	else printf("\ninvalid choice\n\n");	//if the user types a number greater than 23 or a letter

return 0;
}

int liarliar(int number)
{
	int sum	= -1; //sets sum equal to -1

	if(number>2) //checks for all numbers greater than 2 but less than the max
	{
		sum= 2*(liarliar(number-1) + liarliar(number-2));
	}

	return sum; //returns the calculation
}
