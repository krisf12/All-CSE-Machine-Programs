/* Kristian Forestier
// Shannon Hart
// CSE 1040.001
// Lab 1040.307
// Lab 2
*/

#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	char command[2], action[2];
	char employees[50][16], customers[50][16];
	float balance[50], ammount;
	int employeeid, customerid;
	char name;
	
	while(scanf("%s", command) != EOF)
	{
		if(command[0] == 'e')
		{
			scanf("%d", &employeeid);
			scanf("%s", employees[employeeid-1]);
		}
		else if(command[0] == 'c')
		{
			scanf("%d", &customerid);
			scanf("%s", customers[customerid-1]);
			scanf("%g", &balance[customerid-1]);
		}
		else if(command[0] == 't')
		{
			scanf("%d", &customerid, &employeeid);
			scanf("%s", action);
			scanf("%g", &ammount);
		
			if(action[0]== 'w')
			{
				balance[customerid-1] = balance[customerid-1]-ammount;
			}
			else if(action[0]== 'd')
			{
				balance[customerid-1] = balance[customerid-1]+ammount;
			}

		printf("%11s %11s %8.2f %8.2f", customers[customerid-1], employees[employeeid-1], ammount, balance);

		}		
	}

	return 0;
}
