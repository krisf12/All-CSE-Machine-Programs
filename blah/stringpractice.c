#include<stdio.h>
#include<string.h>

int main(void)
{
char s1[] = "Hello, world!";
char s2[100];
int l;

strcpy(s2,s1);

printf("s2 = %s\n",s2);

char *s3="this is another string";

printf("s1 compared to s2= %d\n", strcmp(s1,s2));
printf("s1 compared to s3= %d\n", strcmp(s1,s3));
printf("s3 compared to s1= %d\n", strcmp(s3,s1));

char *s4="a";
printf("length of a =%d\n", strlen(s4));

char *s5;
s5=strcat(s2,s1);
printf("s2 concatenated with s1 = %s\n", s2);
printf("s5 = %s\n", s5);


}
