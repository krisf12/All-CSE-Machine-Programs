#include<iostream>
#include<cstdlib>
#include"class.h"
#include"Prototypes.h"

using namespace std;

void Menu::printmenu()
{
cout<<endl;
cout<<"1: Add new course"<<endl;cout<<"2: Add new student"<<endl;cout<<"3: Add a student to a course"<<endl;
cout<<"4: Add grades for student in a course"<<endl;cout<<"5: Print a list of all grades for a student in a course"<<endl;
cout<<"6: Print a list of all students in a course"<<endl;cout<<"7: Compute the average for a student in a course"<<endl;
cout<<"8: Print a list of all courses"<<endl;cout<<"9: Print a list of all students"<<endl;
cout<<"10: Compute the average for a course"<<endl; cout<<"11: Save grade book"<<endl;cout<<"12: Load grade book"<<endl;cout<<"13: Quit"<<endl<<endl;
}

Course::Course()
{
}

Student::Student()
{
}

Enrollment::Enrollment()
{
}

void Course::setcourse(int cid, string cname)
{
	courseid=cid;
	coursename=cname;
	next=NULL;
}

void Course::setnext(Course* cnext)
{
	next=cnext;
}

Course* Course::getnext()
{
	return next;
}

int Course::getid()
{
	return courseid;
}

//string Course::getname()
//{
//	return coursename;
//}

Course* addcourse()
{
	string coursename;
	int cnum;

	Course *course=new Course;

	cout<<"Enter the course name:"<<endl;
	cin>>coursename;
	cout<<endl<<"Enter the course number:"<<endl;
	cin>>cnum;
	
	if(cnum>9999 || cnum<1)
	{
		cout<<"ERROR INVALID COURSE NUMBER"<<endl;
		return NULL;
	}
	
	course->setcourse(cnum,coursename);	
	return course;
}


void Student::setstudent(int sid, string sname)
{
	studentid=sid;
	studentname=sname;
	next=NULL;
}

void Student::setnext(Student* snext)
{
	next=snext;
}

Student* Student::getnext()
{
	return next;
}

int Student::getid()
{
	return studentid;
}

//string Student::getname()
//{
//
//}


Student* addstudent()
{
	string stuname;
	int id;

	Student *student=new Student;

	cout<<"Enter the student name:"<<endl;
	cin>>stuname;
	cout<<endl<<"Enter the student ID:"<<endl;
	cin>>id;

	if(id<1 || id>99999999)
	{
		cout<<"ERROR INVALID ID NUMBER"<<endl;
		return NULL;
	}
						
	student->setstudent(id,stuname); 
	return student;
}

Enrollment* addstocourse()
{

	string coursename;
	int id, cid;

	Enrollment *enrolls=new Enrollment;

	cout<<"Enter the student id to enroll:"<<endl;
	cin>>id;
	cout<<"Enter the course name to enroll the student into:"<<endl;
	cin>>coursename;
	cout<<"Enter the course number:"<<endl;
	cin>>cid;
	
	if(id<1 || id>99999999)
	{
		cout<<"ERROR INVALID INPUT"<<endl;
		return NULL;
	}	

	enrolls->setenroll(id, cid, coursename);
	return enrolls;

}

void Enrollment::setenroll(int id, int cid, string coursename)
{
	studentids=id;
	courseids=cid;
	coursenames=coursename;
}

void Enrollment::setnext(Enrollment* enext)
{
	next=enext;
}

Enrollment* Enrollment::getnext()
{
	return next;
}

int Enrollment::getcourseid()
{
	return course->getid();
}

void Enrollment::addgrades(int i)
{
	string gradecourse;
	int gradecourseid;
	int gradeid;
	int g;
	Enrollment *temp=next;

	cout<<"Enter the course name:"<<endl;
	cin>>gradecourse;
	cout<<"Enter the course number:"<<endl;
	cin>>gradecourseid;
	cout<<"Enter the student id:"<<endl;
	cin>>gradeid;
	cout<<"Enter the grade:"<<endl;
	cin>>g;
	
	if(gradecourse==coursenames && gradecourseid== courseids && gradeid== studentids)
	{
		grade[i]=g;
	}
	else
	{
		while(1)
		{	
			if(temp==NULL)
				break;
				
			if(temp->coursenames==gradecourse && temp->courseids==gradecourseid && temp-> studentids==gradeid)
		{	grade[i]=g; return;}
			else
				temp=temp->next;			
		}
		cout<<"Student not found"<<endl;
	}
}

void Enrollment::printgrades(int i)
{
        string gradecourse;
        int gradecourseid=0;
        int gradeid=0;
        Enrollment *temp=next;

	int tempStudentID=0, tempval=0;


        cout<<"Enter the course name:"<<endl;
        cin>>gradecourse;
        cout<<"Enter the course number:"<<endl;
        cin>>gradecourseid;
        cout<<"Enter the student id:"<<endl;
        cin>>gradeid;

        if(gradecourse==coursenames && gradecourseid== courseids && gradeid== studentids)
        {
                for(int j=0; j<i; j++)
		{
			cout<<" "<<endl;
			cout<<grade[j];
		}
        }
        else
        {
                while(1)
                {
                        if(temp==NULL)
                                break;

                        if(temp->coursenames==gradecourse && temp->courseids==gradecourseid && temp->studentids==gradeid)
                	{       
				for(int j=0; j<i; j++)
				cout<<grade[j];
				 return;
			}
                        else
                                temp=temp->next;
                }
                cout<<"Student not found"<<endl;
        }
}

//string Enrollment::getcoursename()
//{
//	return course->getname();
//}

int Enrollment::getstudentid()
{
	return student->getid();
}

//string Enrollment::getstudentname()
//{
//	return student->getname();
//}

void Enrollment::printstuincourse()
{

	string tempcourse;
	int tempcid, tempval=0;

//	cout<<"\n\n\nNo students have been added to a course."<<endl;
//		return;

	cout<<"Enter the course number:"<<endl;
	cin>>tempcid;

//	encurrent=enhead;
/*
	while(encurrent!=NULL)
	{
		//make user the course id exists
		if(encurrent->getcourseid()==tempcourse)
		{
			tempval=1;
			break;
		}
	
		//traverse
		else
			encurrent=encurrent->getnext();
	}
	
	encurrent=enhead;

	if(tempval==1)
	{
			cout<<"Enter the course name:"<<endl;
			cin>>tempcourse;			

			//traverse list
			while(encurrent!=NULL)
			{
				//make sure course id and name and student id exist together
				if(encurrent->getcourseid()==tempcid)
				{	//print information
						tempval=0;
						break;
				}
				else
				encurrent=encurrent->getnext();
			}
		if(tempval==0)
		{
			//set current to beginning of list
			encurrent=enhead;

			//format
			cout<<"\n\n\n"<<endl;
			cout<<"Student name:\t\tStudent ID:"<<endl;
			cout<<"********************************************"<<endl;
			
			while(encurrent!=NULL)
			{
				//make sure course id and name and student id exist together
				if(encurrent->getcourseid()==tempcid) ///////////////////////
					//print information
					cout<<encurrent->getstudentid()<<endl;

				//traverse
				encurrent=encurrent->getnext();
			}
		}

		//print error message
		else
		{
			cout<<"\n\nNo students have been added to this course."<<endl;
		}
	}
	
	//print error message
	else
	{
		cout<<"\n\nNo students have been added to this course."<<endl;
		return;
	}
*/
}

//void computeaverage()
//{

//}
