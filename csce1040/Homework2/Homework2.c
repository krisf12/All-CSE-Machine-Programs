#include<stdio.h>
#include"Structuredeclarations.h"

int main(void)
{

	printf("\n\nCSCE 1040\nHomework 2\nKristian Forestier\nkristian.forestier@my.unt.edu\n");

	int choice,k, j;
   
		for(j=0;j<400; j++)
		{
		allstudents[j].courseid=-1; allstudents[j].id=-1;

			for(k=0;k<10;k++)
			{
				allstudents[j].grades[k]=-1;
			}		
		}
		
		for(j=0; j<25; j++)
		{
		allcourses[j].cid=-1;
		}
	do
	{
                printf("\n\n");
                printmenu();            /*call menu function*/
                scanf("%d", &choice);  /*scan for their input*/
 
                if(choice==1)
                add_course(&allstudents,&allcourses);  /*call add course function*/
		else if(choice==2)
                add_student(&allstudents); /*call add student function*/
                else if(choice==3)
                add_student_and_course(/*&allcourses,*/ &allstudents); /*call add student with course function*/
                else if(choice==4)
                add_grade(&allcourses, &allstudents);    //   call add grade for a student function
                else if(choice==5)
                print_grade(&allstudents);   //call print grade for a student function
                else if(choice==6)
                print_stu_in_course(&allstudents);
              	else if(choice==7)
                compute_average(&allstudents);   //call average function
                else if(choice==8)
                print_courses(&allstudents, &allcourses);
                else if(choice==9)
                print_students(&allstudents);    //these two print courses and students
                else if(choice==10)
                course_average(&allstudents, &allcourses);  //course average function
                else if(choice==11)
                save(&allstudents, &allcourses);
                else if(choice==12)
                load(&allstudents, &allcourses);
                else if(choice==13)
                ;
                else
                printf("ERROR try again");    //if they do not type a number on the menu
  
         }while(choice != 13);

return 0;
}
