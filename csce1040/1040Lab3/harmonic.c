#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	float harmonic(int ,int);

	int base=0;
	float sum=0;

	printf("Enter the number of terms to generate: ");
	scanf("%d", &base);

	sum= harmonic(1, base);

	printf("Sum: %f\n", sum);


	return 0;
}


float harmonic(int x, int base)
{
float sum=0;

if(x == base)
	printf("1/%d\n", x);
else    {
	printf("1/%d + ", x);
	sum = harmonic(x+1, base);
	}
return (sum+(1.0/x));
}
