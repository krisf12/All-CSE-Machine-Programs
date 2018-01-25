#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Structuredeclarations.h"
#include"MenuFunctionPrototypes.h"

void printmenu()
{
printf("1: Add new course\n2: Add new student\n3: Add a student to a course\n4: Add grades for student in a course\n5: Print a list of all grades for a student in a course\n");
printf("6: Print a list of all students in a course\n7: Compute the average for a student in a course\n8: Print a list of all courses\n9: Print a list of all students\n");
printf("10: Compute the average for a course\n11: Store grade book\n12: Load grade book\n13: Quit\n\n");
}

void add_course(struct totalcourses allcourses[], int *i)
{
	printf("Course name: ");
	scanf("%s",allcourses[*i].coursename);
	printf("Course number: ");
	scanf("%d",&allcourses[*i].coursenumber);
(*i)++;
}

void add_student(struct students allstudents[], int *i)
{
        printf("Student name: ");
        scanf("%s",allstudents[*i].firstname);
        printf("Student ID: ");
        scanf("%d",&allstudents[*i].id);
(*i)++;
}


void add_student_and_course(struct totalcourses allcourses[], struct students allstudents[], int *j)
{

	char student[25], course[25];
	int i, studentid, coursenumber, val=1;


	//printf("Student name: ");
	//scanf("%s",student);
	printf("Student ID: ");
	scanf("%d",&studentid);
         
         for(i=0;i<100;i++)                             // CURRENT ISSUE IS HERE
   //      {       
         	if(allstudents[i].id == studentid)
               	//	val=0;
	//	else allstudents[i].id = 0;
      //   }
      //   if(val==1)
        //        {printf("ERROR, not found");return;}


	printf("Course name to add student to: ");
	scanf("%s",course);
	printf("Course number:");
	scanf("%d",&coursenumber);
	
	for(i=0; i<25; i++)
	{
		if(allcourses[i].coursenumber == coursenumber && allcourses[i].coursename == course)
		val=1;
	}
	if(val==0)
		{printf("ERROR, not found");return;}
}

void add_grade(struct totalcourses allcourses[], struct students allstudents[]/*, struct grades studentcourses[]*/)
{

	char coursename[25];
	int stid, coursenumber, grade;

	printf("What Student ID would you like to add grades for? ");
	scanf("%d",&stid);
	printf("Course name? ");
	scanf("%s",coursename);
	printf("Course number? ");
	scanf("%d",&coursenumber);

	printf("Grade: ");
	scanf("%d",&grade);


	int i,j, val=1;

	for(i=0; i<100; i++)
	{
		if(allstudents[i].id == stid)
			val=0;  //TEST
	}
		
       if(val==1)
               {printf("ERROR, not found");return;}

		
	for(j=0; j<25; j++)
	{
		if(allcourses[j].coursename == coursename && allcourses[j].coursenumber == coursenumber)
		{
			printf("what grade: ");
			val=1;
			//scanf("%d",&allstudents[*b].studentcourses.grades);
		}
	}
        if(val==0)
                {printf("ERROR, not found");return;}
}

/*
void print_grade(struct students allstudents[])
{








}
*/
