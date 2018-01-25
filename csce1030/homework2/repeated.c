//
// Kristian Forestier
//
// 9/28/13
//
// This program asks the user questions, takes their input, which can be in the form of "y/Y" or "n/N", 
// and writes a reccomendation on the screen based off of their input.
//

#include <stdio.h>

int main(void)
{
    char answer, contin, restart;

while(restart != 'n' || restart != 'N')          //this while loop goes over the entire program and coincides with the question at the end of the program//

    {
	printf("\n");
	printf("CSCE 1030.001\nHomework 2\nKristian Forestier 10845548\nkristianforestier@my.unt.edu\n\n");  

	printf("Are you running a fever?\n");            //this is the first line which will prompt the user to enter yes or no//
	scanf(" %c", &answer);
	printf("\n");  

	printf("Do you want to continue?\n");
	scanf(" %c", &contin);
	printf("\n");
	   while(contin == 'n' || contin == 'N')         //if the user enters "n" or "N" for "do you want to continue" the program will terminate//
	   return 0;

    if(answer == 'n' || answer == 'N')                   //if they enter no for the first question it will ask another and then terminate after their input//
{
	printf("\n");
	printf("Do you have a runny nose or cough?\n");
	scanf(" %c", &answer);
	printf("\n");

	printf("Do you want to continue?\n");
	scanf(" %c", &contin);
	   while(contin == 'n' || contin =='N')         //if the user enters "n" or "N" for "do you want to continue" the program will terminate//
	   return 0;

    if(answer == 'y' || answer == 'Y')            //if they answer yes to having a "runny nose or cough", after saying no to "running a fever", it will say "get some rest"//
    {
	printf("\n\n");
	printf("You have a runny nose or cough, but no fever");
	printf("\n\n");
	printf("Get some rest");  
	printf("\n\n");
    }
    else if(answer == 'n' || answer == 'N')
    {
	printf("\n\n");
	printf("You are not running a fever, and do not have a runny nose or cough.");
	printf("\n\n");
	printf("You are healthy.");                       //if they answer "no" to both questions then it will say "you are healthy"//
	printf("\n\n");
    }
}

    else if(answer == 'y' || answer == 'Y')              //if they answer yes for the first question it will ask them the following set and then terminate//
{
    	printf("\n");
        printf("Do you have a runny nose or cough?\n");
    	scanf(" %c", &answer);
	printf("\n");
	
	printf("Do you want to continue?\n");
        scanf(" %c", &contin);
	printf("\n");
           while(contin == 'n' || contin =='N')       //if the user enters "n" or "N" for "do you want to continue" the program will terminate//
           return 0;

    if(answer == 'y' || answer == 'Y')            //if they answer yes to the "runny nose or cough" it will tell them to "see a doctor soon".//
    {
        printf("\n");
        printf("You have a fever, and a runny nose or cough.");
	printf("\n\n");
	printf("See a Doctor Soon");
        printf("\n\n");
    }
    else if(answer == 'n' || answer == 'N')         //if they answer no to the "runny nose or cough" it will tell them to see a doctor soon because they still have a fever.//
    {
        printf("\n");
        printf("You have a fever, but no runny nose or cough.");
	printf("\n\n");	
	printf("See a Doctor Soon");
        printf("\n\n");
    }
}
	{
	printf("\n");
	printf("Do you want to continue?\n");
	scanf(" %c", &restart);
	}
	if(restart == 'n' || restart == 'N')
	return 0;
	
    }
	return 0;
}
