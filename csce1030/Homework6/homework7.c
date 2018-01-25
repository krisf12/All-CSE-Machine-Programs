#include"header.h"

int main(void)
{


printf("\nCSCE1030\nHomework7\nKristian Forestier\nkf0106\nkristianforestier@my.unt.edu\n\n");

playerinfo(&dude); /*call the functions that initialize player and room*/
theroom(&dude, area);

		while(choice!= 'q') /*this is the while loop to continue until the user wants to quit*/
		{
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"); /*these new lines are for aesthetic purposes*/
			printplayer(&dude);
			printroom(area);
			printf("\t\t\t\t\t\t\t\t\t   Move using [k,j,l,h] or type 'q' to quit:\n");
			choice=getchar();

			if(choice== 'q' || choice== 'w' || choice== 's' || choice== 'a' || choice== 'd')
			{
				movement(&dude, area);
			}
		}


return 0;
}


