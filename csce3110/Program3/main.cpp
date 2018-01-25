/*************** 
Name: Kristian Forestier
Course: CSCE 3110
Assignment: Program 3
Due Date: 10/24/15
****************/

#include<cstdlib>
#include<iostream>
#include<string>
//#include"a.cpp"
//#include"b.cpp"   				//  ********* uncomment the one being used and comment out the other two *********  //
#include"c.cpp"

using namespace std;

int main(void)
{
	string user;
	int input;
	BST tree;
	clock_t begin, end;
	float time;

while(user != "quit")	
{
	cout<<endl;                  //the menu for the user to make a selection
	cout<<"MENU:"<<endl<<endl;
	cout<<"add"<<endl;
	cout<<"delete"<<endl;
	cout<<"print"<<endl;
	cout<<"quit"<<endl<<endl;
	cout<<"> ";cin>>user;  //prompt user

	if(user == "add")
	{
		cin>>input;
		tree.addleaf(input);
	}
	else if(user == "delete")
	{
			cin>>input;

		begin = clock();
			tree.removenode(input);
		end = clock();
			cout<<endl;
		time = (float)(end-begin)/CLOCKS_PER_SEC;
		cout<<"execution time: "<<time<<endl;

			tree.print();
	}
	else if(user == "print")
	{
		cout<<"tree in sorted order: ";
		tree.print();
		cout<<endl<<endl;
		cout<<"Enter a parent to look at its children: "; //this is used to show that when the root is deleted the new root is correctly placed and the BST is organized
		cin>>input;
		tree.printchildren(input);
		cout<<endl<<endl;
	}
}
	return 0;
}
