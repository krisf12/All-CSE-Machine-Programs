// Kristian Forestier
// 4/11/14
// Lab10
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct account {
  char   *name;
  float  balance;
  struct account *next;
};

int main()
{
	int		 listID;
  float  balance;
  char   name[20];                           //array to store the data for each name
  struct account *list1head = NULL;          // initialize list1head to null
  struct account *list1tail = NULL;          // initialize tail to null
	struct account *list2head = NULL;    //same thing with list 2 head
  struct account *list2tail = NULL;         //same thing with list 2 tail
  struct account *walk = NULL;              //initialize the walking mechanism to null

int count1=0, count2=0; //these are used to check the size of each list

  while(scanf("%d%s%f", &listID, name, &balance) != EOF) {  //this reads the entire file and scans an integer and a string and a float
		if(listID == 1) //checks for the number
		{
			if(list1head == NULL) //chacks if list is empty
			{

				list1head=(struct account *)malloc(sizeof(struct account));
				list1head->next=NULL;
				list1tail=list1head;

    			}
			else 
			{

				list1tail->next = (struct account *) malloc(sizeof(struct account));
  				list1tail= list1tail->next;
  				list1tail->next = NULL;

			}
			
			list1tail->name=(char*) malloc(sizeof(char) * strlen(name) + 1);
			strcpy(list1tail->name, name);
			list1tail->balance= balance;
	
		}


		else 
		{ // listID == 2
      			if(list2head == NULL) //chacks if list is empty
			{

				list2head=(struct account *)malloc(sizeof(struct account));
				list2head->next=NULL;
				list2tail=list2head;

      			}
      			else 
			{
				list2tail->next = (struct account *) malloc(sizeof(struct account));
				list2tail= list2tail->next;
				list2tail->next = NULL;
	        	}
	
			list2tail->name=(char*) malloc(sizeof(char) * strlen(name) + 1);
	       		strcpy(list2tail->name, name);
		        list2tail->balance= balance;
		}
  }

	walk=list1head;

	while(walk!=NULL){  //counts the size of list1
		count1++;
		walk=walk->next;	
	}

	walk=list2head;
	
	while(walk!=NULL){  //counts the size of list 2
		count2++;
		walk=walk->next;
	}
	
	if(count1>count2) //compares
	{
		list1tail->next=list2head;  //appends list 2 to end of list 1
	}

	else list2tail->next=list1head;

	walk = list1head;
  while(walk != NULL) {
    printf("%20s %8.2f\n", walk->name, walk->balance);   //printing lists
    walk = walk->next;
  }
	// print list2
	printf("----------------\n");
	walk = list2head;
  while(walk != NULL) {
    printf("%20s %8.2f\n", walk->name, walk->balance);  //printing lists
    walk = walk->next;
  }


  return;
}
