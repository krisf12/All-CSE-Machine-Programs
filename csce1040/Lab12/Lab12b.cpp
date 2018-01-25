//Kristian Forestier
// 4/25/14
// Lab12
//

#include<iostream>
#include<cstdlib>
#include<string>
#include"class.h"

using namespace std;


int main(void)
{

string selection; //this allows the user to input a selection
Bank bank;

int num, num1, num2, value; //variable declarations

while(1)  //this is so that it loops until the user wants to quit
{

	cout<<"bank> ";
	cin>>selection;   //takes in the user selection

	if(selection=="deposit")  
	{
		cout<<"DEPOSIT SELECTED"<<endl;
		cin>>num;       
		cin>>value;
		bank.deposit(num,value);  //calls the function deposit
	}
	else if(selection=="withdraw")
	{
		cout<<"WITHDRAW SELECTED"<<endl;
		cin>>num;
		cin>>value;
		bank.withdraw(num, value); //calls the function withdraw
	}
	else if(selection=="balance")
	{
		cout<<"BALANCE SELECTED"<<endl;
		cin>>num;
		bank.balance(num);  //calls the function balance
	}
	else if(selection=="transfer")
	{
		cout<<"TRANSFER SELECTED"<<endl;
		cin>>num1;
		cin>>num2;
		cin>>value;
		bank.transfer(num1,num2,value); //calls the function transfer
	}
	
	else if(selection=="quit")
		return 0;  //quits the program
}


}
