# include <stdio.h>
# include <stdlib.h>
# include <time.h>

void makeGuess(int target){
  printf("Enter a guess:\n");
  int guess;
  scanf("%d", &guess);
  checkGuess(target, guess);
}

int checkGuess(int target, int guess){
  if(guess > target){
    printf("You guessed too high!\n");
    makeGuess(target);
  } else if(guess < target){
    printf("You guessed too low!\n");
    makeGuess(target);
  } else {
    printf("You are correct!\n");
    exit(0);
  }
}

int main(int code, char** args){
  int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  srand(time(NULL));
  int target = arr[rand() % 10];
  makeGuess(target);
  return 0;
}

