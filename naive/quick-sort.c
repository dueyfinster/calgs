# include <stdio.h>
# include <stdlib.h>


int main(int code, char** args){
  int arrToSort[10] = {12, 23, 16, 2, 5, 31, 21, 10, 8, 4};
  /* int arrToSort[10] = {11, 12, 2, 4, 55, 36, 35, 88, 29, 10}; */
  /* int arrToSort[] = {12, 11, 2, 4, 10}; */
  size_t size = sizeof arrToSort / sizeof *arrToSort;
  /* printSortedArray("Start arr", arrToSort, size); */
  /* sort((int *) arrToSort, size); */
  return 0;
}
