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

void add_course(struct students *allstudents)
{
	printf("Enter course number: ");
	int coursenum=0;
	allstudents->coursd = 0;
	allstudents->coursf = 0;
	scanf("%d", &coursenum);

	if(allstudents->courseid[(allstudents->coursd)][(allstudents->coursf)] == 0)
	{
		allstudents->courseid[(allstudents->coursd)][(allstudents->coursf)] = coursenum;
	}

	else{
		while(((allstudents->coursd)<25) && (allstudents->courseid[(allstudents->coursd)][(allstudents->coursf)] > 0))
		{
			allstudents->courseid[++(allstudents->coursd)][(allstudents->coursf)];
		}
		////end of while loop
		
		if(allstudents->courseid[(allstudents->coursd)][(allstudents->coursf)] == 0)
		{
			allstudents->courseid[(allstudents->coursd)][(allstudents->coursf)] = coursenum;
			allstudents->coursd = (allstudents->coursd) + 25;
		} 
		
		else if(allstudents->courseid[(allstudents->coursd)][(allstudents->coursf)] == coursenum){
			printf("Class already added.\n");
		}
		
		else
		{
			printf("Unable to add classes.\n");
		}//end of else
	    
	    }//end of else

//		int acd=0, acb=0;
//		while(acd < 5){
//			printf("%d\n", allstudents->courseid[acd][acb]);
//			acd++;
//			}
//		(allstudents->count)++;
	}//////////////////////////////////////////end of add cours


void add_student(struct students *allstudents)
{

	int id=0;
	//char s[10];
	allstudents->stud =0;
	allstudents->studf =0;

	printf("Enter student id: ");
	scanf("%d", &id);
	//printf("Enter student first name: ");
	//scanf("%s", s); 

	if(allstudents->id[(allstudents->stud)][(allstudents->studf)] == 0){
		allstudents->id[(allstudents->stud)][(allstudents->studf)] = id;
	}
 
	else
	{
		while((allstudents->id[(allstudents->stud)][(allstudents->studf)] > 0) && ((allstudents->stud) < (allstudents->total)))
		{
			allstudents->id[++(allstudents->stud)][(allstudents->studf)];
		}//end of while
		
		if(allstudents->id[(allstudents->stud)][(allstudents->studf)] == 0)
		{
			allstudents->id[(allstudents->stud)][(allstudents->studf)] = id;
		}
		
		else
		{ 
			printf("Cannot add students.\n");
		}//end of else

	}//end of else 
	
	allstudents->stud=0;

	(allstudents->count)++;
}


void add_student_and_course(struct students *allstudents)
{

	int course=0,id=0;

	printf("Enter course number: ");
	scanf("%d", &course);
	printf("Enter student id number: ");
	scanf("%d", &id);

			allstudents->coursd = 0;
			allstudents->coursf = 0;

		while(allstudents->courseid[(allstudents->coursd)][(allstudents->coursf)] != course)
		{
			allstudents->courseid[++(allstudents->coursd)][(allstudents->coursf)];
		}//end of while loop
		 allstudents->stud = 0;
		 
		int d = 0;
		while((allstudents->id[(allstudents->stud)][(allstudents->studf)] != id) && (d < (allstudents->total)))
		{
			allstudents->id[++(allstudents->stud)][(allstudents->studf)];
		}//end of while loop

		if((allstudents->courseid[(allstudents->coursd)][(allstudents->coursf)] == course) && (allstudents->id[(allstudents->stud)][(allstudents->studf)] == id))
		{
			allstudents->courseid[(allstudents->coursd)][++(allstudents->coursf)];
			allstudents->id[(allstudents->studf)][++(allstudents->studf)];
			
			while((allstudents->id[(allstudents->stud)][(allstudents->studf)] > 0) && ((allstudents->studf) < (allstudents->total)))
			{
				allstudents->studf = (allstudents->studf) + (allstudents->cours);
				allstudents->id[(allstudents->stud)][(allstudents->studf)];
			}//end of while loop
		
			allstudents->id[(allstudents->stud)][(allstudents->studf)] = course;
			
			while((allstudents->courseid[(allstudents->coursd)][(allstudents->coursf)] > 0) && (allstudents->coursf < (allstudents->total)))
			{
				allstudents->courseid[(allstudents->coursd)][++(allstudents->coursf)]; 
			}//end of whiile loop

			if((allstudents->courseid[(allstudents->coursd)][(allstudents->coursf)] == 0) && ( (allstudents->coursf) < (allstudents->total)))
			{
				allstudents->courseid[(allstudents->coursd)][(allstudents->coursf)] = id;
			}//end of if statement
		}//end of if statment
	else {
		printf("Either student or course is not in system.\n");
	}//end of else statement
	(allstudents->count)++;
}

