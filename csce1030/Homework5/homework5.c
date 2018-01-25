#include"header5.h"

int main(void)   /*main calls some or all functions as desired*/
{
printf("\nCSCE1030\nHomework4\nKristian Forestier\nkf0106\nkristianforestier@my.unt.edu\n\n");

gtfile(recordsize);
scan_forinput();
print_all(recordsize, &selection);
print_euid(recordsize, &selection, &euidnumber);
print_name(recordsize, &selection);
print_lowest(recordsize, &selection);
print_highest(recordsize, &selection);
gpa(recordsize, &selection);

return 0;
}
