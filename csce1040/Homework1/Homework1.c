/*
//Kristian Forestier
//Kristianforestier@my.unt.edu
//CSCE 1040.001
//Homework 1
//1/29/14
//
*/

#include<stdio.h>
#include<stdlib.h>

void printmenu();
void add_course(int gradebook[25][101][11]);
void add_student_and_course(int gradebook[25][101][11]);
void add_grade(int gradebook[25][101][11]); 
void print_grade(int gradebook[25][101][11]);
void print_stu_in_course(int gradebook[25][101][11]);
void compute_average(int gradebook[25][101][11]);
void print_courses(int gradebook[25][101][11]);
void print_students(int gradebook[25][101][11]);
void course_average(int gradebook[25][101][11]);
void save_gradebook(int gradebook[25][101][11]);
void load_gradebook(int gradebook[25][101][11]);
int gradebook[25][101][11];

int main(void)
{
	printf("\nKristian Forestier\nKristianforestier@my.unt.edu\nCSCE 1040.001\nHomework 1\n1/29/14\n\n");

	int a, b, c;
	for(a=0; a<25; a++)
	{
		for(b=0; b<101; b++)
		{
			for(c=0; c<11; c++)
			{
				gradebook[a][b][c] = 0;     /*initialize array*/
			}
		}
	}
	
	int choice;
	printf("Welcome! Please select an option from the menu below.\n");
	
	do
	{
		printf("\n\n");
		printmenu();            /*call menu function*/
		scanf("%d", &choice);  /*scan for their input*/
	
		if(choice==1)
		add_course(gradebook);  /*call add course function*/
		else if(choice==2)
		add_student_and_course(gradebook); /*call add student function*/
		else if(choice==3)
		add_student_and_course(gradebook); /*call add student with course function*/
		else if(choice==4)
		add_grade(gradebook);       /*call add grade for a student function*/
		else if(choice==5)
		print_grade(gradebook);   /*call print grade for a student function*/
		else if(choice==6)
		print_stu_in_course(gradebook);
		else if(choice==7)
		compute_average(gradebook);   /*call average function*/
		else if(choice==8)
		print_courses(gradebook);
		else if(choice==9)
		print_students(gradebook);    /*these two print courses and students*/
		else if(choice==10)
		course_average(gradebook);  /*course average function*/
		else if(choice==11)
		save_gradebook(gradebook);
		else if(choice==12)
		load_gradebook(gradebook);
		else if(choice==13)
		;
		else
		printf("ERROR try again");    /*if they do not type a number on the menu*/

	} while(choice != 13);
}

void printmenu()
{
printf("1: Add new course\n2: Add new student\n3: Add a student to a course\n4: Add grades for a student in a course\n5: Print a list of all grades for a student in a course\n");
printf("6: Print a list of all students in a course\n7: Compute the average for a student in a course\n8: Print a list of all courses\n9: Print a list of all students\n");
printf("10: Compute the average for a course\n11: Store grade book\n12: Load grade book\n13: Quit\n\n");
}

void add_course(int gradebook[25][101][11])
{
	int course;
	int i;

	printf("Enter Course Number: ");
	scanf("%d", &course);
	
	for(i=0;i<25;i++)
		if(gradebook[i][0][0] == 0)  /*checks for a previous course entered*/
		{
		gradebook[i][0][0]=course;
		break;
		}
}

void add_student_and_course(int gradebook[25][101][11])
{
	int ID;
	int i, j;
	int courselection;
	
	printf("Student ID: \n");
	scanf("%d", &ID);
	
	printf("What course? \n");
        scanf("%d", &courselection);
         
        for(i=0;i<25;i++)
                if(gradebook[i][0][0] == courselection)   /*checks for what course was chosen*/
                        for(j=1; j<101; j++)
                               if(gradebook[i][j][0] == 0)  
				{
					gradebook[i][j][0] = ID; /*adds the id entered to that course*/
                                       	break;
				}
}

