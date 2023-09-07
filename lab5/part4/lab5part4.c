#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void populateBoxes(int[], int);
void takeUserChoices(int[], int[], const int, const int);
bool validateChoices(int[], const int, const int);
void calculateScore(int[], const int, int[], int[], const int, int*,
                    int*);  // calculate the score of each user
void appendStatistics(int[], const int, int[]);
int frequentBox(int[], const int);

int main(void) {
  // don't set srand!
  const int BoxesNum = 20;
  const int ChoicesNum = 5;
  int boxes[BoxesNum], userOne[ChoicesNum], userTwo[ChoicesNum],
      histogramUserOne[BoxesNum], histogramUserTwo[BoxesNum];

  int userOneScore = 0, userTwoScore = 0;
  while (50 > userOneScore - userTwoScore && 50 > userTwoScore - userOneScore) {
    for (int i = 0; i < BoxesNum; i++) {
      histogramUserOne[i] = 0;
      histogramUserTwo[i] = 0;
    }

    populateBoxes(boxes, BoxesNum);

    takeUserChoices(userOne, userTwo, ChoicesNum, BoxesNum);

    calculateScore(boxes, BoxesNum, userOne, userTwo, ChoicesNum, &userOneScore,
                   &userTwoScore);

    // Append Statistics for User One
    appendStatistics(userOne, ChoicesNum, histogramUserOne);
    // Append Statistics for User Two

    appendStatistics(userTwo, ChoicesNum, histogramUserTwo);

    printf("Player 1: %d.\nPlayer 2: %d.\n", userOneScore, userTwoScore);
  }
  if (userOneScore > userTwoScore) {
    printf("User 1 wins, ");
    printf("and the first box they chose most frequently is: %d\n",
           frequentBox(histogramUserOne, BoxesNum));
  } else {
    printf("User 2 wins, ");
    printf("and the first box they chose most frequently is: %d\n",
           frequentBox(histogramUserTwo, BoxesNum));
  }

  return 0;
}

void takeUserChoices(int userOne[], int userTwo[], const int ChoicesNum,
                     const int BoxesNum) {
  // Can check if the inputs are distinct and if they are between 1 and BoxesNum
  // - 1
  do {
    printf("Player 1, please enter distinct box choices between 0 and 19: ");
    for (int choiceInd = 0; choiceInd < ChoicesNum; choiceInd++) {
      scanf("%d", &userOne[choiceInd]);
    }
  } while (!validateChoices(userOne, ChoicesNum, BoxesNum));

  do {
    printf("Player 2, please enter distinct box choices between 0 and 19: ");
    for (int choiceInd = 0; choiceInd < ChoicesNum; choiceInd++) {
      scanf("%d", &userTwo[choiceInd]);
    }
  } while (!validateChoices(userTwo, ChoicesNum, BoxesNum));
}

void populateBoxes(int boxes[], const int BoxesNum) {
  // TODO: Fill each element randomly by either
  // 0 empty
  // -10 bomb
  // 10 candy
  for (int i = 0; i < BoxesNum; i++) {
    int scoreOption = rand();
    boxes[i] = ((scoreOption % 3) - 1) * 10;
    printf("%d: %d, ", i, boxes[i]);
  }
  printf("\n");
  // Print the contents of the boxes
}

bool validateChoices(int choices[], const int ChoicesNum, const int BoxesNum) {
  bool valid = true;
  // TODO:
  // Check if elements in choices is between 0 and BoxesNum - 1
  for (int i = 0; (i < ChoicesNum); i++) {
    if (choices[i] == choices[i + 1]) {
      valid = false;
    } else if ((choices[i] > (BoxesNum - 1)) || (choices[i] < 0)) {
      valid = false;
    }
  }
  // Check if elements in choices is distinct
  return valid;
}

void appendStatistics(int userChoice[], const int ChoicesNum, int histogram[]) {
  // Fill in the histogram with the number of times each index was picked
  // Print the histogram
  for (int i = 0; i < ChoicesNum; i++) {
    histogram[userChoice[i]]++;
  }
}

int frequentBox(int histogram[], const int BoxesNum) {
  // Return the index having the maximum number in histogram
  int highest = 0, mostFreqNum = 0, i = 0;
  for (i = 0; i < BoxesNum; i++) {
    if (histogram[i] > highest) {
      highest = histogram[i];
      mostFreqNum = i;
    }
  }
  return mostFreqNum;
}

void calculateScore(int boxes[], const int BoxesNum, int userOne[],
                    int userTwo[], const int ChoicesNum, int* score1,
                    int* score2) {
  // Get the score of each user
  int userOneSelection, userTwoSelection;
  for (int i = 0; i < BoxesNum; i++) {
    userOneSelection = 0;
    userTwoSelection = 0;
    if (boxes[i] != 0) {  // print the nonzero score in box number i
      printf("Found %d in boxes[%d].\n", boxes[i], i);
      for (int j = 0; j < ChoicesNum; j++) {
        if (userOne[j] == i) {
          userOneSelection += 1;
        }
        if (userTwo[j] == i) {
          userTwoSelection += 1;
        }
      }
      if (userOneSelection > 0 && userTwoSelection == 0) {
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
      } else if (userOneSelection == 0 && userTwoSelection > 0) {
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
      } else if (userOneSelection && userTwoSelection) {
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
            *score1 += (boxes[i]) / 2;
            *score2 += (boxes[i]) / 2;
            printf("+5 to players 1 and 2 scores.\n");
            break;
        }
      }
    }
  }
}
