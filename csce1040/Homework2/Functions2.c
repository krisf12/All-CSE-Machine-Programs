#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"Structuredeclarations.h"
#include"MenuFunctionPrototypes.h"

void printmenu()
{
printf("1: Add new course\n2: Add new student\n3: Add a student to a course\n4: Add grades for student in a course\n5: Print a list of all grades for a student in a course\n");
printf("6: Print a list of all students in a course\n7: Compute the average for a student in a course\n8: Print a list of all courses\n9: Print a list of all students\n");
printf("10: Compute the average for a course\n11: Store grade book\n12: Load grade book\n13: Quit\n\n");
}

void add_course(struct students allstudents[], struct totalcourses allcourses[]/*, int *i*/)
{
	int i, coursenum;

        printf("Course number: ");
	scanf("%d",&coursenum);

	for(i=0; i<400; i++)
	{
		if(allstudents[i].courseid == -1)
		{
			allstudents[i].courseid=coursenum;	
			printf("Course name: ");
			scanf("%s",allcourses[i].coursename); break;
		}
	}
  
//(*i)++;
}

void add_student(struct students allstudents[]/*, int *i*/)
{
	int id, i;

	printf("Student ID: ");
        scanf("%d",&id);
	
	for(i=0; i<400; i++)     //scans for students
	{
		if(allstudents[i].id==-1)
		{
			allstudents[i].id=id;
        		printf("Student name: ");
        		scanf("%s",allstudents[i].firstname); break;
		}
	}
//(*i)++;
}


void add_student_and_course(/*struct totalcourses allcourses[],*/ struct students allstudents[]/*, int *i, int *j*/)
{

	char name[25];
	int i, cid, studentid, coursenumber, val=1;

	printf("Student ID: ");
	scanf("%d",&studentid);
	printf("Student Name: ");
	scanf("%s",name);
	printf("Course Number: ");
	scanf("%d",&cid);
         
         for(i=0;i<400;i++)                             // scans for students
         {    
         	if(allstudents[i].id == studentid && allstudents[i].courseid==cid)
		{
			allstudents[i].courseid =cid;
			printf("\n%s was successfully enrolled in %d!",name,cid);
			val=0; break; //the val is used to see if there is data stored or not
		}
		//else i++;
        } 
         if(val==1)  //this means the value didnt change because the if statement was not fulfilled
               {printf("ERROR, not found");return;}
	
}

void add_grade(struct totalcourses allcourses[], struct students allstudents[])
{

	char coursename[25];
	int stid, grade, coursenumber;

	printf("What Student ID would you like to add grades for? ");
	scanf("%d",&stid);
	printf("Course name? ");
	scanf("%s",coursename);
	printf("Course number? ");
	scanf("%d",&coursenumber);
	printf("What grade: ");
	scanf("%d",&grade);

	int i,j, val=1;

	for(i=0; i<400; i++)
	{
		if(allstudents[i].id == stid && allstudents[i].courseid == coursenumber)
			for(j=0; j<10; j++)
				if(allstudents[i].grades[j] == -1)
				{
					allstudents[i].grades[j]=grade; printf("success!");
					val=0; break;
				}
	}
       if(val==1)
               {printf("ERROR, not found");return;}
}


void print_grade(struct students allstudents[])
{

	int i, j, courseid, id, val=0;

printf("Student ID to print grades for: "); //stores temporary variables and then compares
scanf("%d",&id);
printf("Course number to print grades: ");
scanf("%d",&courseid);

	for(i=0; i<400; i++)
	{
		if(allstudents[i].courseid == courseid)
		{
		val=1;
		printf("\n\nGrade for student: %s in class: %d\n", allstudents[i].firstname, allstudents[i].courseid);
			for(j=0; j<10; j++)
			{
				if(allstudents[i].grades[j] != -1)
					{printf("%d ",allstudents[i].grades[j]);} ////////////
			}
		}
	}
	if(val==0)
		{printf("ERROR, not found");return;}
}

void print_stu_in_course(struct students allstudents[])
{

int i, j, courseid;

printf("Course number to print students: ");
scanf("%d", &courseid);
printf("All student enrolled in %d:\n\n", courseid);

	for(i=0;i<400; i++)
	{
		if(allstudents[i].courseid==courseid)
			printf("%s %d\n",allstudents[i].firstname,allstudents[i].id);
	}
}

