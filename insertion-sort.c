# include <stdio.h>
# include <stdlib.h>

void printSortedArray(char* name, int * sortedArr){
  printf(" %s: [", name);
  for(int i=0; i < 4; i++){
    printf("%d=%d,", i,sortedArr[i]);
  }
  printf("]\n");
}

void setNewArrValues(int* oldArr, int* newArr){
    for(int i=0; i<4; i++){
      oldArr[i] = newArr[i]; // fill with same 
    }
}

void splitArr(int* arrToSplit, int newIndex, int value, int oldIndex){
  // Malloc new array
  int* newArr = malloc(4 * sizeof(int));
  // Fill array to split
  if(newIndex == 0){
    newArr[newIndex] = value; // fill with same 
    printf("F[%d]=%d", newIndex, value);
  }else{
    for(int i=0; i<newIndex; i++){
      newArr[i] = arrToSplit[i]; // fill with same 
      printf("F[%d]=%d", i, arrToSplit[i]);
    }
    // Fill split
    printf("F[%d]=%d", newIndex, value);
    newArr[newIndex] = value;
  }

  // Fill array after split
  for(int i=newIndex+1; i<4; i++){
    if(i-1 != oldIndex){
      printf("F[%d]=%d", i, arrToSplit[i-1]);
      newArr[i] = arrToSplit[i-1];
    }else{
      newArr[i] = arrToSplit[i];
      printf("F[%d]=%d", i, arrToSplit[i]);
    }
  }
  printSortedArray("After sorting", newArr);
  // set new array
  setNewArrValues(arrToSplit, newArr);
}

void sort(int * arrToSort){
  // Sort the first two
  if(arrToSort[0] > arrToSort[1]){
    printf("%d>%d so swapping them.", arrToSort[0], arrToSort[1]);
    int t1 = arrToSort[0];
    int t2 = arrToSort[1];
    arrToSort[0] = t2;
    arrToSort[1] = t1;
    printf("Now [%d]=%d & [%d]=%d.", 0, t2, 1, t1);
  }

  // Sort the rest
  for(int i=2; i <4; i++){
    int moveRequired = 0;
    int newPos = i;
    printSortedArray("Again", arrToSort);
    printf("\n");
    for(int x=i-1; x>=0; x--){
      printf("Check %d v %d:", arrToSort[i], arrToSort[x]);
      if(arrToSort[i]<arrToSort[x]){
        printf("New position for %d is: %d,", arrToSort[i], x);
        moveRequired = 1;
        newPos = x;
      }else{
        printf(" Same pos:[%d]=%d,", newPos, arrToSort[i]);
        break;
      }
    }

    if(moveRequired>0){
      printf("Resort.");
      printSortedArray("Before Resort", arrToSort);
      splitArr(arrToSort, newPos, arrToSort[i], i);
      printSortedArray("After Resort", arrToSort);
    }
  }
  printSortedArray("Final", arrToSort);
}

int main(int code, char** args){
  /* int arrToSort[10] = {11, 12, 2, 4, 55, 36, 35, 88, 29, 10}; */
  int arrToSort[4] = {12, 11, 2, 4};
  printSortedArray("Start arr", arrToSort);
  sort((int *) arrToSort);
  return 0;
}

