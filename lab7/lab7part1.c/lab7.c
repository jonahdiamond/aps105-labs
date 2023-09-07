#include <stdio.h>
#include <stdbool.h>
#include "reversi.h"

/*void printBoard(char board[][26], int n);
bool positionInBounds(int n, int row, int col);
bool checkLegalInDirection(char board[][26], int n, int row, int col,
                           char colour, int deltaRow, int deltaCol);
*/

#include <stdio.h>
#include "reversi.h"

void lookForMoves(char board[][26], int dim, char colour);
bool checkLegalMove(char board[][26], int dim, char r, char c, char colour);
void printFlip(char board[][26], char colour, char opp, int row, int col, int deltaRow, int deltaCol, int dim);


int main(void) {
  char board[][26] = {
    {'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U'},
    {'U', 'U', 'U', 'U', 'U','U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U'},
    {'U', 'U', 'U', 'U', 'U','U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U'},
    {'U', 'U', 'U', 'U', 'U','U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U'},
    {'U', 'U', 'U', 'U', 'U','U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U'},
    {'U', 'U', 'U', 'U', 'U','U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U'},
    {'U', 'U', 'U', 'U', 'U','U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U'},
    {'U', 'U', 'U', 'U', 'U','U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U'},
    {'U', 'U', 'U', 'U', 'U','U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U'},
    {'U', 'U', 'U', 'U', 'U','U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U'},
    {'U', 'U', 'U', 'U', 'U','U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U'},
    {'U', 'U', 'U', 'U', 'U','U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U'},
    {'U', 'U', 'U', 'U', 'U','U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U'},
    {'U', 'U', 'U', 'U', 'U','U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U'},
    {'U', 'U', 'U', 'U', 'U','U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U'},
    {'U', 'U', 'U', 'U', 'U','U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U'},
    {'U', 'U', 'U', 'U', 'U','U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U'},
    {'U', 'U', 'U', 'U', 'U','U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U'},
    {'U', 'U', 'U', 'U', 'U','U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U'},
    {'U', 'U', 'U', 'U', 'U','U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U'},
    {'U', 'U', 'U', 'U', 'U','U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U'},
    {'U', 'U', 'U', 'U', 'U','U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U'},
    {'U', 'U', 'U', 'U', 'U','U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U'},
    {'U', 'U', 'U', 'U', 'U','U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U'},
    {'U', 'U', 'U', 'U', 'U','U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U'},
    {'U', 'U', 'U', 'U', 'U','U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U'}
    }; /*unused board which user draws from*/
  int dim= 0; /*side length input of board*/
  printf("Enter the board dimension: ");
  scanf(" %d", &dim); 
  board[dim/2 - 1][dim/2 - 1] = 'W'; /*the game always starts with WBBW in the middle as a square*/
  board[dim/2 - 1][dim/2] = 'B';
  board[dim/2][dim/2 - 1] = 'B';
  board[dim/2][dim/2] = 'W';
  printBoard(board, dim); /*print the board with proper dimensions*/
  char boardConfig0 = 0, boardConfig1 = 0, boardConfig2 = 0; /*variables for board configuration intake*/
  printf("Enter board configuration:\n");
  while (boardConfig0 != '!' && boardConfig1 != '!' && boardConfig2 != '!'){ /*take in board configurations*/
    scanf(" %c%c%c", &boardConfig0, &boardConfig1, &boardConfig2);
    board[boardConfig1 - 'a'][boardConfig2 - 'a'] = boardConfig0; /*adjust the board to input configurations*/
  }
  printBoard(board, dim);
  lookForMoves(board, dim, 'W');
  lookForMoves(board, dim, 'B');
  char colour;
  char row, col;
  printf("Enter a move:\n");
  scanf(" %c%c%c",&colour, &row, &col);
  checkLegalMove(board, dim, row, col, colour);
  return 0;
}

