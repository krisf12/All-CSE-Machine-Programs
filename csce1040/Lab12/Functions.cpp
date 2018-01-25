#include<iostream>
#include<cstdlib>
#include"class.h"
using namespace std;

Bank::Bank() //this provides access to the accounts
{
	for(int i=0; i<10; i++)
	{
		Account[i]=0;  //initialize all 10 accounts to 0
	}
}


void Bank::deposit(int num, int value)
{
	Account[num]+=value;  //adds the funds to the account selected

}

void Bank::withdraw(int num, int value)
{
	if(Account[num] >= value) //checks if there are sufficient funds
	{
		Account[num]-=value;  //subtracts the ammount from the account selected
	}
	else
	cout<<"ERROR insufficient funds"<<endl;

}

void Bank::balance(int num)
{
	cout<<endl;        //new line
	cout<<Account[num];//prints the account selected
	cout<<endl;
}

void Bank::transfer(int num1, int num2, int value)
{
	if(Account[num1]<value) //checks if there are sufficient funds
	{ 
		cout<< "ERROR insufficient funds"<<endl; //error message
	}

	else
	{
		Account[num1]-=value;  //subtracts ammount from first account
		Account[num2]+=value;  //adds to second account
	}
}
