#include"homework4.h"

/*Function: readfile*/
/*this function reads the file and checks for lowercase letters. It then prints the number of each letter occurance*/
void readfile(double *count, char *length)
{
	int i=0;

	for(i=0; i<26; i++)
	{
	count[i] = 0; /*array of count i*/
	}

        while((c=getchar())!=EOF)  /*this makes the program read until the end of the text file*/
        {
		length[i]=c;
                i++;
        }

	for(i=0; i<100000; i++)      /*this array checks the text file for all the lowercase letters of the alphabet*/
	{
		switch(length[i])
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
		}
	}

printf("\nnumber of letter occurences:\n"); /*this prints the number of times each letter occurs*/

	for(i=0; i<26; i++)
	{
		printf("%g\t", count[i]);
	}
}

/*Function: percentage*/
/*this function calculates the percentage each letter appears in the text*/
void percentage(double *length, double *q)
{

	int e;
	double sum;
	int i;

	for(e=0; e<26; e++)
	{
		sum+=length[e];
	}		
	
	printf("\nthe sum is %g", sum); /*this print of the sum is for had calculating purposes*/
	printf("\n");
	printf("\npercentage of letter occurances:\n");
	
	for(i=0; i<26; i++)
	{
		q[i] = (length[i]/sum)*100; /*the equation to find the percentage*/
		printf("%.2lf\t", q[i]);
	}

	{
		printf("\n\n");
	}
		
}					/*end of function percentage*/

/*Function: frequency*/
/*this function finds the least and most frequent letters in the text*/
void frequency(double *count)
{
	int i;
	int minimum= count[0];
	int maximum= count[0];

	for(i=0; i<26; i++)
	{
		if(count[i] > maximum)
		{
			maximum = count[i];	/*equation to find the most frequent letter*/
		}
		else if(count[i] < minimum)
		{
			minimum = count[i];     /*equation to find the least frequent letter*/
		}
	}

printf("min equals %d\n",minimum);
printf("the least frequent letters are:");

	for(i=0; i<26; i++)
	{
		if(minimum==count[i])
			printf("%c  ",97+i);
	}

printf("\nmax equals %d\n",maximum);
printf("the most frequent letters are:");

        for(i=0; i<26; i++)
        {       
                if(maximum==count[i])
                        printf("%c  ",97+i);
        }
printf("\n\n");
}					         /*end of function frequency*/
