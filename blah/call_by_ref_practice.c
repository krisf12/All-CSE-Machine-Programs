#include<stdio.h>

/* Function prototypes */
void by_value(int a);
void by_ref(int *a);

/* The main functino should be the first function in your program */
int main(void)
{
	int x = 5;
	
	printf("\nBefore first function call x = %d\n",x);
	by_value(x);
	printf("After first function call x = %d\n",x);
	by_ref(&x);
	printf("After second function call x = %d\n\n",x);

	return 0;
}

/* Call by value: The parameter a will be equal to the VALUE of the
 parameter that has been passed to the function. The original parameter 
 is not changed, as only its value has been copied. */
void by_value(int a)
{
	printf("\n\tCALL BY VALUE:\n");
	printf("\t\t a=%d\n",a);
	a=10;
	printf("\t\t a=%d\n\n",a);
}

/* Call by reference: a refers to an address. Using * we can obtain
 the value stored at the address that is referenced. Since we refer to 
 an address, the change will affect the original parameter */
void by_ref(int* a)
{
	printf("\n\tCALL BY REFERENCE:\n");
	printf("\t\t a=%d\n",*a);
	*a=20;
	printf("\t\t a=%d\n\n",*a);
}


