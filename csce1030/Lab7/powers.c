/*
//Author: Kristian Forestier
//Date: 10/18/13
//Purpose: This program takes an input and raises to to the power of that input.
*/

#include<stdio.h>

int floop(int x);
int wloop(int x);   /*these are my 3 functions and loops*/
int dwloop(int x);

int n;
int loops;    /*these are global variables*/

int main(void)     /*main function*/
{
	printf("\nEnter an integer you would like to raise 2 to the power of:\n"); /*their input*/
	scanf("%d", &n);
	printf("Select one of these methods:\n\n1: for-loop\n2: while-loop\n3: do-while\n"); /*the menu*/
	scanf("%d",&loops);

	switch(loops)
		{
		case 1:
		printf("using the for loop you get: %d", floop(n)); /*this will print the result of floop*/
		printf("\n\n");
		break;
		
		case 2:
		printf("using the while loop you get: %d", wloop(n)); /*this will print the result of wloop*/
		printf("\n\n");
		break;
		
		case 3:
		printf("using do while loop you get: %d", dwloop(n));/*this will print the result of dwloop*/
		printf("\n\n");
		break;
		}
}                  /*end of main*/

int floop(int x)      /*for loop function*/
{
	int i;
	int result=1;

	for(i= 1; i <= x; i++)
	{
	result= (result*2);
	}
return result;
}

int wloop(int x)     /*while loop function*/
{
	int i=1;
	int result=1;

	while(i<=x)
	{
	i++;
	result=(result*2);
	}
return result;
}

int dwloop(int x)    /*do while loop function*/
{
	int i=1;
	int result=1;

	do
	{
	i++;
	result=(result*2);
	}
	while(i<=x);
return result;
}