void printBoard(char board[][26], int dim) {
  char alphabet[] = {'a','b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
  printf("  "); //ensures the headers are directly over the corresponding columns
  for (int i = 0; i < dim; i++){
    printf("%c", alphabet[i]); /*print the headers for the columns (abcd...)*/
  }
  printf("\n");
  for (int i = 0; i < dim; i++){
    printf("%c ", alphabet[i]); /*print the header for the row (abcd...)*/
    for (int j = 0; j < dim; j++){
      printf("%c", board[i][j]); /*print the Unused board*/
      
    }
    printf("\n");
  }
}


bool positionInBounds(int dim, int row, int col) {
  if (row >= dim || col >= dim || row < 0 || col < 0){
    return false; //ie position is out of bounds
  }
  return true; //ie position is in bounds
}
bool checkLegalInDirection(char board[][26], int dim, int row, int col,
                           char colour, int deltaRow, int deltaCol) {
  char opp;
  if (colour == 'W'){
    opp = 'B';
  } else{
    opp = 'W';
  }
  if (board[row][col]!= 'U'){
    return false; /*illegal if current spot is taken*/
  }
  row+=deltaRow; //update row
  col+=deltaCol; //update col
  if (!positionInBounds(dim, row, col) || board[row][col] == 'U' || board[row - deltaRow][col - deltaCol] != 'U' || board[row][col] == colour){
    return false; //move is invalid if position is out of bounds, unused, or if current spot is used
  } 
  if (board[row][col] == opp){
    while (board[row][col] == opp){
      row+= deltaRow;
      col+=deltaCol; /*if a seemingly proper move is found, check the entire direction*/
    }
    if (board[row][col] == colour && positionInBounds(dim, row, col)){
      return true; /*legal if it ends in your colour*/
    }
  }
  return false; /*otherwise illegal*/
                           }

void lookForMoves(char board[][26], int dim, char colour){
  int deltaRow, deltaCol;
  printf("Available moves for %c:\n", colour);
  for (int i = 0; i < dim; i++){ /*check every row*/
    for (int j = 0; j < dim; j++){ /*check every column for every row*/
      for (int dir = 0; dir < 8; dir++){ /*check every direction for each cell*/
        deltaRow = 0;
        deltaCol = 0;
        switch (dir) {
          case 0: //N
            (deltaRow)--;
            break;
          case 1: //NE
            (deltaRow)--;
            (deltaCol)++;
            break;
          case 2: //E
            (deltaCol)++;
            break;
          case 3: //SE
            (deltaRow)++;
            (deltaCol)++;
            break;
          case 4: //S
            (deltaRow)++;
            break;
          case 5: //SW
            (deltaRow)++;
            (deltaCol)--;
            break;
          case 6: //W
            (deltaCol)--;
            break;
          case 7: //NW
            (deltaRow)--;
            (deltaCol)--;
            break;
        }
        //print available positions
        if (checkLegalInDirection(board, dim, i, j, colour, deltaRow, deltaCol)){
          printf("%c%c\n", i + 'a', j + 'a');
          break;
        }
      }
    }
  }
}

bool checkLegalMove(char board[][26], int dim, char r, char c, char colour) {
  int row = r - 'a' /*convert the row from char to int*/, rowCopy = row /*store current row*/;
  int col = c - 'a', colCopy = col; /*see above*/
  char opp = (colour == 'W') ? 'B' : 'W'; //ternary to set opposite colour
  for (int deltaRow = -1; deltaRow <= 1; deltaRow++){ 
    for (int deltaCol = -1; deltaCol <= 1; deltaCol++){
      if (deltaRow == 0 && deltaCol == 0){ /*check every direction except unmoving*/
        continue;
      } else {
        if (!positionInBounds(dim, row, col) || board[row][col] != 'U'){
          printf("Invalid move.\n"); /*invalid if out of bounds or used space*/
          printBoard(board, dim); /*print unflipped*/
          return false;
        }
        if (board[row + deltaRow][col+deltaCol] == opp){
          while (board[row + deltaRow][col+deltaCol] == opp){ /*check in full direction for validity*/
            row += deltaRow;
            col += deltaCol;
          }
          if (board[row+deltaRow][col+deltaCol] == colour){ /*valid if check ends in colour*/
            printf("Valid move.\n");
            board[rowCopy][colCopy] = colour; /*make checked cell colour*/
            printFlip(board, colour, opp, rowCopy, colCopy, deltaRow, deltaCol, dim); /*flip cells in between  to be colour*/
            return true;
          }
        }
      }
    }
  }
  printf("Invalid move.\n");
  printBoard(board, dim); /*print unflipped board*/
  return false;
}

void printFlip(char board[][26], char colour, char opp, int row, int col, int deltaRow, int deltaCol, int dim){
  int rowCopy = row, colCopy = col;
  for (int i = -1; i <= 1; i++){
    for (int j = -1; j<=1; j++){
      if (i == 0 && j == 0){
        continue;
      }
      while (board[row+i][col+j]== opp){
        row+=i;
        col+=j;
      }
      if (board[row+i][col+j] == colour){
        while (board[row][col] == opp){
          board[row][col] = colour;
          row-=i;
          col-=j;
        }
      }
      row = rowCopy;
      col = colCopy;
    }
  }
  /*while (board[row][col] == opp){ /*reverse the direction and flip them all to be colour
    board[row][col] = colour;
    row-=deltaRow;
    col-=deltaCol;
  }*/
  printBoard(board, dim); /*print flipped board*/
}
