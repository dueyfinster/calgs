# include <stdio.h>
# include <stdlib.h>

void printSortedArray(char* name, int * sortedArr, size_t size){
  printf(" %s: [", name);
  for(int i=0; i < size; i++){
    if(i+1!=size){
      printf("%d=%d,", i,sortedArr[i]);
    }else{
      printf("%d=%d", i,sortedArr[i]);
    }
  }
  printf("]\n");
}

void setNewArrValues(int* oldArr, size_t size, int* newArr){
    for(int i=0; i<size; i++){
      oldArr[i] = newArr[i]; // fill with same 
    }
}

void splitArr(int* arrToSplit, size_t size, int newIndex, int value, int oldIndex){
  // Malloc new array
  int* newArr = malloc(4 * sizeof(int));
  // Fill array to split
  if(newIndex == 0){
    newArr[newIndex] = value; // fill with same 
    /* printf("F[%d]=%d", newIndex, value); */
  }else{
    for(int i=0; i<newIndex; i++){
      newArr[i] = arrToSplit[i]; // fill with same 
      /* printf("F[%d]=%d", i, arrToSplit[i]); */
    }
    // Fill split
    /* printf("F[%d]=%d", newIndex, value); */
    newArr[newIndex] = value;
  }

  newIndex++; // need to fill from now on
  int oldPos = newIndex-1;

  // Fill array after split
  for(int i=newIndex; i<size; i++){
     if(oldPos == oldIndex){
       oldPos++;
       /* printf("skip"); */
       /* printf("ASF[%d]=%d,", i, arrToSplit[oldPos]); */
       newArr[i] = arrToSplit[oldPos];
       oldPos++;
     }else{
       /* printf("AF[%d]=%d,", i, arrToSplit[oldPos]); */
       newArr[i] = arrToSplit[oldPos];
       oldPos++;
     }
  }
  /* printSortedArray("After sorting", newArr, size); */
  // set new array
  setNewArrValues(arrToSplit, size, newArr);
}

void sort(int * arrToSort, size_t size){
  // Sort the first two
  if(arrToSort[0] > arrToSort[1]){
    /* printf("%d>%d so swapping them.", arrToSort[0], arrToSort[1]); */
    int t1 = arrToSort[0];
    int t2 = arrToSort[1];
    arrToSort[0] = t2;
    arrToSort[1] = t1;
    /* printf("Now [%d]=%d & [%d]=%d.", 0, t2, 1, t1); */
  }

  // Sort the rest
  for(int i=2; i<size; i++){
    int moveRequired = 0;
    int newPos = i;
    /* printSortedArray("Again", arrToSort, size); */
    /* printf("\n"); */
    for(int x=i-1; x>=0; x--){
      /* printf("Check %d v %d:", arrToSort[i], arrToSort[x]); */
      if(arrToSort[i]<arrToSort[x]){
        /* printf(" New: [%d]=%d,", x, arrToSort[i]); */
        moveRequired = 1;
        newPos = x;
      }else{
        /* printf(" Same:[%d]=%d,", newPos, arrToSort[i]); */
        break;
      }
    }

    if(moveRequired>0){
      /* printf("Resort."); */
      /* printSortedArray("Before Resort", arrToSort, size); */
      splitArr(arrToSort, size, newPos, arrToSort[i], i);
      /* printSortedArray("After Resort", arrToSort, size); */
    }
  }
  printSortedArray("Final", arrToSort, size);
}

int main(int code, char** args){
  int arrToSort[10] = {12, 23, 16, 2, 5, 31, 21, 10, 8, 4};
  /* int arrToSort[10] = {11, 12, 2, 4, 55, 36, 35, 88, 29, 10}; */
  /* int arrToSort[] = {12, 11, 2, 4, 10}; */
  size_t size = sizeof arrToSort / sizeof *arrToSort;
  printSortedArray("Start arr", arrToSort, size);
  sort((int *) arrToSort, size);
  return 0;
}

