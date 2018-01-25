#include<iostream>
#include<cstdlib>

using namespace std;

int main(void)
{

int check[3];

while(1)
{
// PROCESS 1
check[1] = true;
while (1){
        if(check[2])
        ;       //do nothing
        else    
        cout<<"done 1"; // critical section;
check[1] = false;
}
// PROCESS 0
check[0] = true; 
while (1){
	if(check[1])
	;	//do nothing
	else
    	cout<<"done 0"; // critical section; 
check[0] = false;
} 

/*
// PROCESS 1
check[1] = true;
while (check[2]){
        if(check[2])
        ;       //do nothing
        else
    	cout<<"done 1"; // critical section;
check[1] = false;
}
*/
// PROCESS 2
check[2] = true;
while (1){
	if(check[0])
        ;       //do nothing
        else
    	cout<<"done 2"; // critical section;
check[2] = false;
}
}

return 0;
}
