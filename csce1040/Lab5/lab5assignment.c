// Kristian Forestier
// kristian.forestier@my.unt.edu
// 2/21/14
// Lab 5


// I changed student to students in my bubble file so it will only run if the bubble file is edited to students

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "student.h"
#include "bubble.h"

typedef struct {
  float mean;
  float min;
  float max;
  float median;
  char *name;
} classStats;

int main()
{

int i, classnum, sumval, sum, divide;
char classname[25];
char fname[45], lname[45];
students *student[19];
classStats class;

//student = (students **) malloc (19 * sizeof(student));

	for(i=0; i<19; i++)
	{
	student[i]= (students*) malloc (sizeof(students));
	//student[i]=NULL;
	scanf("%s %s", fname, lname);
        scanf("%d %d %d",&student[i]->exam1, &student[i]->exam2, &student[i]->exam3);
	}
	
	scanf("%s",classname);

	for(i=0; i<19; i++)
	{
	sumval=0;

//	scanf("%s %s", fname, lname); 
//	scanf("%d %d %d",&student[i]->exam1, &student[i]->exam2, &student[i]->exam3);
	student[i]->first=(char *) malloc(strlen(fname)+1);
	strcpy(student[i]->first, fname);
	student[i]->last=(char *) malloc(strlen(lname)+1);
	strcpy(student[i]->first, fname); 
	}
	
	bubble(student,19);

	for(i=0; i<19; i++)
	{
	sum+=student[i]->mean;
	divide++;
	}
	
	printf("\nCSCE1040 MEAN: %f MIN: %f MAX: %f MEDIAN: %f",(float)sum/divide,student[0]->mean,student[0]->mean,student[18]->mean,student[9]->mean);

	
return 0;
}

