//	Kristian Forestier
//	csce 2110
//	Programming Assignment 3
//	This is main, this is where I created two arrays and linked them with the student ID by using for loops and if statements.

#include <cstdlib>
#include <iostream>
#include <string>
#include "Class.h"

using namespace std;


int main()
{
	string stu_gra;			//this is for user selection of student, grade, or quit
	string option;			//this is for add and delete selection
	int num;
	Students mystud[100];		//the fixed array for student class
	Grades mygrade[100];		//the fixed array for grade class
	int i;
	string name;			//user input
	string lname;			//user input
	string classroom;		
	char grade;
	bool found = false;		//bool flag for checking different circumstances

	do
	{	
	cout<<"Tables> ";		//prompt
	cin>>stu_gra;

		if(stu_gra !="quit")		//loops until user types quit
		{
			if(stu_gra =="students")		//checks for user typing students
			{
				cin>>option;			
				if(option== "add")		//checks for add
				{
					cin>>num;		//student id number
					cin>>name;		//student name
					cin>>lname;		//last name
					
                                        int j;
                                        int hold;
                                        string namehold;
                                        string lnamehold;
	
					for(i=0; i<100; i++)	
					{
						if(mystud[i].id==0)	//checks for empty spot in database
						{
							mystud[i].id = num;				
							mystud[i].Name = name;		//placing student info into that spot
							mystud[i].last_name = lname;
							break;
						}
					}
                                                for(i=0; i<100; i++)
                                                {
                                                        if(mystud[i].id != 0)   //checking only spots that are not empty
                                                        {
                                                                found= true;
                                                                for(j=0; j<50; j++) //array for bubble sort
                                                                {
                                                                        if(mystud[j].id != 0)   //checking only spots that are not empty
                                                                        {
                                                                                if(mystud[j].id > mystud[j+1].id) //bubble sort check
                                                                                {
                                                                                        hold = mystud[j].id;
                                                                                        mystud[j].id = mystud[j+1].id;          //bubble sorting
                                                                                        mystud[j+1].id = hold;
				////////////////////////
                                                                                        namehold = mystud[j].Name;
                                                                                        mystud[j].Name = mystud[j+1].Name;      //bubble sorting
                                                                                        mystud[j+1].Name = namehold;

                                                                                        lnamehold = mystud[j].last_name;
                                                                                        mystud[j].last_name = mystud[j+1].last_name;    //bubble sorting
                                                                                        mystud[j+1].last_name = lnamehold;
                                                                                }
                                                                        }       
                                                                }       
                                                        }       
                                                }       

				}				
				else if(option =="delete")	//checks for delete
				{
					cin>>num;
					found = false;		//initialize bool flag
					for(i=0; i<100; i++)
					{	
						if(mystud[i].id==num)
						{
							found = true;	//flag = true (student was found in database)
						}
					}
						if(found == true)
						{
							for(i=0; i<100; i++)
							{
								if(mygrade[i].id==num)	//checks for all instances for that id
								{
								 	mystud[i].id= 0;
								 	mystud[i].Name= " "; 
								 	mystud[i].last_name= " ";	//setting everything blank
								 	mygrade[i].id= 0;
								 	mygrade[i].classroom= " ";
								 	mygrade[i].grade= " ";
								}
							}
							for(i=0; i<100; i++)
							{
								if(mystud[i].id==num)
								{
										mystud[i].id= 0;
										mystud[i].Name= " ";
								}
							}
						}
						else if(found == false)		//flag was not initiated (student was not entered into database) 
						{
							cout<<"Error: student not in database"<<endl;
						}
				}
				else if(option == "display")			//check for display option
				{
					int j;
					int hold;
					int ghold;
					string namehold;
					string gnamehold;
					string gnamehold2;
					string lnamehold;

					found= false;			//initialize flag to false
						for(i=0; i<100; i++)
						{
							if(mystud[i].id != 0)	//checking for database not empty
							{
								found= true;
							}
						}
						if(found==true)	//checking if the database was not empty
						{
							for(i=0; i<100; i++)
							{
								if(mystud[i].id != 0)	//checking for only spots that are not empty
								{
									cout<< "(";
									cout<< mystud[i].id;
									cout<< ",";
									cout<< mystud[i].Name;		//printing and formatting
									cout<< ",";
									cout<< mystud[i].last_name;
									cout<< ")-";
								}
							}
						}
						if(found== false)			//if no flag then there was nothing in database
						{
							cout<<"Error: empty list"<<endl;
						}
					cout<<endl;
				}
				else							//check for all incorrect inputs
				{
					cout<<"Error: invalid input"<<endl;		
				}
			}

			else if(stu_gra =="grades")		//check for grades option
			{
				cin>>option;
				found= false;			//initialize flag to false

				if(option== "add")              //check for add option
				{
					cin>>num;
					cin>>classroom;
					cin>>grade;
					int j;
					
					for(i=0; i<100; i++)		
					{
						if(mystud[i].id==num)	//check if student in database already				
						{
							found=true;	//flag = true
						}

					}
					if(found==true)			//if student found in database
					{
						for(i=0; i<100; i++)
						{
							if(mygrade[i].id==0)	//check for empty grade slot
							{
								mygrade[i].id = num;			//set id entered to grade database position
								mygrade[i].classroom = classroom;	//set classroom name
								mygrade[i].grade = grade;		//set grade
								break;
							}
						}	
						for(i=0; i<50; i++)
						{
						        if(mygrade[i].id != 0)   //checking only spots that are not empty
						        {
                						for(j=0; j<100; j++) //array for bubble sort
               							{
                        						if(mygrade[j].id != 0)   //checking only spots that are not empty
                        						{
                         							if(mygrade[j].id > mygrade[j+1].id) //bubble sort check
                                						{
                                        						int holding = mygrade[j].id;
                                        						mygrade[j].id = mygrade[j+1].id;          //bubble sorting
                                        						mygrade[j+1].id = holding;
                                        						string classholding = mygrade[j].classroom;
                                        						mygrade[j].classroom = mygrade[j+1].classroom;      //bubble sorting
                                        						mygrade[j+1].classroom = classholding;
                                 	  						string gradehold = mygrade[j].grade;
                                        						mygrade[j].grade = mygrade[j+1].grade;    //bubble sorting
                                        						mygrade[j+1].grade = gradehold;
                                						}
                        						}
                						}
        						}
						}
					}
					else
						cout<<"Error student not enrolled"<<endl;		//if flag = false
				}
				else if(option =="delete")	//check for delete option
				{
					found = false;			//initialize flag to false
					cin>>num;
					cin>>classroom;
					for(i=0; i<100; i++)
					{
						if(mygrade[i].id == num)		//check for grade found
						{
							mygrade[i].classroom = " ";	//delete classroom
							mygrade[i].grade = " ";		//delete grade
							mygrade[i].id = 0;		//delete id
							found = true;			//flag = true
							break;
						}
					}		
					if(found== false)				//if no grades found
					{
						cout<<"Error: no grades in database"<<endl;
					}
					
				}
				else if(option == "display")	//check for display option
				{
					found = false;					//initialize flag to false
        	                        	for(i=0; i<100; i++)
	                               		{
                                        	       	if(mygrade[i].id != 0)		//check for an empty database
                                        	        {
								found=true;
                                        	                cout<< "(";
                                        	                cout<< mygrade[i].id;
                                        	                cout<< ",";			//printing and formatting
                                        	                cout<< mygrade[i].classroom;
                                        	                cout<< ",";
                                        	                cout<< mygrade[i].grade;
                                        	                cout<< ")-";
                                        	        }
                                       		}
						if(found== false)			//the database was empty
						{
							cout<<"Error: empty list"<<endl;
						}
                                        cout<<endl;
				}
				else
				{
					cout<<"Error: invalid input"<<endl;		//if user did not enter appropriate input
				}
			}
			else
				cout<<"Error: invalid input"<<endl;		//if user did not enter appropriate input

		}
	}
	while(stu_gra != "quit");		//loop until quit is typed
	return 0;
}
