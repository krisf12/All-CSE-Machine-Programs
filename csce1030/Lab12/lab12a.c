/*
//Kristian Forestier
//Date: 11/22/13
//Purpose: 
*/

#include<stdio.h>
#include<string.h>

int main(void)
{
FILE *f;
int i,j;
int size;
char fname[30];

	printf("Enter a file name: ");
	scanf("%s",fname);

	f=fopen(fname, "r");
	fscanf(f,"%d",&size);

int matrix[size][size];

	for(i=0; i<size; i++)
	{
		
		for(j=0; j<size; j++)
		{
		fscanf(f,"%d",&matrix[i][j]);
		}
	}
int matrix2[size][size];

	for(i=0; i<size; i++)
	{
		for(j=0; j<size; j++)
		{
		fscanf(f,"%d",&matrix2[i][j]);
		}
	}

fclose(f);

int add[size][size];
/*
	for(i=0; i<size; i++)
	{
		for(j=0; j<size; j++)
		{
		printf("%d\t",matrix[i][j]);
		}
	}

	for(i=0; i<size; i++)
	{
		for(j=0; j<size; j++)
		{
		printf("%d\t",matrix2[i][j]);
		}
	}
*/	
	for(i=0; i<size; i++)
	{
		for(j=0; j<size; j++)
		{	
		add[i][j]= matrix[i][j]+matrix2[i][j];
		}
	}

	for(i=0; i<size; i++)
	{
	printf("\n");
		for(j=0; j<size; j++)
		{
		printf("%d  ",add[i][j]);
		}
	printf("\n");
	}


return 0;
}
