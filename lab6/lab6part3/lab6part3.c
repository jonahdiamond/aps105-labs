#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Part 3: 4 marks
// Using calculateScoreInDir, it checks for each row/col,
// if it sees a line of 1's resulting from that startRow and startCol
// that is equal to difficulty level! Amazing it should return gameOver
bool gameStatus(int Size, char userArray[][Size], int difficultyLevel);

// You need to have implemented to proceed! But on Examify, we will add ours
void printBoard(int Size, char grid[][Size]);
bool validRowCol(int row, int col, int Size);
void updateRowCol(int* row, int* col, int dir, bool forward);
int calculateScoreInDir(int row, int col, int direction, int Size,
                        char userArray[][Size]);

int main(void) {
  const int maxDim = 23;
  int Size = 0, difficultyLevel = 0;
  printf("Enter size and difficulty level: ");
  scanf("%d %d", &Size, &difficultyLevel);

  int copy[maxDim][maxDim] = {
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
    printf("Enter row and col: ");
    scanf("%d %d", &userInputRow, &userInputCol);

    userArray[userInputRow][userInputCol] = grid[userInputRow][userInputCol];
    printBoard(Size, userArray);  
    gameOver = gameStatus(Size, userArray, difficultyLevel);
    steps++;
  } while (!gameOver && steps < Size * Size);
  if (steps == Size * Size) {
    printf("Not a valid game!");
  } else {
    printf("Game over!");
  }

  return 0;
}

bool gameStatus(int Size, char userArray[][Size], int difficultyLevel) {
  // you will need to call calculateScoreInDir
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
  // from part 2
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
  // from part 1
  bool valid = false;
  if (row < Size && row >= 0 && col < Size && col >= 0){
    valid = true;
  }
  return valid;
}
void updateRowCol(int* row, int* col, int dir, bool forward) {
  // update Row and Col in forward/backward direction given direction
  // If direction is 0: row--, 1: row--, col++, 2: col++, 3: row--, col--
  // from part 2
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
  // similar to part 1
  for (int i = 0; i < Size; i++){
    for (int j = 0; j < Size; j++){
      printf("%c", grid[i][j]);
    }
    printf("\n");
  }   
}

