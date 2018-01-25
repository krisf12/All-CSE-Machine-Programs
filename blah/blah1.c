#include<stdio.h>

int main(void)
{
   int result = 5, i = 10, total;

while(i<=15)
{
printf("this is %d\n", i);
total = result*i;
i++;
printf("now i equals %d\n", total);
}
return 0;
}
