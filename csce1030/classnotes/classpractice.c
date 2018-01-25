#include<stdio.h>

int bool(int x, int y);

int main(void)
{
int i,j;
scanf("%d%d",&i,&j);
printf("i=%d, j=%d, result=%d\n", i, j, bool(i,j));
return 0;
}

int bool(int i, int j)
{
if(i>j) return 1;
/*else*/ return 0;
}

