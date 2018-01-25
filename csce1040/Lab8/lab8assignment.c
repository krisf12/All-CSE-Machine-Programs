//Kristian Forestier
//kristianforestier@my.unt.edu
//Lab8
//3/28/14

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void encrypt(char *, char *);  //function prototypes
void decrypt(char *, char *);


int main(int argc, char *argv[])
{
	if(argc==4 && strcmp(argv[1], "encrypt")==0) //this checcks for encrypt user input
	{
		encrypt(argv[2], argv[3]); //calls function
	}

	if(argc==4 && strcmp(argv[1], "decrypt")==0) //this checks for decrypt user input
	{
		decrypt(argv[2], argv[3]); //calls function
	}
	
	else if(argc<4 || argc>4)
	{
		printf("ERROR Try Again"); //if user types incorrect input
	}

}

void encrypt(char *readfile, char *writefile) //this function encrypts the text and prints it into the file 
{
	int i;
	char letters;
	FILE *read, *write;

	printf("\nin encrypt\n"); //tells user that encrypt went through

	read = fopen(readfile, "r"); //opens file
	write = fopen(writefile, "w"); //opens file

	while(fscanf(read, "%c", &letters)!=EOF) //loops until end of file
	{
		if(letters == ' ')  //for spacing
		fprintf(write, "%c", ' '); //for spacing
		fprintf(write, "%d", ~letters+1); //encryption process
	}
	
	fclose(read);
	fclose(write);
}


void decrypt(char *readfile, char *writefile) //this function does the same as the first but backwards so that it can decrypt
{
	int i;
	int letters;
	FILE *read, *write;

	printf("\nin decrypt\n"); //tells user that decrypt went through

	read = fopen(readfile, "r");
	write = fopen(writefile, "w");

	while(fscanf(read, "%d", &letters)!=EOF)
	{
		fprintf(write, "%c", ~letters+1); //decryption process
	}

	fclose(read);
	fclose(write);
}
