#include<iostream>
#include<cstdlib>
#include<string>
#include"class.h"
#include"Prototypes.h"

using namespace std;


int main(void)
{

cout<<endl; cout<<endl; cout<<"CSCE 1040"<<endl; cout<<"Homework 5"<<endl; cout<<"Kristian Forestier"<<endl; cout<<"kristian.forestier@my.unt.edu"<<endl;

Menu menu;
string choice;
int i=0;

Student *shead=NULL, *scurrent=NULL, *students= new Student();
Course *courhead=NULL,  *ccurrent=NULL, *courses= new Course();
Enrollment *enhead=NULL, *encurrent=NULL, *enrolls= new Enrollment();

	do
	{
		menu.printmenu();
		cin>>choice;
		
		if(choice== "1")
		{
			if(courhead==NULL)
			{
				ccurrent=courhead=addcourse();	
			}
			else
			{
				ccurrent=courhead;
				while(ccurrent->getnext() != NULL)
					ccurrent=ccurrent->getnext();
					
				ccurrent->setnext(addcourse());
			}
		}
		else if(choice== "2")
		{
			if(shead==NULL)
			{
				scurrent=shead=addstudent();
			}
			else
			{
				scurrent=shead;
				while(scurrent->getnext() != NULL)
					scurrent=scurrent->getnext();

				scurrent->setnext(addstudent());
			}
		}
		else if(choice== "3")
		{
			if(enhead==NULL)
			{
				encurrent=enhead=addstocourse();
			}
			else
			{
				encurrent=enhead;
				while(encurrent->getnext()!= NULL)	
				        encurrent=encurrent->getnext();

				encurrent->setnext(addstocourse());
			}
		}
		else if(choice== "4")
		{
			enhead->addgrades(i);
			i++;
		}
		else if(choice== "5")
		{
			enhead->printgrades(i);
		}
		else if(choice== "6")
		{
			enhead->printstuincourse();
		}
		else if(choice== "7")
		;
		else if(choice== "8")
		;
		else if(choice== "9")
		;
		else if(choice== "10")
		;
		else if(choice== "11")
		;
		else if(choice== "12")
		;
		else if(choice=="quit" || choice=="13")
			return 0;
	}
	while(choice!="quit");

	return 0;
}
