#include <stdio.h>
#include <stdbool.h>

void calculateScore(int[], const int, int[], int[], const int, int*,
                    int*);  // calculate the score of each user
int main(void) {
  const int BoxesNum = 20;
  const int ChoicesNum = 5;
  int boxes[BoxesNum], userOne[ChoicesNum], userTwo[ChoicesNum];
  printf("Enter boxes content: ");
  for (int i = 0; i < BoxesNum; i++) {
    scanf("%d", &boxes[i]);
  }
  printf("Enter player 1 choices: ");
  for (int i = 0; i < ChoicesNum; i++) {
    scanf("%d", &userOne[i]);
  }
  printf("Enter player 2 choices: ");
  for (int i = 0; i < ChoicesNum; i++) {
    scanf("%d", &userTwo[i]);
  }
  int userOneScore = 0, userTwoScore = 0;
  calculateScore(boxes, BoxesNum, userOne, userTwo, ChoicesNum, &userOneScore,
                 &userTwoScore);
  printf("Player 1: %d.\nPlayer 2: %d.\n", userOneScore, userTwoScore);

  return 0;
}

void calculateScore(int boxes[], const int BoxesNum, int userOne[],
                    int userTwo[], const int ChoicesNum, int* score1,
                    int* score2) {
  // Get the score of each user
  int userOneSelection, userTwoSelection;
  for (int i = 0; i < BoxesNum; i++){
    userOneSelection = 0;
    userTwoSelection = 0;
    if (boxes[i] != 0){         //print the nonzero score in box number i
      printf("Found %d in boxes[%d].\n", boxes[i], i);
    for (int j = 0; j < ChoicesNum; j++){
      if (userOne[j] == i){
        userOneSelection += 1;
      }
      if (userTwo[j] == i){
        userTwoSelection += 1;
      }
    }
    if (userOneSelection > 0 && userTwoSelection == 0){
      printf("Found index %d in player 1.\n", i);
      switch (boxes[i]) {
      case -10:
        *score1 += boxes[i];
        printf("-10 from player 1 score.\n");
        break;
      case 10:
        *score1 += boxes[i];
        printf("+10 to player 1 score.\n");
        break;
      }
    } else if (userOneSelection == 0 && userTwoSelection > 0){
      printf("Found index %d in player 2.\n", i);
      switch (boxes[i]) {
      case -10:
        *score2 += boxes[i];
        printf("-10 from player 2 score.\n");
        break;
      case 10:
        *score2 += boxes[i];
        printf("+10 to player 2 score.\n");
        break;
      }
    } else if (userOneSelection && userTwoSelection){
      printf("Found index %d in player 1.\n", i);
      printf("Found index %d in player 2.\n", i);
      switch (boxes[i]) {
      case -10:
        *score1 += boxes[i];
        *score2 += boxes[i];
        printf("-10 from player 1 score.\n");
        printf("-10 from player 2 score.\n");
        break;
      case 10:
        *score1 += (boxes[i])/2;
        *score2 += (boxes[i])/2;
        printf("+5 to players 1 and 2 scores.\n");
        break;
      }
    }
  }
    }  
}

                    
