#include<cstdlib>
#include<iostream>
#include"class.h"

using namespace std;

Node::Node()
{
        data=0;     //initializing everything to NULL or 0
        prev=NULL;
        next=NULL;
}

List::List()
{
        tail=NULL;      //initializing everything to NULL
        head=NULL;
        temp=NULL;
	id=NULL;
	print=NULL;
	search=NULL;
}

void Node::addleft(int num)
{	
	data=num; //setting data equal to the value stored in num
}

void Node::addright(int num)
{
	data=num; //setting data equal to the value stored in num
}

/*
void List::AddL(int num)
{

}
*/
