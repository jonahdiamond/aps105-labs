#include <stdio.h>
#include "reversi.h"

int main(void) {
  char board[][26] = {
    {'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U'},
    {'U', 'U', 'U', 'U', 'U','U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U'},
    {'U', 'U', 'U', 'U', 'U','U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U'},
    {'U', 'U', 'U', 'U', 'U','U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U'},
    {'U', 'U', 'U', 'U', 'U','U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U'},
    {'U', 'U', 'U', 'U', 'U','U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U'},
    {'U', 'U', 'U', 'U', 'U','U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U'},
    {'U', 'U', 'U', 'U', 'U','U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U'},
    {'U', 'U', 'U', 'U', 'U','U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U'},
    {'U', 'U', 'U', 'U', 'U','U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U'},
    {'U', 'U', 'U', 'U', 'U','U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U'},
    {'U', 'U', 'U', 'U', 'U','U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U'},
    {'U', 'U', 'U', 'U', 'U','U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U'},
    {'U', 'U', 'U', 'U', 'U','U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U'},
    {'U', 'U', 'U', 'U', 'U','U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U'},
    {'U', 'U', 'U', 'U', 'U','U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U'},
    {'U', 'U', 'U', 'U', 'U','U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U'},
    {'U', 'U', 'U', 'U', 'U','U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U'},
    {'U', 'U', 'U', 'U', 'U','U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U'},
    {'U', 'U', 'U', 'U', 'U','U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U'},
    {'U', 'U', 'U', 'U', 'U','U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U'},
    {'U', 'U', 'U', 'U', 'U','U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U'},
    {'U', 'U', 'U', 'U', 'U','U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U'},
    {'U', 'U', 'U', 'U', 'U','U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U'},
    {'U', 'U', 'U', 'U', 'U','U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U'},
    {'U', 'U', 'U', 'U', 'U','U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U', 'U'}
    }; /*unused board which user draws from*/
  int n = 0; /*side length input of board*/
  printf("Enter the board dimension: ");
  scanf(" %d", &n); 
  board[n/2 - 1][n/2 - 1] = 'W';
  board[n/2 - 1][n/2] = 'B';
  board[n/2][n/2 - 1] = 'B';
  board[n/2][n/2] = 'W';
  printBoard(board, n); /*print the board with proper dimensions*/
  char boardConfig0 = 0, boardConfig1 = 0, boardConfig2 = 0; /*variables for board configuration intake*/
  printf("Enter board configuration:\n");
  while (boardConfig0 != '!' && boardConfig1 != '!' && boardConfig2 != '!'){ /*take in board configurations*/
    scanf(" %c%c%c", &boardConfig0, &boardConfig1, &boardConfig2);
    board[boardConfig1 - 'a'][boardConfig2 - 'a'] = boardConfig0;
  }
  printBoard(board, n);
  return 0;
}