void compute_average(struct students allstudents[])
{

int i, j, studentid, courseid, sum=0, x=0, average, val=0;
char name[25];

printf("Student ID: ");
scanf("%d",&studentid);
printf("Student name: ");
scanf("%s",name);
printf("Course number that student is enrolled in: ");
scanf("%d",&courseid);

        for(i=0; i<400; i++)    //scans through students
        {       
                if(allstudents[i].courseid == courseid && allstudents[i].id ==studentid)
                {
                val=1;
                        for(j=0; j<10; j++)
                        {       
                                if(allstudents[i].grades[i] != -1)
				{
					sum+=allstudents[i].grades[j]; //this calculates the average
					x++;
					printf("the average for %s %d is: ",name,allstudents[i].id);
					break;
				}
                        }       
                }       
        }       
        if(val==0)
                {printf("ERROR, not found");return;}
	
	average=sum/x;
	printf("%d\n\n",average);
}

void print_courses(struct students allstudents[], struct totalcourses allcourses[])
{

	int i;

	printf("A list of all courses:\n\n");

	for(i=0; i<25; i++)
	{
		if(allstudents[i].courseid != -1)
		{
			printf("%s %d\n",allcourses[i].coursename,allstudents[i].courseid);
		}
	}
	printf("\n\n");
}

void print_students(struct students allstudents[])
{
	
	int i;

	printf("A list of all students\n");

	for(i=0; i<400; i++)
	{
		if(allstudents[i].id != -1)
		{
			printf("%s %d\n",allstudents[i].firstname,allstudents[i].id);
		}
	}
printf("\n\n");
}

void course_average(struct students allstudents[], struct totalcourses allcourses[])
{

int i, j, studentid, courseid, sum=0, x=0, average, val=0;

printf("Course number to calculate average: ");
scanf("%d",&courseid);

        for(i=0; i<400; i++)
        {
                if(allstudents[i].courseid == courseid)
                {
                val=1;
                        for(j=0; j<10; j++)
                        {
                                if(allstudents[i].grades[j] != -1)
                                {
                                        sum+=allstudents[i].grades[j];
                                        x++;
                                }
                        }
                }
        }
        if(val==0)
                {printf("ERROR, not found");return;}

        average=sum/x;
	printf("the average for the course is: %d\n\n",average);
}

void save(struct students allstudents[], struct totalcourses allcourses[])
{

	int i,j;
	FILE *out;
	out=fopen("data", "w");
	
        for(i=0; i<400; i++)
        {
                if(allstudents[i].id != -1)
                {
             		fprintf(out, "%d %d %s",allstudents[i].courseid, allstudents[i].id, allstudents[i].firstname);
                        for(j=0; j<10; j++)
                        {
                                fprintf(out,"%d ", allstudents[i].grades[j]);
                        }
                }
        }
	fclose(out);

	FILE *outfile;	
	outfile=fopen("courses","w");

	for(i=0;i<25;i++)
	{
		fprintf(outfile, "%d",allcourses[i].cid);
		fprintf(outfile, "%s",allcourses[i].coursename);
	}
	fclose(outfile);
printf("\n\nSAVING.. Done\n\n");
}

void load(struct students allstudents[], struct totalcourses allcourses[])
{

        int i,j;
        FILE *in;
	FILE *f;
        in=fopen("data", "r");
        
        for(i=0; i<sizeof("data"); i++)
        {
                if(allstudents[i].id != -1)
                {
                        fscanf(in, "%d %d %s",&allstudents[i].courseid, &allstudents[i].id, allstudents[i].firstname);
                        for(j=0; j<10; j++)
                        {
                                fscanf(in,"%d ", &allstudents[i].grades[j]);
                        }
                }
        }
        fclose(in);

	FILE *infile;
	infile=fopen("courses", "r");
	
	for(i=0;i<25;i++)
	{
               fscanf(infile, "%d",&allcourses[i].cid);
               fscanf(infile, "%s",allcourses[i].coursename);
        }
        fclose(infile);

printf("\n\nLOADING.. Done\n\n");
}
