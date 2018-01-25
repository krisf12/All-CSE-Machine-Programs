/*Kristian Forestier
//Date: 10/25/13
//Purpose: this program counts the number of times a lowercase letter appears in text.
*/

#include<stdio.h>

int main(void)
{
	int count[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	char length[500];
	int i = 0;
	char c;

	while((c=getchar())!= EOF) /*while loop for file with text until the end of file is reached*/
	{
		length[i] = c;
		i++;
	} 
 
	for(i=0; i<500; i++)
	{
		switch(length[i]) /*switch statement for the letters*/
		{
		case 'a': 
			count[0]++; break;
		case 'b':
			count[1]++; break;
		case 'c':
			count[2]++; break;
		case 'd':
                        count[3]++; break;
		case 'e':
                        count[4]++; break;
		case 'f':
                        count[5]++; break;
		case 'g':
                        count[6]++; break;
		case 'h':
                        count[7]++; break;
		case 'i':
                        count[8]++; break;
		case 'j':
                        count[9]++; break;
		case 'k':
                        count[10]++; break;
		case 'l':
                        count[11]++; break;
		case 'm':
                        count[12]++; break;
		case 'n':
                        count[13]++; break;
		case 'o':
                        count[14]++; break;
		case 'p':
                        count[15]++; break;
		case 'q':
                        count[16]++; break;
		case 'r':
                        count[17]++; break;
		case 's':
                        count[18]++; break;
		case 't':
                        count[19]++; break;
		case 'u':
                        count[20]++; break;
		case 'v':
                        count[21]++; break;
		case 'w':
                        count[22]++; break;
		case 'x':
                        count[23]++; break;
		case 'y':
                        count[24]++; break;
		case 'z':
                        count[25]++; break;
		}				/*end of switch*/
	}

	for(i=0; i<26; i++) 			/*for loop for the print statement*/
	{
		printf("%d\n", count[i]);
	}
} 			/*end of main*/
