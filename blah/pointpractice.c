#include<stdio.h>

int main(void)
{

	int *x;
	int *y, *z;
	int a = 1;
	int b;

	x= &a;		/*basically, x is pointing to a so it is equal to a, which is 1.*/

	b= *x;         /* And then b is set to equal x.. which is now 1.. and this causes b to be  set to 1 and is not affected by any other changes of a*/

	printf("\n\t a = %d \t x = %d \t b = %d\n", a,*x,b);
	a = 8;
	(*x)++;
	printf("\n\t a = %d \t x = %d \t b = %d\n", a,*x,b);
	a = 5;
	b = *x;
	b++;
	printf("\n\t a = %d \t x = %d \t b = %d\n", a,*x,b);
	
	return 0;
}
