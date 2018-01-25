/*
//Kristian Forestier
//Date: 11/1/13
//Purpose: this program calculates quadratic equations.
*/

#include<stdio.h>
#include<math.h>

void root(double a, double b, double c, double *solution1, double *solution2) /*begin root function*/
{

	printf("\n");
	printf("Enter three parameters: A B C\n", a, b, c); /*prompts the user*/
	scanf("%lf %lf %lf", &a, &b, &c);
	printf("\nYour quatratic looks like: %gx^2+%gx+%g", a, b, c);

*solution1= ((-b-(sqrt((b*b)-(4*a*c))))/(2*a));   /*these are the equations*/
*solution2= ((-b+(sqrt((b*b)-(4*a*c))))/(2*a));
printf("\nThe solutions are: %g and %g\n", *solution1, *solution2); /*uses pointers for reference*/
}  /*end root function*/


int main(void) /*begin main*/ /*main prints what function root does*/
{
double solution1, solution2, a, b, c;

	root(a, b, c, &solution1, &solution2); /*calls the pointers*/
}      /*end main*/
