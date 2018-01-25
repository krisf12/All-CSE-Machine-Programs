//Kristian Forestier
// 2/28/14
//Lab6
//

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void count(char *, int *, int *); // function prototype for counting

int main (void)
{
	int N;
	int i;
	char *text[20];
	int counting=0;
	int sum=0;
		
	for(i=0;i<20;i++)   // this for loop scans the first number and then uses that number for the size of that word and then scans the word and moves on to the next line
	{
		scanf("%d", &N);

		text[i]= (char *) malloc(N * sizeof(char)); //allocates the memory for each word

		scanf("%s", text[i]);
	}
	
	printf("\n12345678901234567890123456789\n");
	
	for(i=0; i<20; i++)   // this for loop calls the function one word at a time
	{
		count(text[i], &counting, &sum); //calls the word, number of t's and the sum
	}	


return 0;
}


void count(char *text, int *counting, int *sum) //this function checks the ammount of times 't' shows up in a word and uses a counter that increments each time it shows up. Then it prints the counter and the word and the sum.
{
	int i;
	(*counting)=0;
	(*sum)=0;

	for(i=0;i<strlen(text);i++)  //scans through the word
	{
		if(text[i] == 't') //checks for 't'
		(*counting)++;

		(*sum) += text[i]; //finds the sum
	}

	printf("%15s %d%10d\n",text,(*counting), (*sum)); //prints everything with right alignment

}