void add_grade(int gradebook[25][101][11])
{
	int ID, courselection, grade;
	int i, j, k;

	printf("Enter the Student ID: \n");
	scanf("%d", &ID);
	printf("Enter the course to add grades for: \n");
	scanf("%d", &courselection);
	printf("Enter the grade: \n");
	scanf("%d", &grade);

	        for(i=0; i<25; i++)
                if(gradebook[i][0][0] == courselection)    /*checks for course selected*/
                        for(j=1; j<101; j++)
                                if(gradebook[i][j][0] == ID)    /*checks for student*/
                                	for(k=1; k<11; k++)
						if(gradebook[i][j][k] == 0)
							{
                                        		gradebook[i][j][k] = grade;   /*adds that grade to the student in that class*/
                                        		break;
                                			}
}

void print_grade(int gradebook[25][101][11])
{
	int ID, courselection, grade;
	int i, j, k;

	printf("Enter the Student ID: ");
        scanf("%d", &ID);
        printf("Enter the course to print grades for: ");
        scanf("%d", &courselection);
 	
	         for(i=0; i<25; i++)
                 if(gradebook[i][0][0] == courselection)
                         for(j=1; j<101; j++)
                                 if(gradebook[i][j][0] == ID)
                                         for(k=1; k<11; k++)
                                                 if(gradebook[i][j][k] != 0)
                                                       printf("%d ",gradebook[i][j][k]); /*prints grade for chosen course*/
}

void print_stu_in_course(int course_with_student_with_grades[25][101][11])
{
	int i, j, k;
	int ID, courselection;

	printf("Class Number: ");
	scanf("%d", &courselection);
	
	for(i=0; i<25; i++)
		if(gradebook[i][0][0] == courselection)		
			for(j=1;j<101;j++)
				if(gradebook[i][j][0] != 0)
					printf("%d ", gradebook[i][j][0]); /*prints student for chosen course*/
			
}

void compute_average(int gradebook[25][101][11])
{
	int ID, courselection, sum=0, c=0;
	int i,j,k;

	printf(" Student ID: ");
	scanf("%d", &ID);
	printf("Course Number: ");
	scanf("%d", &courselection);
	
	for(i=0; i<25; i++)
                  if(gradebook[i][0][0] == courselection)
                          for(j=1; j<101; j++)
                                  if(gradebook[i][j][0] == ID)
                                          for(k=1; k<11; k++)
                                                  if(gradebook[i][j][k] != 0)
                                                        {
							sum+= gradebook[i][j][k];   /*finds average*/
							c++;
							}
	sum= sum/c;                /*computes average*/
	printf("Average: %d", sum);
}

void print_courses(int gradebook[25][101][11])
{
	int i;

	printf("A list of all Courses:\n");
	
	for(i=0; i<25; i++)
		if(gradebook[i][0][0] !=0)
			printf("%d ", gradebook[i][0][0]);  /*finds the spot in the array with courses*/
}

void print_students(int gradebook[25][101][11])
{
        int i, j;

        printf("A list of all Students:\n");

        for(i=0; i<25; i++)
		for(j=1;j<101;j++)
			if(gradebook[i][j][0] != 0)	
                        	printf("%d ", gradebook[i][j][0]); /*finds spot in the array with student*/

}

void course_average(int gradebook[25][101][11])
{
	int i, j, k;
	int x=0, sum=0;
	int courselection;

	printf("course number: \n");
	scanf("%d", &courselection);

	for(i=0;i<25;i++)
		if(gradebook[i][0][0] == courselection)
			for(j=1;j<101;j++)
				if(gradebook[i][j][0] != 0)
					for(k=1;k<11;k++)
						if(gradebook[i][j][k] !=0)
						{
						sum+=gradebook[i][j][k];   /*calculates average*/
						x++;
						}
	sum=sum/x; /*divides by sum*/
	printf("Average grade of course %d: %d\n\n",courselection,sum);		
}

void load_gradebook(int gradebook[25][101][11])
{
	int i,j,k;

	FILE *f; 
	f = fopen("gradebook","r");
	
	for(i=0;i<25;i++)
            for(j=1;j<101;j++)
            	for(k=1;k<11;k++)

		fscanf(f, "%d", &gradebook[i][j][k]);

		fclose(f);

	printf("\n\nOpening File. . .\n\n");

}

void save_gradebook(int gradebook[25][101][11])
{
	int i,j,k;
	
	FILE *f;
	f = fopen("gradebook","w");

        for(i=0;i<25;i++)
            for(j=1;j<101;j++)
                for(k=1;k<11;k++)
		
		fprintf(f,"%d",gradebook[i][j][k]);

	fclose(f);

	printf("\n\nSaved...\n\n");
}
