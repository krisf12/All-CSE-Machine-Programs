/*
Kristian Forestier
10/4/2013
This program asks the user for input.
*/

#include<stdio.h>

int main(void)
{
int option;
float int1, int2; /*these are the variables*/
float total;
{
printf("0: Add\n1: Subtract\n2: Multiply\n3: Divide\n"); /*these are the options*/
printf("\n");

printf("Please select one of these options:\n");
scanf("%d", &option);
printf("you picked: %d\n", option);
                                                   /*user inputs here*/
printf("Please pick two integers:\n");
scanf("%g%g", &int1, &int2);
printf("you picked %g and %g\n", int1, int2);
}

switch(option)          /*begin swtich*/
{
case 0:
total= (int1 + int2);                                       /*first case*/
printf("adding these two numbers gives you: %g\n", total);
break;

case 1:
total= (int1 - int2);
printf("subtracting thse two numbers gives you: %g\n", total); /*second*/
break;

case 2:
total= (int1 * int2);
printf("multiplying these two numbers gives you: %g\n", total); /*third*/
break;

case 3:
total= (int1 / int2);
printf("dividing these two numbers gives you: %g\n", total);  /*fourth*/
break;

default:
printf("you did not enter an option between 0 and 3\n");  /*the default for all other cases*/
break;
}

return 0;  /*end*/
}
