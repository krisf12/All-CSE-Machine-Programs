#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    /* We want to use all of these as arrays */
    int *a, *b;
    char *x, *y;

	struct person{
		char* name;
	};    
	struct person p;
	p.name=malloc(20*sizeof(char));

    /* allocate memory */
    a = calloc(5,sizeof(int));
    x = calloc(8,sizeof(char));
    
    b = malloc(10 * sizeof(int));
    y = malloc(4 * sizeof(char));
    
    
    int i;
    
    printf("\nContents of int array a:\n");
    for(i=0;i<5;i++)
        printf("%d\t",a[i]);

   for(i=0;i<5;i++)	
   {
	printf("%c",x[i]);
   }   

   printf("\nContents of int array b:\n");
   for(i=0;i<10;i++)
        printf("%d\t",b[i]);

 
    free(a);
    free(b);
    free(x);
    free(y);
    
    
	return 0;
}

