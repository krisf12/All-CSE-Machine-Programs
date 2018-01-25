#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i=0;

	int a=42;  //an integer (a is actually an address to the machine)
	int *p1=NULL; //a pointer to the address of an integer
	char *p2=NULL; //a pointer to the address of a character
	int p3[10]; //a pointer to the first address of array size 10
	int *p4=NULL; //a pointer to the first elemtent of an array
	int N;
	int *p5[10]; //array of pointers to integers

	for(i=0;i<10;i++)
	p5[i]=NULL;

	printf("enter the number of items: ");
	scanf("%d", &N);
	p4 =(int *)malloc(N * sizeof(unsigned int));
	printf("p4->%p\n", p4);
		
	for(i=0; i<N;i++)
		p4[i]= i * N;
	for(i=0; i<N;i++)
		printf("%d", p4[i]);
		printf("\n\n\n\n");

	p1=&a;
	printf("a=%d, address of a is %p\n", a, &a);
	printf("p1=&a; results in p1->%p\n", p1);

	printf("addresses : p1 is %p, p2 is %p, p3 is %p\n", &p1, &p2, &p3);
	printf("pointing to : p1->%p, p2->%p, p3->%p\n\n", p1, p2, p3);

	for(i=0; i<10; i++)
		p3[i]=i;

	for(i=0; i<10; i++)
		printf("%p->%d\n", p3+i, *(p3+i));
		printf("\n");

//	for(i=0; i<10;i++)
//		printf("i=%d p5[i]=%p\n\n", i, p5[i]);

	p5[0]=(int*) malloc(sizeof(unsigned int));
	
	for(i=0;i<10;i++)
		p5[i]=(int*) malloc(sizeof(unsigned int));

	for(i=0;i<10;i++)
		*p5[i]=i;

	for(i=0; i<10;i++)
		printf("i=%d p5[i]=%p\n\n", i, p5[i], *p5[i]);

	return 0;
}
