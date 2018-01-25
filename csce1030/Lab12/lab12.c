#include<stdio.h>

int main(void)
{
FILE *f;
int i,j;
int size;
char fname[30];
int highest1, highest2, highest3;

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

fclose(f);

	highest1=matrix[0][0];
	for(i=0; i<size; i++)
	{
		for(j=0; j<size; j++)
		if(i==0)
			if(highest1<=matrix[i][j])
			{
			highest1= matrix[i][j];
			}
	}		

	highest2=matrix[0][0];
	for(i=0; i<size; i++)
	{
		for(j=0; j<size; j++)
		if(i==1)
			if(highest2<=matrix[i][j])
			{
			highest2= matrix[i][j];
			}	
	}

        highest3=matrix[0][0];
        for(i=0; i<size; i++)
        {
                for(j=0; j<size; j++)
                if(i==2)
                        if(highest3<=matrix[i][j])
                        {
                        highest3= matrix[i][j];
                        }
        }

printf("\nthe highest at row 0: %d\n",highest1);
printf("the highest at row 1: %d\n",highest2);
printf("the highest at row 2: %d",highest3);
printf("\n\n");


return 0;
}
