#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

int makeMove(char board[][26], int n, char turn, int *row, int *col){
    int score[n][n];
  //set elements in score to 0
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      score[i][j] = 0;
    }
  }
  //loop through every row
  for (int i = 0; i < n; i++){
    //loop through every column
    for (int j = 0; j < n; j++){
      //loop thru every direction
      for (int deltaRow = -1; deltaRow <=1; deltaRow++){
        for (int deltaCol = -1; deltaCol <=1; deltaCol++){
          if (checkLegalInDirection(board, n, i, j, turn, deltaRow, deltaCol)){
            //add 1 to score of that row
            score[i][j]++;
          }
        }
      }

    } 
  } 
  /*for (int i = 0; i < dim; i++){
    for (int j = 0; j < dim; j++){
      printf("%c", score[i][j]);
    }
    printf("\n");
  }*/
  //loop thru score and get highest, while storing row and col of highest
  int highestScoredMove = 0;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      if (score[i][j] > highestScoredMove){
        highestScoredMove = score[i][j];
        *row = i;
        *col = j;
      }
    }
  }

   if (score[0][0] > 0){
        if (score[0][0] >= score[0][n-1] && score[0][0] >= score[n-1][0] && score[0][0] >= score[n-1][n-1]){
            *row = 0;
            *col = 0;
        }
    }
    if (score[0][n-1] > 0){
        if (score[0][n-1] > score[0][0] && score[0][n-1] >= score[n-1][0] && score[0][n-1] >= score[n-1][n-1]){
            *row = 0;
            *col = n-1;
        }
    }
    if (score[n-1][0] > 0){
        if (score[n-1][0] > score[0][n-1] && score[n-1][0] > score[0][0] && score[n-1][0] >= score[n-1][n-1]){
            *row = n-1;
            *col = 0;
        }
    }
    if (score[n-1][n-1] > 0){
        if (score[n-1][n-1] > score[0][n-1] && score[n-1][n-1] > score[n-1][0] && score[n-1][n-1] > score[0][n-1]){
            *row = n-1;
            *col = n-1;
        }
    }
    
    return 0;
}
