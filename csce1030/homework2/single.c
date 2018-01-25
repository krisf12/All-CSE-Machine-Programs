//
//
// Kristian Forestier
// 9/28/13
// This program asks the user questions, takes their input, which can be in the form of "y/Y" or "n/N", and writes a reccomendation on the screen based off of their input.
//
//

#include <stdio.h>

int main(void)
{
    char answer;
    
    printf("Are you running a fever?\n");	//this is the first line which will prompt the user to enter yes or no.//
    scanf(" %c", &answer);
    printf("\n");

    if(answer == 'n' || answer == 'N')        //if they enter no for the first question it will ask another and then terminate after their input//
    {
	printf("Do you have a runny nose or cough?\n");
	scanf(" %c", &answer);
	printf("\n");
	if(answer == 'y' || answer == 'Y')
	{
	printf("\n");
	printf("Get some rest");    //if they answer yes to having a "runny nose or cough", even after saying no to "running a fever", it will say "get some rest"//
	printf("\n\n");
	}
	else printf("You are healthy");
	printf("\n\n");
    }
    else if(answer == 'y' || answer == 'Y')  //if they answer yes for the first question it will ask them the following set and then terminate// 
{
    	printf("\n\n");
    
    	printf("Do you have a runny nose or cough?\n");
    	scanf(" %c", &answer);
    
    if(answer == 'y' || answer == 'Y')  //if they answer yes to the "runny nose or cough" it will tell them to "see a doctor soon".//
    {
        printf("\n");
        printf("You have a fever, and a runny nose or cough.");
	printf("\n\n");
	printf("See a Doctor Soon");
        printf("\n\n");
    }
    else if(answer == 'n' || answer == 'N') //even if they answer no to the "runny nose or cough" it will tell them to see a doctor soon because they have a fever.//
    {
        printf("\n\n");
        printf("You have a fever, but no runny nose or cough.");
	printf("\n\n");	
	printf("See a Doctor Soon");
        printf("\n\n");
    }
}
    return 0;
}

