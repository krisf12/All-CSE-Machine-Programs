#include<stdio.h>
#include<stdlib.h>
#include"Structuredeclarations.h"

int main(void)
{
	printf("\n\nCSCE 1040\nHomework 3\nKristian Forestier\nkristian.forestier@my.unt.edu\n");

	int choice,k, j;

struct students allstudents;

	int i=0,h=0,pick=0,decide=0;
	allstudents.coursd = 0;
	allstudents.coursf = 0;
	allstudents.stud = 0;
	allstudents.studf = 0;        //initializing variables

	allstudents.total = 100;
	allstudents.count = 0;
	allstudents.grades = 10;
	allstudents.cours = 11;
	
allstudents.id = (int **) malloc((allstudents.total)*sizeof(int));   //allocating for students

	for(i=0;i<(allstudents.total);i++)
			allstudents.id[i] = (int *) malloc((allstudents.total)*sizeof(int)); //allocating for array


allstudents.courseid = (int **) malloc((allstudents.total)*sizeof(int)); //allocating for courses
		
		 for(i=0;i<(allstudents.total);i++)
				allstudents.courseid[i] = (int *) malloc((allstudents.total)*sizeof(int)); //allocating for array

//allstudents.grades = (int **) malloc((allstudents.total)*sizeof(int)); //allocating for grades 
		
		 for(i=0;i<(allstudents.total);i++)
		{
			for(h=0;h<(allstudents.total);h++)
			{
		
				allstudents.id[i][h] = 0; //initializing array to 0
			}//end of loop

		}//end of loop

	for(i=0;i<(allstudents.total);i++)
	{
		for(h=0;h<(allstudents.total);h++)
		{
			allstudents.courseid[i][h] =0; //initializing array to 0
		}//end of loop

	}//end of loop

//end initializing to 0
	
	while(decide < 1)
	{
		int i;

		if((allstudents.count) > 3)
		{
			allstudents.total = (allstudents.total) * 2;
			allstudents.id = (int **) realloc((allstudents.id),(allstudents.total)*sizeof(int));

				for(i=0;i<(allstudents.total);i++)
					allstudents.id[i] = (int *) realloc((allstudents.id),(allstudents.total)*sizeof(int));
		//reallocating the space for courses
				allstudents.courseid = (int **) realloc((allstudents.courseid),(allstudents.total)*sizeof(int));
		
				 for(i=0;i<(allstudents.total);i++)
					allstudents.courseid[i] = (int *) realloc((allstudents.courseid),(allstudents.total)*sizeof(int));
	        //finished reallocating memory and reset counter
		
			//allstudents.grades = -1;
			allstudents.cours = (allstudents.cours) + 11;
			//printf(" %d, %d", allstudents.cours, allstudents.grades);
			allstudents.count = 0;
	
		}//end of if statement

	do
	{
                printf("\n\n");
                printmenu();            /*call menu function*/
                scanf("%d", &choice);  /*scan for their input*/
 
                if(choice==1)
                add_course(&allstudents);  /*call add course function*/
		else if(choice==2)
                add_student(&allstudents); //call add student function
                else if(choice==3)
                add_student_and_course(&allstudents); //call add student with course function
                else if(choice==4)
                add_grade(&allstudents);    //   call add grade for a student function
                else if(choice==5)
                print_grade(&allstudents);   //call print grade for a student function
                else if(choice==6)
                print_stu_in_course(&allstudents);
             	else if(choice==7)
                compute_average(&allstudents);   //call average function
                else if(choice==8)
                print_courses(&allstudents);
                else if(choice==9)
                print_students(&allstudents);    //these two print courses and students
/*                else if(choice==10)
                course_average(&allstudents);  //course average function
                else if(choice==11)
                save(&allstudents);
                else if(choice==12)
                load(&allstudents);
*/                else if(choice==13)
                  {
			decide++;
			free(allstudents.id);
			free(allstudents.courseid);
        	  }
	        else
                printf("ERROR try again");    //if they do not type a number on the menu
  
         }while(choice != 13);

	}

return 0;
}
