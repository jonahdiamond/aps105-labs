#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool validateChoices(int choices[], const int ChoicesNum, const int BoxesNum);
void takeUserChoices(int userOne[], int userTwo[], const int ChoicesNum,
                     const int BoxesNum);
void populateBoxes(int boxes[], const int BoxesNum);

int main(void) {
  const int BoxesNum = 20;
  const int ChoicesNum = 5;

  int boxes[BoxesNum], userOne[ChoicesNum], userTwo[ChoicesNum];
  populateBoxes(boxes, BoxesNum);
  takeUserChoices(userOne, userTwo, ChoicesNum, BoxesNum);
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
    if (choices[i] == choices[i + 1]){
      valid = false;
    } else if ((choices[i] > (BoxesNum - 1)) || (choices[i] < 0)){
      valid = false;
    }
  }
  // Check if elements in choices is distinct
  return valid;
}
