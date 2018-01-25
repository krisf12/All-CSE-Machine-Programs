#include<stdio.h>

#define MAX_SIZE 10

int main(void)
{
	double array[MAX_SIZE];
	int i;


	array[0]= 1.0;
	printf("%g\t",array[0]);

	for(i=1; i<MAX_SIZE; i++)
	{
		array[i]= i*array[i-1];
		
		printf("%g\t", array[i]);
	}

printf("\n\n");

for(i=0; i<MAX_SIZE; i=i+2)
{
	array[i]= array[i]*array[i];
	
	printf("%g\t", array[i]);
}

printf("\n\n");

for(i=MAX_SIZE-1; i>=0; i--)
{
	//array[i]= array[i]*array[i];
	
	printf("%g\t", array[i]);
}
printf("\n\n");
	
return 0;
}
