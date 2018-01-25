#include <stdio.h>

int main(void)

{
int time;

	printf("Enter the time of day in millitary time: ");
	scanf("%d",&time);

	if((time >= 1)&&(time<=1200))
	printf("Good Morning\n");

	else if((time >= 1201)&&(time<=1700))
	printf("Good Afternoon\n");

	else printf("Good Evening\n");

	return 0;
}
