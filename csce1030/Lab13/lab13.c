/*
//Kristian Forestier
//Date: 11/26/13
//Purpose: use malloc and calloc and argc/argv[].
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void reverse(char *word);                     /*function prototypes*/
void create_string(char *strung[], int argc);


int main(int argc, char *argv[])
{
	if(argc <3 && argc>1)
		printf("\nthere are no arguments\n\n");

	if(argc==3 && strcmp(argv[1], "reverse")==0)
		reverse(argv[2]);
		printf("\n");


	if(argc>=3 && strcmp(argv[1], "reverse")==0 || strcmp(argv[1], "reverse")!=0)
		create_string(argv, argc);
	if(argc==5)
	printf("five");
	
	if(argc==6)
		printf("fuck");
return 0;
}


void reverse(char *word) /*function to reverse if entered correctly*/
{
	int i;

	for(i=strlen(word); i>-1; i--)
		putchar(word[i]);

}


void create_string(char *strung[], int argc)  /*function to do arguments*/
{
	int i;
	char *stringy;

	stringy= calloc(200, 1);

	for(i=1;i<argc;i++)
	{
		char *strgay = calloc(200, 1); /*allocates memory*/
		strcpy(strgay, strung[i]);
		strcat(stringy, strgay);
		strcat(stringy, " ");
		free(strgay);
	}

printf("%s",stringy);

free(stringy); /*free memory*/

}

