#include <cstdlib>
#include <iostream>
#include <string>
//#include "Functions.cpp"
#include "Hash.h"

using namespace std;
 
void menu(); void add(int, int, Hash*); void del(int, int, Hash*); void search(int, int, Hash*); void show(Hash*);

int main(void)
{

int num, a, b, c;
string input;
int key;

Hash *h;
h = new Hash[7];

for(a=0; a<7; a++)  //initializing to 0
{
	h[a].count=0;
}
for(b=0;b<7;b++)          //initializing to 0
	for(c=0;c<11; c++)
	{
		h[b].data[c] = 0;
	}

do
{

menu(); //calls function menu
cin>>input; //takes user selection

	if (input=="add")
	{
		cin>>num; //takes the number to add
		key=(num*num)%(7); //creates key
		add(num,key,h);  //calls function add
	}
	else if(input=="delete")
	{
		cin>>num; //takes the number to delete
		del(num, key, h); //calls function delete
	}
	else if(input=="search")
	{	
		cin>>num; //takes number to search
		search(num,key,h); //calls function search
	}
	else if(input=="show")
	{
		show(h); //calls function show
	}
	else if(input=="quit")
	{
		return 0; //quits the program
	}
	else
	{
	cout<<endl;cout<<"INVALID COMMAND"<<endl; //error checking
	menu();
	cin>>input;
	}
}while(input!="quit"); //loop until quit


return 0;
}
