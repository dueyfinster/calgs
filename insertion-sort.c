# include <stdio.h>
# include <stdlib.h>


void sort(int * arrToSort, int * sortedArr){
  for(int i=0; i < sizeof(arrToSort); i++){

  }
}

int main(int code, char** args){
  int arrToSort[10] = {11, 12, 2, 4, 55, 36, 35, 88, 29, 10};
  int *sortedArr = malloc(sizeof(int)*10);
  sort((int *) arrToSort, (int *) sortedArr);
  return 0;
}

