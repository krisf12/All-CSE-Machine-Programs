/*
//Kristian Forestier
//Date:11/1/13
//Purpose: This program finds the total number of vowels and nonvowels and prints them out for the user.
*/

#include<stdio.h>

void calc(char text[], int *vowel, int *nonvowel);  /*function prototype*/

int main(void)  /*begin main*/
{
	int vowel, nonvowel;
	char text[]= {"write a C program that will take a string"}; /*the original string*/
	calc(text, &vowel, &nonvowel);
 	printf("\nOriginal string: \n%s", text);
	printf("\n");
	printf("\nThe total number of vowels is: %d\n", vowel);
	printf("The total number of non vowels is: %d\n\n", nonvowel);

}     /*end of main*/


void calc(char text[], int *vowel, int *nonvowel) /*end of function calc*/
{
	int i;
	int vowels=0;     /*set vowels and non vowels equal to zero*/
	int nonvowels=0;

	for(i=0; text[i]!='\0'; i++)	/*for loop to check for vowels and nonvowels*/
	{
		switch(text[i]) 
		{
			case 'a': vowels++;
			break;
			case 'e': vowels++;
			break;
			case 'i': vowels++;
			break;
			case 'o': vowels++;
			break;
			case 'u': vowels++;
			break;
			case 'y': vowels++;
			break;
			default: nonvowels++;
		}
*vowel=vowels;        /*new variables to use for printing in main*/
*nonvowel=nonvowels;
	}
}                     /*end of function calc*/
