// Kristian Forestier
// 3/21/14
// Lab7
// encryption


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{

//FILE * f;

//f = fopen("sentences","r");


char letters[27];
char alphabet[30];
char key[30];
int number, i;

	for(i=0; i<100; i++)
	{
		//scanf("%s", alphabet);   //these were supposed to scan the first two lines of code and ignore them
		//scanf("%s", key);
		scanf("%d %s",&number, &letters[i]);	
	}
	
		printf("%c", letters[i]);

//fclose(sentences);

	for(i=0;i<100;i++)  //this for loop is to replace each letter with the encrypted letter
	{

		if(letters[i]=='a')
		letters[i]= 'f';	
		else if(letters[i]=='b')
		letters[i]= 'c';
		else if(letters[i]=='c')
		letters[i]= 's';
		else if(letters[i]=='d')
		letters[i]= 'a';
		else if(letters[i]=='e')
		letters[i]= 'n';
		else if(letters[i]=='f')
		letters[i]= 'k';
		else if(letters[i]=='g')
		letters[i]= 'r';
		else if(letters[i]=='h')
		letters[i]= 'p';
		else if(letters[i]=='i')
		letters[i]= 'o';
		else if(letters[i]=='j')
		letters[i]= 'y';
		else if(letters[i]=='k')
		letters[i]= 'g';
		else if(letters[i]=='l')
		letters[i]= 'u';
		else if(letters[i]=='m')
		letters[i]= 'i';
		else if(letters[i]=='n')
		letters[i]= 'm';
		else if(letters[i]=='o')
		letters[i]= 'q';
		else if(letters[i]=='p')
		letters[i]= 'v';
		else if(letters[i]=='q')
		letters[i]= 't';
		else if(letters[i]=='r')
		letters[i]= 'w';
		else if(letters[i]=='s')
		letters[i]= 'x';	
		else if(letters[i]=='t')
		letters[i]= 'j';
		else if(letters[i]=='u')
		letters[i]= 'l';
		else if(letters[i]=='v')
		letters[i]= 'b';
		else if(letters[i]=='w')
		letters[i]= 'd';
		else if(letters[i]=='x')
		letters[i]= 'e';
		else if(letters[i]=='y')
		letters[i]= 'z';
		else if(letters[i]=='y')
		letters[i]= 'h';
	}

	for(i=0;i<100;i++)
	{
		printf("%c", letters[i]);
	}

return 0;
}
