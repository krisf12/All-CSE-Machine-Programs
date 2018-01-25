/*
//Author: Kristian Forestier
//Date: 11/15/13
//Purpose: This program opens a file, prints a menu, creates a database, and performs actions requested by the user.
*/


#include"header5.h"
#include<string.h>

void gtfile(struct records recordsize[]) /*this function prompts the user for a file name, prints a menu, and opens the file.*/
{
	FILE *nameofile;
	char FileName[Max_File_Size];
	char Extension[Max_File_Size];

printf("Please enter the file name: ");
scanf("%s",FileName); /*stores the file they enter in "FileName*/

printf("\nThe file you have chosen is: %s\n\n",FileName);

	nameofile=fopen(FileName, "r");	/*opens and reads file*/
	readLine(nameofile, recordsize);
	fclose(nameofile);  /*closes the file*/


printf("*******************************************\n");
printf("Select one of the following options:\n");
printf("1: all - print all records\n");
printf("2: euid - search for euid\n");
printf("3: name - search for last name\n");
printf("4: lowest - print records with lowest GPA\n");
printf("5: highest - print records with highest GPA\n");
printf("6: gpa - print records with GPA >= 3.0\n*******************************************\n");

}

void readLine(FILE* inFile, struct records recordsize[]) /*this function reads the contents of the file and stores them in their proper struct*/
{
	int i=0;	

	do
	{
		fscanf(inFile,"%d",&recordsize[i].euid);
		fscanf(inFile,"%s",recordsize[i].firname);
		fscanf(inFile,"%s",recordsize[i].lasname);
		fscanf(inFile,"%g",&recordsize[i].gpa);
		i++;
	}while(fscanf(inFile,"%d",&recordsize[i].euid) != -1);

}

void scan_forinput() /*this function prompts the user for a selection and stores their selection*/
{
	printf("db> ");
	scanf("%d",&selection);
}

void print_all(struct records recordsize[], int *selection) /*this function prints all records if the user chooses the first option*/
{
	if(*selection==1)
	{
            printf("%d\t%s\t%s\t%g\n",recordsize[0].euid,recordsize[0].firname,recordsize[0].lasname,recordsize[0].gpa);
            printf("%d\t%s\t%s\t%g\n",recordsize[1].euid,recordsize[1].firname,recordsize[1].lasname,recordsize[1].gpa);
            printf("%d\t%s\t%s\t%g\n",recordsize[2].euid,recordsize[2].firname,recordsize[2].lasname,recordsize[2].gpa);
            printf("%d\t%s\t%s\t%g\n",recordsize[3].euid,recordsize[3].firname,recordsize[3].lasname,recordsize[3].gpa);
            printf("\n");
	}
}

void print_euid(struct records recordsize[], int *selection, int *euidnumber) /*this function prints the record of the euid specified by the user*/
{
	if(*selection==2)
	{
	printf("enter an euid: ");
	scanf("%d",euidnumber);
	
		if(*euidnumber== recordsize[0].euid)
		{
		printf("%d\t%s\t%s\t%g\n",recordsize[0].euid,recordsize[0].firname,recordsize[0].lasname,recordsize[0].gpa);
		}
		if(*euidnumber== recordsize[1].euid)
		{
		printf("%d\t%s\t%s\t%g\n",recordsize[1].euid,recordsize[1].firname,recordsize[1].lasname,recordsize[1].gpa);
		}
		if(*euidnumber== recordsize[2].euid)
		{
		printf("%d\t%s\t%s\t%g\n",recordsize[2].euid,recordsize[2].firname,recordsize[2].lasname,recordsize[2].gpa);
		}
		if(*euidnumber== recordsize[3].euid)
		{
		printf("%d\t%s\t%s\t%g\n",recordsize[3].euid,recordsize[3].firname,recordsize[3].lasname,recordsize[3].gpa);
		}
	}
}

void print_name(struct records recordsize[], int *selection) /*this function prints the record/s of the last name specified by the user*/
{
	char entlasname[20];

	if(*selection==3)
	{
	printf("enter a last name: ");
	scanf("%s",entlasname);

                if(strcmp(entlasname,recordsize[0].lasname)==0)
                {
                printf("%d\t%s\t%s\t%g\n",recordsize[0].euid,recordsize[0].firname,recordsize[0].lasname,recordsize[0].gpa);
                }
                if(strcmp(entlasname,recordsize[1].lasname)==0)
                {
                printf("%d\t%s\t%s\t%g\n",recordsize[1].euid,recordsize[1].firname,recordsize[1].lasname,recordsize[1].gpa);
                }
                if(strcmp(entlasname,recordsize[2].lasname)==0)
                {
                printf("%d\t%s\t%s\t%g\n",recordsize[2].euid,recordsize[2].firname,recordsize[2].lasname,recordsize[2].gpa);
                }
                if(strcmp(entlasname,recordsize[3].lasname)==0)
                {
                printf("%d\t%s\t%s\t%g\n",recordsize[3].euid,recordsize[3].firname,recordsize[3].lasname,recordsize[3].gpa);
                }
	}	
}


void print_lowest(struct records recordsize[], int *selection) /*this function prints the record/s with the lowest gpa*/
{
        if(*selection==4)
        {
		double lowest= (recordsize[0].gpa);
		int i;

        	for(i=0; i<=(sizeof(recordsize)); i++)
        	{
 
                	if(recordsize[i].gpa < lowest) /*min function*/
 	                
                        lowest = recordsize[i].gpa;
                
        	}

		for(i=0; i<=(sizeof(recordsize)); i++)
		{
			if(recordsize[i].gpa == lowest)
			printf("%d\t%s\t%s\t%g\n",recordsize[i].euid,recordsize[i].firname,recordsize[i].lasname,recordsize[i].gpa);
		}
        }
}


void print_highest(struct records recordsize[], int *selection) /*this function prints the record/s with the highest gpa*/
{
	if(*selection==5)
	{
		double highest= (recordsize[0].gpa);
		int i;

		for(i=0; i<=(sizeof(recordsize)); i++)
		{
        		if(recordsize[i].gpa > highest) /*max function*/
        		highest = recordsize[i].gpa;
		}
		for(i=0; i<=(sizeof(recordsize)); i++)
		{
        		if(recordsize[i].gpa == highest)
		        printf("%d\t%s\t%s\t%g\n",recordsize[i].euid,recordsize[i].firname,recordsize[i].lasname,recordsize[i].gpa);
		}
	}
}


void gpa(struct records recordsize[], int *selection) /*this function prints the record/s with a gpa >= 3.0*/
{
	if(*selection==6)
	{
		int i;
	
		for(i=0; i<=(sizeof(recordsize)); i++)
		{
			if(recordsize[i].gpa >= 3.0)
			printf("%d\t%s\t%s\t%g\n",recordsize[i].euid,recordsize[i].firname,recordsize[i].lasname,recordsize[i].gpa);

		}
	}
}
