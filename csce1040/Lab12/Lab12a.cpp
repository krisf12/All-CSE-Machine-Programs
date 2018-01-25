// Kristian Forestier
// 4/25/14
// Lab 12
//

#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;


int main(void)
{

string selection; //creates a string for the user selection

cout<<"bank> ";  //prompts the user
cin>>selection;

if(selection=="deposit")      //checks for selection
cout<<"DEPOSIT SELECTED"<<endl; //prints user selection
else if(selection=="withdraw")
cout<<"WITHDRAW SELECTED"<<endl;
else if(selection=="balance")
cout<<"BALANCE SELECTED"<<endl;
else if(selection=="quit")
return 0;

}
