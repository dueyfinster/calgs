# include <stdio.h>
# include <stdlib.h>

void printSortedArray(int * sortedArr){
  printf("Sorted Array: ");
  for(int i=0; i < sizeof(sortedArr); i++){
    printf(" %d,", sortedArr[i]);
  }
  printf("\n");
}

void sort(int * arrToSort, int * sortedArr){
  if(arrToSort[0] > arrToSort[1]){
    int t1 = arrToSort[0];
    int t2 = arrToSort[1];
    arrToSort[0] = t2;
    arrToSort[1] = t1;
  }
  for(int i=2; i <= sizeof(arrToSort); i++){
    int varToCheck = arrToSort[i];
    int newPos = 0;
    int found = 0;
    int x=i-1;
    do {
      printf("\nChecking %d vs %d\n", varToCheck, arrToSort[x]);
      if(varToCheck > arrToSort[x]){
        newPos = i; // do nothing
        found = 1;
      } else if(varToCheck < arrToSort[x]){
        if(x>=1 && varToCheck > arrToSort[x-1]){
          newPos = x;
          found = 1;
        } else {
          newPos = x;
        }
      }
      x--;
    }while(x>=0 && found != 1);
    printf("\n%d should have position %d\n", varToCheck, newPos);
  }
  printSortedArray(arrToSort);
}

int main(int code, char** args){
  int arrToSort[10] = {11, 12, 2, 4, 55, 36, 35, 88, 29, 10};
  int *sortedArr = malloc(sizeof(int)*10);
  printSortedArray(arrToSort);
  sort((int *) arrToSort, (int *) sortedArr);
  return 0;
}