void add_grade(struct students *allstudents)
{
	 allstudents->stud =0;
	 allstudents->studf =0;
	 int id=0,course=0,grade=0;

	printf("Enter course number: ");
	scanf("%d", &course);
	printf("Enter student id: ");
	scanf("%d", &id);

	while(allstudents->id[(allstudents->stud)][(allstudents->studf)] != id)
	{
		allstudents->id[++(allstudents->stud)][(allstudents->studf)];
	}//end of while statement

	allstudents->id[(allstudents->stud)][++(allstudents->studf)];
	while(allstudents->id[(allstudents->stud)][(allstudents->studf)] != course)
	{
		(allstudents->studf) = (allstudents->studf) + (allstudents->cours);
	}///////end of while statement

	printf("Enter Grade: ");
	scanf("%d", &grade);
	
	allstudents->id[(allstudents->stud)][++(allstudents->studf)];
	
	if((allstudents->id[(allstudents->stud)][(allstudents->studf)] == 0) || (allstudents->id[(allstudents->stud)][(allstudents->studf)] == -1))
	{
		allstudents->id[(allstudents->stud)][(allstudents->studf)] = grade;
	} 
	
	else
	{
		int a=0;		
		a = (allstudents->studf);
	
		while((allstudents->id[(allstudents->stud)][(allstudents->studf)] > 0) && (allstudents->id[(allstudents->stud)][(allstudents->studf)] < (allstudents->total)) && ((allstudents->studf) < a + (allstudents->cours)))
		{
			allstudents->id[(allstudents->stud)][++(allstudents->studf)];	
		}//end of while loop

		if((allstudents->id[(allstudents->stud)][(allstudents->studf)] == 0) || (allstudents->id[(allstudents->stud)][(allstudents->studf)] == -1))
		{
			if((allstudents->studf) < a + (allstudents->cours))
				allstudents->id[(allstudents->stud)][(allstudents->studf)] = grade;
		}// end of if else

		allstudents->id[(allstudents->stud)][++(allstudents->studf)];

		if((allstudents->id[(allstudents->stud)][(allstudents->studf)] < 0) && ((allstudents->studf) < a + (allstudents->cours)))
		{
			allstudents->id[(allstudents->stud)][(allstudents->studf)] = -1;
		} //end of if
	} //end of else

	(allstudents->count)++;
}


void print_grade(struct students *allstudents)
{
	int id=0,course=0;
	allstudents->stud =0;
	allstudents->studf =0;

	printf("Enter course number: ");
	scanf("%d", &course);
	printf("Enter student id: ");
	scanf("%d", &id);

	while(allstudents->id[(allstudents->stud)][(allstudents->studf)] != id)
	{
		allstudents->id[++(allstudents->stud)][(allstudents->studf)];
	}//end of while

	if(allstudents->id[(allstudents->stud)][(allstudents->studf)] == id)
		allstudents->id[(allstudents->stud)][++(allstudents->studf)];
		
		while((allstudents->id[(allstudents->stud)][(allstudents->studf)] != course) && ((allstudents->studf) < (allstudents->total)))
		{
			allstudents->studf = (allstudents->studf) + (allstudents->cours);
		}//end of while loop

	if(allstudents->id[(allstudents->stud)][(allstudents->studf)] == course)
	{
		int b; //=0
		b = (allstudents->studf);
		while((allstudents->id[(allstudents->stud)][(allstudents->studf)] != -1) && ((allstudents->studf) < b + (allstudents->grades)))
		{	
			allstudents->id[(allstudents->stud)][++(allstudents->studf)];
		
			if(allstudents->id[(allstudents->stud)][(allstudents->studf)] > -1 )
				printf("Grade: %d\n", allstudents->id[(allstudents->stud)][(allstudents->studf)]);
		}//end of while
	}
 
	else 
	{
		printf("Student Not Found.\n");
	}//end of else statement
}


void print_stu_in_course(struct students *allstudents)
{
	allstudents->coursd =0; 
	allstudents->coursf =0;
	
	int course=0, id=0;

	printf("Enter course number: ");
	scanf("%d", &course);
	
	while(((allstudents->coursd) < 25) && (allstudents->courseid[(allstudents->coursd)][(allstudents->coursf)] != course))
	{
		allstudents->courseid[++(allstudents->coursd)][(allstudents->coursf)];
	}///////////end of while loop
	if((allstudents->coursd) == 25)
	{
		printf("No course found.\n");
	}
	
	else
	{ 
		printf("List of students:\n");
		for((allstudents->coursf)=1;(allstudents->coursf)<(allstudents->total);(allstudents->coursf)++)
		{
			if(allstudents->courseid[(allstudents->coursd)][(allstudents->coursf)] > 0)
			{
				printf("\tStudent id's: %d\n", allstudents->courseid[(allstudents->coursd)][(allstudents->coursf)]);
			}//end of if statement
		}//end of for
	}//end of else
}


