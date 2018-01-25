/* ********************
Kristian Forestier
CSE 1040.001
Lab 1040.307
Lab 2
01/31/14
******************** */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char cities[11][11];
	char command[2];
	int city1, city2;
	float distance;

	while(scanf("%s", command) != EOF)
	{
		if(command[0]== 'c') {
			scanf("%d", &city1);
			scanf("%s", cities[city1-1]);
			//printf("%11s\t%11s\t%f\n",cities[city1-1], cities[city2-1], distance);
		}
		else if(command[0] == 'a')
		{ 
		scanf("%d %d %f", &city1, &city2, &distance);
		printf("%11s\t%11s\t%8.3f\n",cities[city1-1], cities[city2-1], distance);
		printf("\n");
		}
	}

	return 0;
}
