#include<stdio.h>
#include<stdlib.h>

void swap(int*, int*);

int main()
{
	int a=1;
	int b=2;

	printf("Before swap: a=%d b=%d\n", a,b);
	swap(&a,&b);
	printf("After swap: a=%d b=%d\n", a,b);

	return 0;


}

void swap(int *x, int *y)
{
	int temp;

	temp=*x;
	*x=*y;
	*y=temp;	

	printf("Inside swap: x=%d y=%d\n",*x,*y);

return;
}