void compute_average(struct students *allstudents)
{
	allstudents->stud =0;
	allstudents->studf =0;
	int coursen,studn;

	printf("Enter Course number: ");
	scanf("%d", &coursen);
	printf("Enter student id: ");
	scanf("%d", &studn);
		
		while(allstudents->id[(allstudents->stud)][(allstudents->studf)] != studn)
		{
			allstudents->id[(allstudents->stud)++][(allstudents->studf)];
		}///end of while

	if(allstudents->id[(allstudents->stud)][(allstudents->studf)] == studn)
		allstudents->id[(allstudents->stud)][(allstudents->studf)++];

			while(allstudents->id[(allstudents->stud)][(allstudents->studf)] != coursen){
			(allstudents->studf) = (allstudents->studf) + (allstudents->cours);
		}///end of while
	if(allstudents->id[(allstudents->stud)][(allstudents->studf)] == coursen)
	{
		allstudents->id[(allstudents->stud)][(allstudents->studf)++];

		int max, totalgr=0,sum=0;

		max = (allstudents->studf);
		while((allstudents->id[(allstudents->stud)][(allstudents->studf)] > 0) && ((allstudents->studf) < max + (allstudents->cours)))
		{
			totalgr += allstudents->id[(allstudents->stud)][(allstudents->studf)];
			sum++;
			printf("%d\n", totalgr);
			(allstudents->studf)++;
		}///end of while
		
			double avg = 0;
			avg = ((double) totalgr )/ ((double) sum); 
			printf("The student average is: %2.2lf\n\n", avg);
	}//end of if statement
	
	else
	{
		printf("Student is not enrolled in course\n\n");
	}///end of else
}

void print_courses(struct students *allstudents)
{
	allstudents->coursd=0; 
	allstudents->coursf=0;
	for((allstudents->coursd)=0;(allstudents->coursd)<50;(allstudents->coursd)++)
	{
		if(allstudents->courseid[(allstudents->coursd)][(allstudents->coursf)] > 0)
			printf("Couses: %d\n", allstudents->courseid[(allstudents->coursd)][(allstudents->coursf)]);
	}//end of foor loop
}

void print_students(struct students *allstudents)
{
	allstudents->stud = 0;
	allstudents->studf = 0;
	for((allstudents->stud)=0;(allstudents->stud)<(allstudents->total);(allstudents->stud)++)
	{
		if(allstudents->id[(allstudents->stud)][(allstudents->studf)] > 0)
		{
			printf("Student id: %d\n", allstudents->id[(allstudents->stud)][(allstudents->studf)]);
		}

	}//end of for loop
}

/*
void course_average(struct students *allstudents)
{

int i, j, studentid, courseid, sum=0, x=0, average, val=0, k;

printf("Course number to calculate average: ");
scanf("%d",&courseid);

        for(i=0; i<400; i++)
        {
		for(j=0;j<25;j++)
		{
	                if(allstudents[i].courseid[j] == courseid)
	                {
	                val=1;
	                        for(k=0; k<10; k++)
	                        {
	                                while(allstudents[i].grades[k] != -1)        ///// changed if to while
	                                {
	                                        sum+=allstudents[i].grades[k];
	                                        x++;
	                                }
	                        }
	                }
       		}
	 }
        if(val==0)
                {printf("ERROR, not found");return;}

        average=sum/x;
	printf("the average for the course is: %d\n\n",average);
}

void save(students *allstudents)
{

	int i,j;
	FILE *out;
	out=fopen("data", "w");
	
        for(i=0; i<400; i++)
        {
		for(j=0;j<25;j++)
		{
	                if(allstudents[i].id != -1)
	                {
	             		fprintf(out, "%d %d %s %s",allstudents[i].courseid[j], allstudents[i].id, allstudents[i].firstname, allstudents[i].coursename);
	                       
				 for(j=0; j<10; j++)
	                        {
	                                fprintf(out,"%d ", allstudents[i].grades[j]);
	                        }
	                }
       		}
	 }

	fclose(out);
printf("\n\nSAVING.. Done\n\n");
}

void load(students *allstudents)
{

        int i,j;
        FILE *in;
	FILE *f;
        in=fopen("data", "r");
        
        for(i=0; i<sizeof("data"); i++)
        {
                if(allstudents[i].id != -1)
                {
                        fscanf(in, "%d %d %s %s",&allstudents[i].courseid[j], &allstudents[i].id, allstudents[i].firstname, allstudents[i].coursename);
                        for(j=0; j<10; j++)
                        {
                                fscanf(in,"%d ", &allstudents[i].grades[j]);
                        }
                }
        }
        fclose(in);

printf("\n\nLOADING.. Done\n\n");
}
*/
