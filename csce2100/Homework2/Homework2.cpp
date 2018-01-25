#include<cstdlib>
#include<iostream>
#include<string>
#include"class.h"
using namespace std;

//void List::printright();
//void List::SetHead();

int main(void)
{
	string user;  //user input
	int num;
	bool check=true; //bool checking for true/false start with true
	
	List *l= new List; //allocating mem
	Node *n; //class Node pointer

	do
	{
		cout<<endl;                  //the menu for the user to make a selection
		cout<<"MENU:"<<endl<<endl;
		cout<<"addleft"<<endl;
		cout<<"addright"<<endl;
		cout<<"left"<<endl;
		cout<<"right"<<endl;
		cout<<"search"<<endl;
		cout<<"print"<<endl;
		cout<<"quit"<<endl<<endl;
	
		cout<<"list> ";cin>>user;  //prompt
		
		if(user=="addleft")
		{
			n = new Node; //allocating mem
			cin>>num;		//taking in user input	
				
			if(l->head==NULL && l->tail==NULL) //checking for empty list
			{
				n->addleft(num); //callfunction addleft
				l->head=n;  //set head equal to n
				l->tail=n;  //set tail equal to n
				l->id=n;    //set id equal to n
				l->print=n; //set print equal to n
			}
			else if(l->head == l->tail) //checking for single node in list
			{
				n->addleft(num); //call addleft
				n->next=l->head; //moves the head to the next node
				l->head->prev=n; //sets the previous node equal to the value
				l->head=n; //sets the head equal to the value
			}
			else if(l->id==l->head) //
			{
				n->addright(num); //call function addright
				n->next=l->id; //move current right
				l->id->prev=n; 
				l->head->prev=n;
				l->head=n;
			}
			else //all other cases
			{
				n->addleft(num);
				l->left=l->id->prev;
				n->next=l->id;
				n->prev=l->id->prev;
				l->id->prev=n;
				l->left->next=n;
			}
		}
		else if(user=="addright")            //this function does the same as the last function except in the other direction
		{
			n = new Node; //allocating mem
			cin>>num;
			
			if(l->head==NULL && l->tail==NULL) //checking for empty list
			{
				n->addright(num);
				l->head=n;
				l->tail=n;
				l->id=n;
				l->print=n;
			}
			
			else if(l->head == l->tail)
			{
				n->addright(num);
				n->prev=l->tail;
				l->tail->next=n;
				l->tail=n;
			}
			
			else if(l->id==l->tail)
			{
				n->addright(num);
				n->prev=l->id;
				l->id->next=n;
				l->tail->next=n;
				l->tail=n;
			}
			
			else
			{
				n->addright(num);
				n->prev=l->id;
				n->next=l->id->next;
				l->id->next=n;
			}
			
		}
		else if(user=="left")
		{
			if(l->head==NULL && l->tail==NULL) //error checking for empty list
				cout<<"Error! Empty list."<<endl;

			else
			{
				if(l->id->prev!=NULL) //checks if there is a number to the left
				{
					l->temp=l->id;         //this is moving the pointer left temporarily and then printing the value
					l->id=l->id->prev;
					l->id->next=l->temp;
					cout<<"Value: "<<l->id->data<<endl;
				}

				else
					cout<<"Error! No more elements in the list."<<endl; //if we have reached the head of the list
			}
		}	
		else if(user=="right")
		{
			if(l->head==NULL && l->tail==NULL) //error checking for empty list
				cout<<"Error! Epmty list."<<endl;
			else
			{
				if(l->id->next!=NULL) //checks if there is a number to the right
				{
					l->temp=l->id;
					l->id=l->id->next;    //this is moving the pointer right temporarily and printing the value
					l->id->prev=l->temp;
					cout<<"Value: "<<l->id->data<<endl;
				}
				else
					cout<<"Error! No more elements in the list."<<endl; //if we have reached the tail of the list
			}
		}	
		else if(user=="search")
		{
			cin>>num;
			int i=0; //used to check if true

			if(l->head==NULL && l->tail==NULL)    //checks for empty list
				cout<<"Error! Empty list."<<endl;
			else
			{
				l->search=l->head; //start at head
				while(check)
				{
					if(num==l->search->data) //checks for value
						i++;
					if(l->search->next!=NULL)  //moving along the list
						l->search=l->search->next;
					else if(l->search->next==NULL) //did not find value
						check=false;
				}

				if(i>0) //i was incremented if the value was found
					cout<<"true"<<endl;
				else
					cout<<"false"<<endl; //the value was not found
			}
		}		
		else if(user=="print")
		{
			if(l->head==NULL && l->tail==NULL)  //checking for an empty list
				cout<<"Error! Empty list.";
			else
			{
				l->print=l->head;  //start at head
				while(check)  //loop until end of list
				{
					cout<<l->print->data; //print nodes

					if(l->print->next!=NULL) //moving along list until empty
					{
						cout<<"-"; //printing hyphens
						l->print=l->print->next; //setting print pointer to next value
					}
					else if(l->print->next==NULL) //reached end of list
						check=false;
				}
			}
			cout<<endl;
		}
		else if(user=="quit")
		{
			cout<<"Goodbye!";cout<<endl<<endl; 
			return 0;  //quits the program
		}
		else if(user!="addleft" && user!="addright" && user!="left" && user!="right" && user!="search" && user!="print") //error checking
			{	
				cout<<endl<<endl;
				cout<<"ERROR Try Again:"<<endl<<endl; //error message
			}

	}while(user!="quit");  //loop until quit is typed
}
