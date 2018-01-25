#include<stdio.h>
#include<string.h>

int main(void)
{
FILE *f;
int i,j;
int size;
char fname[30];
int highest;
int lowest;

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

	highest=matrix[0][0];
	for(i=0; i<size; i++)
	{
		for(j=0; j<size; j++)

			if(highest<=matrix[i][j])
			{
			highest= matrix[i][j];
			}
	}		

	
	lowest=matrix[0][0];	
	for(i=0; i<size; i++)
	{
		for(j=0; j<size; j++)
		
			if(lowest>=matrix[i][j])
			{
			lowest= matrix[i][j];
			}	
	}


printf("the highest is %d",highest);
printf("the lowest is %d",lowest);
printf("\n\n");

return 0;
}
