#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void updateRowCol(int* row, int* col, int dir, bool forward);
int calculateScoreInDir(int row, int col, int direction, int Size,
                        char userArray[][Size]);
bool validRowCol(int row, int col, int Size);

int main(void) {
  const int maxDim = 23;
  int Size = 0;
  printf("Enter size: ");
  scanf("%d", &Size);

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

  // call calculateScoreInDir here to check if it works as expected!
  for (int row = 0; row < Size; row++) {
    for (int col = 0; col < Size; col++) {
      printf("Row: %d, Col: %d, in direction\n", row, col);
      printf(" 0 ");
      printf("Score: %d.\n", calculateScoreInDir(row, col, 0, Size, grid));
      printf(" 1 ");
      printf("Score: %d.\n", calculateScoreInDir(row, col, 1, Size, grid));
      printf(" 2 ");
      printf("Score: %d.\n", calculateScoreInDir(row, col, 2, Size, grid));
      printf(" 3 ");
      printf("Score: %d.\n", calculateScoreInDir(row, col, 3, Size, grid));
    }
  }

  return 0;
}

int calculateScoreInDir(int row, int col, int direction, int Size,
                        char userArray[][Size]) {
  // Check in the forward direction how many 1s are there,
  // plus how many 1s are there in the backward direction
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

void updateRowCol(int* row, int* col, int dir, bool forward) {
  // update Row and Col in forward/backward direction given direction
  // If direction is 0: row--, 1: row-- and col++, 2: col++, 3: row-- and col--
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

bool validRowCol(int row, int col, int Size) {
  // from part 1
  bool valid = false;
  if (row < Size && row >= 0 && col < Size && col >= 0){
    valid = true;
  }
  return valid;
}
