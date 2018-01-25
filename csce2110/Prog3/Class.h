//      Kristian Forestier
//      csce 2110
//      Programming Assignment 3
//      This is my class file, this is where I created two classes and linked them with the student ID by using for loops and if statements in main.

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;


class Students{

	public:
		int id;
		int hold;
		string Name;
		string last_name;
		Students();
};



class Grades{
	
	public:
		int id;
		string classroom;
		string grade;
		Grades();
};
