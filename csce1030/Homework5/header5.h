#include<stdio.h>
#define N 100
#define Max_File_Size 500

struct records{            /*this is the records struct*/
	int euid;
	char firname[N];
	char lasname[N];
	float gpa;
};     
struct records recordsize[Max_File_Size];

void gtfile(struct records[]);              /*function prototypes*/
void readLine(FILE*, struct records[]); 
void scan_forinput();

int selection;          /*variables*/
int euidnumber;

void print_all(struct records[], int *);
void print_euid(struct records[], int *, int *);
void print_name(struct records[], int *);   /*function prototypes*/
void print_lowest(struct records[], int *);
void print_highest(struct records[], int *);
void gpa(struct records[], int *);
