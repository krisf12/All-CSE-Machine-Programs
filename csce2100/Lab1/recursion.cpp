#include<iostream>
#include<cstdlib>
using namespace std;

int main(void)
{
	int num;

	cout<<"Please enter any integer"<<endl;
	cin>>num;

	int count=num;	

	while(count>0)
	num = num*(count-1);

	 cout<<num;


return 0;
}

