#include<iostream>
#include<cstdlib>
#include<stdio.h>
#include<string>

using namespace std;

void printargs(int, char**);
void execute(int, char**);


int main( int argc, char**argv)
{

	printargs(argc, argv);
	execute(argc, argv);

	return 0;
}
	
void printargs(int argc, char**argv)
{
	int i=0;

	for(i=0; i<argc; i++)
	{
		printf("Arg %d = %s\n", i, argv[i]);
	}

}

void execute(int argc, char **argv)
{
	int i, j;	
	char *buffer;
	int bufferSize = 0;

for( i = 0; i < argc; i++ )
    bufferSize += strlen(argv[i]) + 1;
	
	buffer = (char *)malloc(bufferSize);
	buffer[0] = '\0';
	strcpy(buffer,"wc ");

for( i = 1; i < argc; i++ )
{
    strcpy(buffer+strlen(buffer), argv[i]);
    strcpy(buffer+strlen(buffer), " ");
}

printf("buffer = %s\n", buffer);
system (buffer);
	
}
