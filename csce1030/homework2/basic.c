#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char answer;
    
    printf("Are you running a fever?\n");
    scanf(" %c", &answer);

    if(answer == 'n' || answer == 'N')
    {
	printf("\n");
        printf("You are fine");
	printf("\n\n");
    }
    else if(answer == 'y' || answer == 'Y')
{
    	printf("\n\n");
    
    	printf("Do you have a runny nose or cough?\n");
    	scanf(" %c", &answer);
    
    if(answer == 'y' || answer == 'Y')
    {
        printf("\n");
        printf("You have a fever, and a runny nose or cough.");
        printf("\n\n");
    }
    else if(answer == 'n' || answer == 'N')
    {
        printf("\n\n");
        printf("You have a fever, but no runny nose or cough.");
        printf("\n\n");
    }
}
    return 0;
}

