#include<stdio.h>
int main(void)
{

int labs;
int quizzes;
int homework;
int exam1;
int exam2;
int final;
int grade;

printf("\n\n\n\n");
printf("enter your final grades\n");

printf("labs: ");
scanf("%d",&labs);

printf("quizzes: ");
scanf("%d",&quizzes);

printf("homework: ");
scanf("%d",&homework);

printf("exam1: ");
scanf("%d",&exam1);

printf("exam2: ");
scanf("%d",&exam2);

printf("final: ");
scanf("%d",&final);


printf("your final grades are:\n");
printf("labs:%d\n",labs);
printf("quizzes:%d\n",quizzes);
printf("homework:%d\n",homework);
printf("exam1:%d\n",exam1);
printf("exam2:%d\n",exam2);
printf("final:%d\n",final);
printf("\n\n");

grade=(labs*.15)+(quizzes*.10)+(homework*.30)+(exam1*.125)+(exam2*.125)+(final*.20);

printf("your overall grade is: %d.",grade);

printf("\n\n");

printf("Hello World!");
return 0;
}

