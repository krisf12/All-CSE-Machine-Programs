#include<stdio.h>

int main(void)
{

struct car{
	int year;
	char *model;
	char *make;
	};
struct car new_car;
struct car old_car;

struct car parking_lot[10];

new_car.year=2013;
new_car.model="A5";
new_car.make="Audi";

old_car.year=1920;
old_car.model="fiesta";
old_car.make="ford";

parking_lot[0] = new_car;
parking_lot[1] = old_car;

printf("in spot 0: %d %s %s\n", parking_lot[0].year, parking_lot[0].make, parking_lot[0].model);
printf("in spot 1: %d %s %s\n", parking_lot[1].year, parking_lot[1].make, parking_lot[1].model);
}
