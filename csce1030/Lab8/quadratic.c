/*Kristian Forestier
//Date: 10/25/13
//Purpose: This program solves quadratic equations
*/

#include<stdio.h>
#include<math.h>

double root1(double a, double b, double c);
double root2(double a, double b, double c);

int main(void)					/*main function*/
{
	double a, b, c;

	printf("\n");
	printf("Enter three parameters: A B C\n", a, b, c); /*prompts the user*/
	scanf("%lf %lf %lf", &a, &b, &c);
	printf("\nYour quatratic looks like: %lfx^2+%lfx+%lf", a, b, c); /*shows them their input in quadratic form*/
	root1(a, b, c);
	root2(a, b, c);
	
return 0;
}       					/*end of main*/

double root1(double a, double b, double c)
{
	double solution;

	solution= ((-b-(sqrt((b*b)-(4*a*c))))/(2*a));	/*square root equation 1*/
	printf("\nThe first solution is: %lf\n", solution);
}

double root2(double a, double b, double c)
{
	double solution;
	
	solution= ((-b+(sqrt((b*b)-(4*a*c))))/(2*a));   /*square root equation 2*/
	printf("The second solution is: %lf\n", solution);
}
