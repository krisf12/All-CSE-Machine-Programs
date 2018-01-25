//      Kristian Forestier
//      csce 2110
//      Programming Assignment 3
//      This is my functions file, this is where I initialized all of the items within my two classes.
#include <cstdlib>
#include <iostream>
#include <string>
#include "Class.h"

using namespace std;

Students::Students()	//initialize items in Students class
{
	id = 0;
	Name = " ";
	last_name = " ";
	hold = 0;
}
Grades::Grades()	//initialize items in Grades class
{
	id = 0;
	classroom = " ";
	grade = " ";
}
