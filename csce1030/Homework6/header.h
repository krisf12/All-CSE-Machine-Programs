#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>


int i;
int j;

struct player{         /*a struct to store  player information*/
        char name[25];
        int lives;
        int gold;
        int x;
        int y;
	int x2;
	int y2;
 }; struct player dude; 

char area[23][23]; /*the data structure for the area*/ 


char choice;


void playerinfo(struct player* dude);
void theroom(struct player* dude, char area[23][23]);
void printplayer(struct player* dude);                  /*the function prototypes*/
void printroom(char area[23][23]);
void movement(struct player* dude, char area[23][23]);

