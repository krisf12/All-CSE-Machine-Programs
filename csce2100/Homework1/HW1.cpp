//Kristian Forestier
//csce2100.002
//9/26/14
// this program takes two numbers and adds or multipys them depending on the user's selection.
// IMPROVEMENTS: this program also asks the user if they would like to quit or continue.

#include<cstdlib>
#include<iostream>

using namespace std;

double add(double, double);      
double multiply(double, double);  //function prototypes
int error();

int main(void)
{

	double *d;
	double *e;
	d = new double; //allocating memory
	e = new double;

	//*d = 45.3; //from simple original program

	char select;  //for user input
	char select2;
	
	while(select2 != 'q') //while loop to repeat program
	{
		cout<<"Type a number:"<<endl;          //user enters first number
		cin>> *d;			//number stored in *d;
		cout<<"Type another number:"<<endl;     //user enters second number
		cin>> *e;			//number stored in *e;
		
		cout<<"Press A to add or press M to multiply:"<<endl; //prompt
		cin>> select; //stores selection in integer
		
		//*d = *d + 5; //from simple original program

		if(select == 'A')    //if statement to check for addition option
		{
			*d = add(*d,*e); //call addition function
		}
		else if(select == 'M') //if statement to check for multiplication option
		{
			*d = multiply(*d,*e);  //call multiplication function
		}
		else if(select != 'A' && select != 'M') //error checking
		{
			error(); return 0;   //call error function and quit program
		}
		cout<<"result: " << *d <<endl<<endl; //prints the result of the algebra

		delete d;  //freeing memory
		delete e;

		cout<<"Type q to quit or press any key to continue:"<<endl;  //checks for the while loop to stop
		cin>> select2;
		cout<<endl<<endl;
	}

	cout<<"Bye!"<<endl<<endl;

	return 0;
}

double add(double d, double e)
{
	return d + e; //returns the addition
}

double multiply(double d, double e)
{
	return (d)*(e); //returns the multiplication
}

int error()
{
	cout<<"ERROR Invalid Selection"<<endl; //prints error on screen
}

