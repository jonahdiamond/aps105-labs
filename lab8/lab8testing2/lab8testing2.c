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

void printFlip2(char boardCopy[][26], char colour, char opp, int row, int col){
  int rowCopy = row, colCopy = col;
  for (int i = -1; i <= 1; i++){
    for (int j = -1; j<=1; j++){
      if (i == 0 && j == 0){
        continue;
      }
      while (boardCopy[row+i][col+j]== opp){
        row+=i;
        col+=j;
      }
      if (boardCopy[row+i][col+j] == colour){
        while (boardCopy[row][col] == opp){
          boardCopy[row][col] = colour;
          row-=i;
          col-=j;
        }
      }
      row = rowCopy;
      col = colCopy;
    }
  }
  //printBoard(board, dim); /*print flipped board*/
}

//needs potential move, board, (to flip moves), colours, highestScoredMove
int nextMove(const char board[][26], int n, int potentialRow, int potentialCol, char turn, char nextTurn){
    /*char boardCopy[n][n];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            boardCopy[i][j] = board[i][j];
        }
    }*/
    // allocate memory for rows
    char **boardCopy = malloc(n * sizeof(char *));

    // allocate memory for columns
    for (int i = 0; i < n; i++) {
    boardCopy[i] = malloc(n * sizeof(char));
    }

    // copy elements to boardCopy
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            boardCopy[i][j] = board[i][j];
        }
    }
    boardCopy[potentialRow][potentialCol] = turn;
    printFlip2(boardCopy, turn, nextTurn, potentialRow, potentialCol);
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
          if (checkLegalInDirection(boardCopy, n, i, j, nextTurn, deltaRow, deltaCol)){
            //add 1 to score of that row
            score[i][j]++;
          }
        }
      }

    } 
  } 
  int highestNextMove = 0;
    for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      if (score[i][j] > highestNextMove){
        highestNextMove = score[i][j];
              }
    }
  }
  //potential move = colour
  //flip necessary tiles
  //int nextscore = 0
  //loop thru every tile to see nextScore
  //return highestScoredMove - nextScore;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            free(boardCopy[i][j]);
        }   
    }


  return highestNextMove;
}


int makeMove(char board[][26], int n, char turn, int *row, int *col){
    char nextTurn = (turn == 'W') ? 'B' : 'W';
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
int highestScoredMove = 0, nextScore = 0;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      //if (score[i][j] > highestScoredMove){
        if (score[i][j] > 0){
        //highestScoredMove = score[i][j];
        nextScore = (nextMove(board[n][n], n, i, j, turn, nextTurn));
        score[i][j] = score[i][j] - nextScore;
              }
    }
  }
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
        if (score[i][j] > highestScoredMove){
            highestScoredMove = score[i][j];
            *row = i;
            *col = j;
        }
    }
  }
  return 0;
}


