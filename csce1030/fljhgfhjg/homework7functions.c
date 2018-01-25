#include"header.h"

void playerinfo(struct player* dude) 			   /*this function initializes the players information after reading the chosen player name*/
{
	printf("\nWELCOME!\n\n");
	printf("Please enter a name for your character: \n");
	scanf("%s", dude->name);
	
	dude->x=0;
	dude->y=0;
	dude->gold=0;
	srand(time(NULL));
	dude->lives=(rand()%50+1);

}

void theroom(struct player* dude, char area[23][23]) 	   /*this function initializes each location in the room and randomizes where the pit and gold is placed*/
{

	int x;

	dude->x2=1; dude->y2=0;

	for(i=21;i>0;i--)
	{
		for(j=0;j<21;j++)
		{
			area[dude->x2][dude->y2]= 'x';

			x=rand()%(10+1);
		
               		if(x==1)
 			area[i][j]= 'g';
			else if(x==2 || x==3)
			area[i][j]= 'p';
			else
			area[i][j]= '_';
		}
	}
}

void printplayer(struct player* dude) 			   /*this function prints the player information*/
{
	printf("\t\t\t\t\t\t\t\t\t\t\tYour player: %s\n",dude->name);
	printf("\t\t\t\t\t\t\t\t\t\t\tLives: %d\n",dude->lives);
	printf("\t\t\t\t\t\t\t\t\t\t\tPosition: (%d,%d)\n", dude->x,dude->y);
	printf("\t\t\t\t\t\t\t\t\t\t\tGold: %d\n\n",dude->gold);
}

void printroom(char area[23][23]) 			   /*this function prints the room*/
{
	
		for(i=21;i>0;i--)
		{
			printf("\n"); printf("\t\t\t\t\t\t\t"); printf("|");
        		for(j=0;j<21;j++)
        		{
				printf("%3c|",area[i][j]);
			}
		}
		printf("\n\n\n\n");
}

