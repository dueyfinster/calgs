# include <stdio.h>
# include <stdlib.h>

int findSmallest(int * arrToSort, int currentSmallest){
  int workingSmallest = 10000;
  for(int i=0; i < sizeof(arrToSort); i++){
    if(arrToSort[i] != currentSmallest &&
       arrToSort[i] > currentSmallest && 
       arrToSort[i] < workingSmallest){
      workingSmallest = arrToSort[i];
      printf("Smallest is now: %d\n", workingSmallest);
    }
  }
  return workingSmallest;
}

void printSortedArray(int * sortedArr){
  printf("Sorted Array: ");
  for(int i=0; i < sizeof(sortedArr); i++){
    printf(" %d,", sortedArr[i]);
  }
  printf("\n");
}

void sort(int * arrToSort, int * sortedArr){
  int currentSmallest = 0;
  for(int i=0; i < sizeof(arrToSort); i++){
    currentSmallest = findSmallest((int *) arrToSort, currentSmallest);
    sortedArr[i] = currentSmallest;
  }
  printSortedArray((int *) sortedArr);
}

int main(int code, char** args){
  int arrToSort[10] = {11, 12, 2, 4, 55, 36, 35, 88, 29, 10};
  int *sortedArr = malloc(sizeof(int)*10);
  sort((int *) arrToSort, (int *) sortedArr);
  return 0;
}

