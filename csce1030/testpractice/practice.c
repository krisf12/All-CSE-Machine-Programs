#include<stdio.h>
#include<math.h>

int main(void)
{
	int i = 10;
	int optional, num, value;
	float x, y, a;
	double z, b;

printf("enter an integer:\n");
scanf("%d", &optional);

switch(optional)
{
case 0:
	printf("this is reached only by the number \"0\"\n");

case 1:
	printf("this is reached by the number 0 and 1\n");
break;

case 2:
	printf("this is reached only by the number 2\n");
break;

case 3: 
	printf("this is reached only by 3\n");
break;

default:
	printf("this is reached by all other numbers\n");
break;
}

num = 3;  //ask question as to what this does here. Why does it matter and what it does?//

while(num % 2 != 0)
{
printf("please enter an even number:\n");
scanf("%d", &num);
}
{
printf("thank you\n");
}

{
printf("enter two floats and one double:\n");
scanf("%f %f %lf",&x, &y, &z);

a = ((x+y) / (x-(y*y)));
b = ((z*z)-z);

printf("equation A equals %f", a);
printf("\n");
printf("equation B equals %lf", b);
printf("\n");
}

{
printf("the value of i is %d\n", i);
value= ((i/ 4) +( 5));
i++;
printf("++i equals %d\n", ++i);
printf("i++ equals %d\n", i++);
printf("once again if we do i++ we get %d\n", i++);
printf("now the value of i will become %d\n", i);
}

}