void movement(struct player* dude, char area[23][23])     /*this function moves the player and adds gold or takes away lives if player lands in a pit*/
{

if((dude->x2) <=21 && (dude->y2)<=20 && (dude->x2)>=0 && (dude->y2)>=0)
{ /*first if statement*/
	
	if(dude->lives >0)
	{
		switch(choice)             /*switch statement to move player*/
		{
			case 'k':
			
			if(dude->y <=20)   /*checks if player is within the boundaries*/
			{
				(dude->y)++;
			}
			area[dude->x2++][dude->y2];   /*moves player up by 1*/
	
			if((area[dude->x2][dude->y2])== '_')
			{
			area[dude->x2--][dude->y2];

				if(area[dude->x2][dude->y2]=='!')
				{
					area[dude->x2][dude->y2]= 'p';
					area[dude->x2++][dude->y2];
					area[dude->x2][dude->y2]='x';
				}

				else{
					area[dude->x2][dude->y2]= '_';
					area[dude->x2++][dude->y2];
					area[dude->x2][dude->y2]='x';
				}
			}
			else if((area[dude->x2][dude->y2])== 'p')    /*this is for when player lands on a pit*/
			{	
				if(dude->lives >0)
				(dude->lives--); if(dude->lives >0)(dude->lives--); if(dude->lives >0)(dude->lives--); if(dude->lives >0)(dude->lives--); 
				if(dude->lives >0)(dude->lives--);
				if(dude->lives >0)
				(dude->lives--); if(dude->lives >0)(dude->lives--); if(dude->lives >0)(dude->lives--); if(dude->lives >0)(dude->lives--); 
				if(dude->lives >0)(dude->lives--);

			area[dude->x2--][dude->y2];

				if(area[dude->x2][dude->y2]=='!')
				{
				area[dude->x2][dude->y2]='p';
				area[dude->x2++][dude->y2];
				area[dude->x2][dude->y2]= '!';
				}
				else{
				area[dude->x2][dude->y2]='_';
				area[dude->x2++][dude->y2];
				area[dude->x2][dude->y2]= '!';
				}
			}
			else if((area[dude->x2][dude->y2])== 'g')  /*this is for when player lands on a gold*/
			{
				area[dude->x2--][dude->y2];
        			if(area[dude->x2][dude->y2]=='!')
        			{
        			        area[dude->x2][dude->y2]= 'p';
        			        area[dude->x2++][dude->y2];
        			        area[dude->x2][dude->y2]='x';
        			}
        			else{
        			        area[dude->x2][dude->y2]= '_';
        			        area[dude->x2++][dude->y2];
        			        area[dude->x2][dude->y2]='x';
        			}	
				(dude->gold)++;
			}
			break;

			case 'j':                                       /*All other cases do the same thing as the first. Just in different directions.*/

			if(dude->y >=0)
			{
				(dude->y)--;
			}
			area[dude->x2--][dude->y2];

			if((area[dude->x2][dude->y2])== '_')
			{
				area[dude->x2++][dude->y2];
        			if(area[dude->x2][dude->y2]=='!')
        			{
                			area[dude->x2][dude->y2]= 'p';
                			area[dude->x2--][dude->y2];
                			area[dude->x2][dude->y2]='x';
        			}
        			else{
                			area[dude->x2][dude->y2]= '_';
                			area[dude->x2--][dude->y2];
                			area[dude->x2][dude->y2]='x';
        			}			
			}       
			else if((area[dude->x2][dude->y2])== 'p')
			{       
        			if(dude->lives >0)
				(dude->lives--); if(dude->lives >0)(dude->lives--); if(dude->lives >0)(dude->lives--); if(dude->lives >0)(dude->lives--);
				if(dude->lives >0)(dude->lives--);
				if(dude->lives >0)
				(dude->lives--); if(dude->lives >0)(dude->lives--); if(dude->lives >0)(dude->lives--); if(dude->lives >0)(dude->lives--); 
				if(dude->lives >0)(dude->lives--);

			area[dude->x2++][dude->y2];

				if(area[dude->x2][dude->y2]=='!')
				{
				area[dude->x2][dude->y2]= 'p';
				area[dude->x2--][dude->y2];
				area[dude->x2][dude->y2]='!';
				}
				else{
        			area[dude->x2][dude->y2]='_';
				area[dude->x2--][dude->y2];
        			area[dude->x2][dude->y2]= '!';
				}
			}       
			else if((area[dude->x2][dude->y2])== 'g')
			{
				area[dude->x2++][dude->y2];
				if(area[dude->x2][dude->y2]=='!')
				{
				        area[dude->x2][dude->y2]= 'p';
				        area[dude->x2--][dude->y2];
				        area[dude->x2][dude->y2]='x';
				}       
				else{   
       					area[dude->x2][dude->y2]= '_';
 					area[dude->x2--][dude->y2];
 					area[dude->x2][dude->y2]='x';
				}       

				(dude->gold)++;
			}       
			break;

			case 'h':

			if(dude->x >=0)
			{
				(dude->x)--;
			}
			area[dude->x2][dude->y2--];

			if((area[dude->x2][dude->y2])== '_')
			{    
				area[dude->x2][dude->y2++];
			        if(area[dude->x2][dude->y2]=='!')
			        {
			                area[dude->x2][dude->y2]= 'p';
			                area[dude->x2][dude->y2--];
			                area[dude->x2][dude->y2]='x';
			        }
			        else{
			                area[dude->x2][dude->y2]= '_';
			                area[dude->x2][dude->y2--];
			                area[dude->x2][dude->y2]='x';
			        }
   
			}       
			else if((area[dude->x2][dude->y2])== 'p')
			{      
				if(dude->lives >0)
				(dude->lives--); if(dude->lives >0)(dude->lives--); if(dude->lives >0)(dude->lives--); if(dude->lives >0)(dude->lives--); 
				if(dude->lives >0)(dude->lives--);
				if(dude->lives >0)
				(dude->lives--); if(dude->lives >0)(dude->lives--); if(dude->lives >0)(dude->lives--); if(dude->lives >0)(dude->lives--); 
				if(dude->lives >0)(dude->lives--);

			area[dude->x2][dude->y2++];

 				if(area[dude->x2][dude->y2]=='!')
				{
        			area[dude->x2][dude->y2]= 'p';
        			area[dude->x2][dude->y2--];
				area[dude->x2][dude->y2]= '!';
				}
				else{
        			area[dude->x2][dude->y2]='_';
				area[dude->x2][dude->y2--];
        			area[dude->x2][dude->y2]= 'p';
				}
			}       
			else if((area[dude->x2][dude->y2])== 'g')
			{       
				area[dude->x2][dude->y2++];
				if(area[dude->x2][dude->y2]=='!')
				{
				        area[dude->x2][dude->y2]= 'p';
				        area[dude->x2][dude->y2--];
				        area[dude->x2][dude->y2]='x';
				}
				else{
				        area[dude->x2][dude->y2]= '_';
				        area[dude->x2][dude->y2--];
				        area[dude->x2][dude->y2]='x';
				}
					(dude->gold)++;
			}

			break;
		
			case 'l':

			if(dude->x <=20)
			{
				(dude->x)++;
			}
			area[dude->x2][dude->y2++];

			if((area[dude->x2][dude->y2])== '_')
			{
				area[dude->x2][dude->y2--];
			        if(area[dude->x2][dude->y2]=='!')
			        {
			                area[dude->x2][dude->y2]= 'p';
			                area[dude->x2][dude->y2++];
			                area[dude->x2][dude->y2]='x';
			        }
			        else{
			                area[dude->x2][dude->y2]= '_';
			                area[dude->x2][dude->y2++];
			                area[dude->x2][dude->y2]='x';
			        }
			}
			else if((area[dude->x2][dude->y2])== 'p')
			{
				if(dude->lives >0)
				(dude->lives--); if(dude->lives >0)(dude->lives--); if(dude->lives >0)(dude->lives--); if(dude->lives >0)(dude->lives--); 
				if(dude->lives >0)(dude->lives--);
				if(dude->lives >0)
				(dude->lives--); if(dude->lives >0)(dude->lives--); if(dude->lives >0)(dude->lives--); if(dude->lives >0)(dude->lives--); 
				if(dude->lives >0)(dude->lives--);

			area[dude->x2][dude->y2--];	
			
				if(area[dude->x2][dude->y2]=='!')
				{
				area[dude->x2][dude->y2]= 'p';
				area[dude->x2][dude->y2++];
				area[dude->x2][dude->y2]='!';
				}
				else{
				area[dude->x2][dude->y2]='_';
				area[dude->x2][dude->y2++];
				area[dude->x2][dude->y2]= '!';
				}
        		}
			else if((area[dude->x2][dude->y2])== 'g')
			{
				area[dude->x2][dude->y2--];
				if(area[dude->x2][dude->y2]=='!')
				{
				        area[dude->x2][dude->y2]= 'p';
				        area[dude->x2][dude->y2++];
				        area[dude->x2][dude->y2]='x';
				}
				else{
				        area[dude->x2][dude->y2]= '_';
				        area[dude->x2][dude->y2++];
				        area[dude->x2][dude->y2]='x';
				}
				(dude->gold)++;
			}

			break;	
	
			case 'q':           /*this case is for when the player types 'q' and wants to quit the game*/
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
			printplayer(dude);
			printf("\n\t\t\t\t\t\t\t\t\t\t\tGOODBYE!\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		}   /*end of switch*/
	}

	else if(dude->lives == 0)    /*this is when the player has run out of lives*/
	{
		choice= 'q';

		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		printf("\t\t\t\t\t\t\t\t\t\t*********************\n");
		printf("\t\t\t\t\t\t\t\t\t\t***** GAME OVER *****\n");
		printf("\t\t\t\t\t\t\t\t\t\t*********************\n\n\n\n");
		printf("\t\t\t\t\t\t\t\t\t\tYour player: %s\n",dude->name);
		printf("\t\t\t\t\t\t\t\t\t\tLives: 0\n");
		printf("\t\t\t\t\t\t\t\t\t\tPosition: (%d,%d)\n", dude->x,dude->y);
		printf("\t\t\t\t\t\t\t\t\t\tGold: %d\n\n",dude->gold);
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");	
		
	}

} /*end of the first if statement*/


	if((dude->x2) >21 || (dude->y) >20)     /*all of these go with the first if statement*/
	{
		(dude->x2)--;                       /*they keep the player on the board*/
		(dude->y)--;
		area[dude->x2][dude->y2]= 'x';
	}
	else if((dude->x2) <0 || (dude->y) <0)
	{
		(dude->x2)++;
		(dude->y)++;
		area[dude->x2][dude->y2]= 'x';
	}
	else if((dude->y2) >20 || (dude->x) >20)
	{
		(dude->y2)--;
		(dude->x)--;
		area[dude->x2][dude->y2]= 'x';	
	}
	else if((dude->y2) <0 || (dude->x) <0)
	{
		(dude->y2)++;
		(dude->x)++;
		area[dude->x2][dude->y2]= 'x';
	}
}                    /*end of function*/


