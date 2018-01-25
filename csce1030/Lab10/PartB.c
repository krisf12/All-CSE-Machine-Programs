#include<stdio.h>
#include<string.h>

#define MAX_SIZE 10

void readFileIntData(FILE*, int*, int);


int main(void)
{

int i;
char input[30];
char txt[30];
int b[MAX_SIZE];
FILE *infile;

printf("Enter a file name:\n");
gets(input);
printf("Enter an extension:\n");
gets(txt);

strcat(input, txt);
printf("%s", input);
printf("\n\n");

infile = fopen(input,"r");

readFileIntData(infile, b, MAX_SIZE);

fclose(infile);

for(i=0; i<MAX_SIZE; i++)
printf("%d\n", b[i]);
printf("\n");

return 0;
}


void readFileIntData(FILE* infile, int b[], int size)
{
	int i;

	for(i=0; i<size; i++)
	{
		fscanf(infile, "%d", &b[i]);
	}
}
