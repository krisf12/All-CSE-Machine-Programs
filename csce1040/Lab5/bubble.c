#include <stdlib.h>
#include "student.h"

void bubble(students *array[], int size)
{
  int x;
  int y;
  students *temp = NULL;

  for(x = 0; x < size; x++) {
    for(y = 0; y < size-1; y++) {
      if(array[y]->mean > array[y+1]->mean) {
        temp = array[y+1];
        array[y+1] = array[y];
        array[y] = temp;
      }
    }
  }

  return;
}
