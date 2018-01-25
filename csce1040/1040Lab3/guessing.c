#include<stdio.h>
#include<stdlib.h>

int main(void)
{
unsigned int number;

srand((unsigned int)time(NULL));

number = random() % (10-1+1)+1;
printf("random number: %d\n", number);
number = random() % (10-1+1)+1;
printf("random number: %d\n", number);
number = random() % (10-1+1)+1;
printf("random number: %d\n", number);

return 0;
}
