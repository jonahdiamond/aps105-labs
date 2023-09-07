#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


bool gameStatus(int Size, char userArray[][Size], int difficultyLevel);

void printBoard(int Size, char grid[][Size]);
bool validRowCol(int row, int col, int Size);
void updateRowCol(int* row, int* col, int dir, bool forward);
int calculateScoreInDir(int row, int col, int direction, int Size,
                        char userArray[][Size]);

void getInput(int* row, int* col, int Size);
void getLevelAndDimensions(int* size, int* difficultyLevel, const int maxDim);
int getRand(int maxChoices);

int main(void) {
  const int maxDim = 23;
  int Size = 0, difficultyLevel = 0;

  getLevelAndDimensions(&Size, &difficultyLevel, maxDim);

  int copy[23][23] = {
      {1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1},
      {1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1},
      {0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0},
      {1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1},
      {1, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1},
      {0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0},
      {1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1},
      {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1},
      {1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1},
      {1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1},
      {0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0},
      {1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1},
      {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
      {0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1},
      {1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1},
      {0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1},
      {1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 1, 0, 0, 1},
      {0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0},
      {0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 1},
      {1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0},
      {1, 1, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1},
      {1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1},
      {1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1}};

  char grid[Size][Size];
  for (int row = 0; row < Size; row++) {
    for (int col = 0; col < Size; col++) {
      grid[row][col] = copy[row][col] + '0';
    }
  }
  // TODO: check if there is a valid game, if not, create one
  while (!gameStatus(Size, grid, difficultyLevel)){
    grid[getRand(Size)][getRand(Size)] = '1';
  }

  int userInputRow = 0, userInputCol = 0;

  // test gameStatus
  char userArray[Size][Size];
  for (int row = 0; row < Size; row++) {
    for (int col = 0; col < Size; col++) {
      userArray[row][col] = '-';
    }
  }
  bool gameOver = true;
  int steps = 0;
  do {
    getInput(&userInputRow, &userInputCol, Size);
    userArray[userInputRow][userInputCol] = grid[userInputRow][userInputCol];
    printBoard(Size, userArray);

    gameOver = gameStatus(Size, userArray, difficultyLevel);
    steps++;
  } while (!gameOver && steps < Size * Size);
  if (steps == Size * Size) {
    printf("Not a valid game!");
  } else {
    printf("Game over!\n");
    printf("Your score is %d", Size * Size - steps);
  }

  return 0;
}

bool gameStatus(int Size, char userArray[][Size], int difficultyLevel) {
  for (int i = 0; i < Size; i++){
    for (int j = 0; j < Size; j++){
      for (int direc = 0; direc < 4; direc++){
        if (calculateScoreInDir(i, j, direc, Size, userArray) >= difficultyLevel){
          return true;
        }
      }
    }
  }
  return false;
}

int calculateScoreInDir(int row, int col, int direction, int Size,
                        char userArray[][Size]) {
                          if (userArray[row][col] == '0'){
    return 0;
  }
  int rowCopy = row, colCopy = col;
  int score = 0;
  while (userArray[row][col] == '1' && validRowCol(row, col, Size)){
    score++;
    updateRowCol(&row, &col, direction, true);
  }
  row = rowCopy;
  col = colCopy;
  while (userArray[row][col] == '1' && validRowCol(row, col, Size)){
    score++;
    updateRowCol(&row, &col, direction, false);
  }
  return score - 1;
                        }

bool validRowCol(int row, int col, int Size) {
  bool valid = false;
  if (row < Size && row >= 0 && col < Size && col >= 0){
    valid = true;
  }
  return valid;
}
void updateRowCol(int* row, int* col, int dir, bool forward) {
  if (forward){
    switch (dir) {
      case 0: //up and down column
        (*row)--;
        break;
      case 1: //
        (*row)--;
        (*col)++;
        break;
      case 2:
        (*col)++;
        break;
      case 3:
        (*row)--;
        (*col)--;
        break;
    }
  } else {
    switch (dir) {
      case 0:
        (*row)++;
        break;
      case 1:
        (*row)++;
        (*col)--;
        break;
      case 2:
        (*col)--;
        break;
      case 3:
        (*row)++;
        (*col)++;
        break;
    }
  }
}

void printBoard(int Size, char grid[][Size]) {
    for (int i = 0; i < Size; i++){
    for (int j = 0; j < Size; j++){
      printf("%c", grid[i][j]);
    }
    printf("\n");
  }   
}

void getInput(int* row, int* col, int Size) {
  printf("Enter user input: ");
  scanf(" %d %d", row, col);
  while (!validRowCol(*row, *col, Size)){
    printf("Please enter your row and col to be between 0 and Size - 1: ");
    scanf(" %d %d", row, col);
  }
}

void getLevelAndDimensions(int* Size, int* levelOfDiff, const int maxDim) {
  printf("Enter the difficulty level: ");
  scanf(" %d", levelOfDiff);
  if (*levelOfDiff <= 0 || *levelOfDiff > maxDim){
    while (*levelOfDiff <= 0 || *levelOfDiff > maxDim){
      printf("Please enter a difficulty level between 1 and %d: ", maxDim);
      scanf(" %d", levelOfDiff);
    }
  }
  printf("Enter the dimensions of the grid: ");
  scanf(" %d", Size);
  if (*levelOfDiff > *Size || *Size > maxDim){
    while (*levelOfDiff > *Size || *Size > maxDim){
      printf("Please enter dimensions >= %d: ", *levelOfDiff);
      scanf(" %d", Size);
    }
  }
}

int getRand(int maxChoices) { return (rand() % (maxChoices)); }
