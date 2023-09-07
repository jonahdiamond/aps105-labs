//
// Author: Jonah Diamond
//
//#include "reversi.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
void printBoard(char board[][26], int n);
bool positionInBounds(int n, int row, int col);
bool checkLegalInDirection(char board[][26], int n, int row, int col,
char colour, int deltaRow, int deltaCol);
void printFlip(char board[][26], char colour, char opp, int row, int col, int dim);
bool checkLegalMove(char board[][26], int dim, char r, char c, char colour);
bool lookForMoves(char board[][26], int dim, char colour);
void userMove(char board[][26], int dim, char compColour, char userColour);
void compMove(char board[][26], int dim, char compColour, char userColour);
void endGame(char board[][26], int dim, bool validUserMove, char compColour);

void printFlip2(char boardCopy[][26], char colour, char opp, int row, int col);
int nextMove(const char board[][26], int n, int potentialRow, int potentialCol, char turn, char nextTurn);

int main(){
    //initalize board
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
    //ask user for dim
    int dim = 0;
    printf("Enter the board dimension: ");
    scanf(" %d", &dim);
    //ask user which colour computer plays, set colours accordingly
    char compColour, userColour;
    printf("Computer plays (B/W): ");
    scanf(" %c", &compColour);
    userColour = (compColour == 'B') ? 'W' : 'B';
    //print board
    board[dim/2 - 1][dim/2 - 1] = 'W'; /*the game always starts with WBBW in the middle as a square*/
    board[dim/2 - 1][dim/2] = 'B';
    board[dim/2][dim/2 - 1] = 'B';
    board[dim/2][dim/2] = 'W';
    printBoard(board, dim);
    //B goes first, so do B move
        //if compColour = B: comp move function
    if (compColour == 'B'){
        //make compmove
        compMove(board, dim, compColour, userColour);
    }
        //if userColour = B: user move
    if (compColour == 'W'){
        //make usermove    
        userMove(board, dim, compColour, userColour);
    }
    return 0;
}

void userMove(char board[][26], int dim, char compColour, char userColour){
/*user move function needs: userColour, compColour, dim, row, col, board[][26]*/
    //check that there are available moves at all, if not end game
    if (!lookForMoves(board, dim, userColour) && !(lookForMoves(board, dim, compColour))){
      //printBoard(board, dim);
      endGame(board, dim, true, compColour);
    }
    //check there are available moves for user
    if (!lookForMoves(board, dim, userColour)){
      printf("%c player has no valid move.\n", userColour);
      //call comp move
      compMove(board, dim, compColour, userColour);
    }
    //Enter move for colour (userColour)
    printf("Enter move for colour %c (RowCol): ", userColour);
    //scan input
    char r, c;
    scanf(" %c%c", &r, &c);
    //int row = r - 'a', rowCopy = row //store current row; //not necessary
    //col = c - 'a', colCopy = col //store current col; //same
    // if valid move and moves avaliable for comp -> comp's turn
    if (lookForMoves(board, dim, compColour) && checkLegalMove(board, dim, r, c, userColour)){
      //call compmove
      if (lookForMoves(board, dim, compColour)){
        compMove(board, dim, compColour, userColour);
      }
      //if only moves for user, user move again
      if (lookForMoves(board, dim, userColour)){
        printf("%c player has no valid move.\n", compColour);
        userMove(board, dim, compColour, userColour);
      }
      //else, end game
      endGame(board, dim, true, compColour);
    }
    // if no moves for computer but the move is legal
    if (!lookForMoves(board, dim, compColour) && checkLegalMove(board, dim, r, c, userColour)){
      //if move fills the board, end game
      if (!lookForMoves(board, dim, userColour)){
        endGame(board, dim, true, compColour);
      }
      //if valid move but no moves for comp, user turn again
      printf("%c player has no valid move.", compColour);
      printf("\n");
      userMove(board, dim, compColour, userColour);
    }
    
    //if invalid move, end game
    if (!checkLegalMove(board, dim, r, c, userColour)){
      printf("Invalid move.\n");
      //printBoard(board, dim);
      endGame(board, dim, false, compColour);
    }
}

void compMove(char board[][26], const int dim, char compColour, char userColour){
/*comp move function*/
  //needs board, dim, compcolour, user colour
  //check if available moves on board for either colour, if not end game
  if (!lookForMoves(board, dim, userColour) && !(lookForMoves(board, dim, compColour))){
    printBoard(board, dim);
      endGame(board, dim, true, compColour);
    }
  //check there are available moves for comp
  if (!lookForMoves(board, dim, compColour)){
    printf("%c player has no valid move.\n", compColour);
    //call user move
    userMove(board, dim, compColour, userColour);
  }
  int score[dim][dim];
  //set elements in score to 0
  for (int i = 0; i < dim; i++){
    for (int j = 0; j < dim; j++){
      score[i][j] = 0;
    }
  }
  //loop through every row
  for (int i = 0; i < dim; i++){
    //loop through every column
    for (int j = 0; j < dim; j++){
      //loop thru every direction
      for (int deltaRow = -1; deltaRow <=1; deltaRow++){
        for (int deltaCol = -1; deltaCol <=1; deltaCol++){
          if (checkLegalInDirection(board, dim, i, j, compColour, deltaRow, deltaCol)){
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
  int highestScoredMove = 0, rowMove, colMove;
  for (int i = 0; i < dim; i++){
    for (int j = 0; j < dim; j++){
      if (score[i][j] > highestScoredMove){
        highestScoredMove = score[i][j];
        rowMove = i;
        colMove = j;
      }
    }
  }
    if (score[0][0] > 0){
        if (score[0][0] >= score[0][dim-1] && score[0][0] >= score[dim-1][0] && score[0][0] >= score[dim-1][dim-1]){
            rowMove = 0;
            colMove = 0;
        }
    }
    if (score[0][dim-1] > 0){
        if (score[0][dim-1] > score[0][0] && score[0][dim-1] >= score[dim-1][0] && score[0][dim-1] >= score[dim-1][dim-1]){
            rowMove = 0;
            colMove = dim-1;
        }
    }
    if (score[dim-1][0] > 0){
        if (score[dim-1][0] > score[0][dim-1] && score[dim-1][0] > score[0][0] && score[dim-1][0] >= score[dim-1][dim-1]){
            rowMove = dim-1;
            colMove = 0;
        }
    }
    if (score[dim-1][dim-1] > 0){
        if (score[dim-1][dim-1] > score[0][dim-1] && score[dim-1][dim-1] > score[dim-1][0] && score[dim-1][dim-1] > score[0][dim-1]){
            rowMove = dim-1;
            colMove = dim-1;
        }
    }
    

  //add 'a' to each value to be compatible with checkLegalMove function, then call it
  rowMove += 'a';
  colMove += 'a';
  //print computer's move message
  printf("Computer places %c at %c%c.\n", compColour, rowMove, colMove);
  
  //perform move
  checkLegalMove(board, dim, (char) rowMove, (char) colMove, compColour);
  //check if available moves for user
  if (!lookForMoves(board, dim, userColour)){
    //if no moves at all, end game
    if (!lookForMoves(board, dim, compColour)){
      endGame(board, dim, true, compColour);
    }
    //if still moves but only for comp -> comp's turn again
    printf("%c player has no valid move.", userColour);
    printf("\n");
    compMove(board, dim, compColour, userColour);
  }
  //call userMove if moves available for user
  userMove(board, dim, compColour, userColour);
  
/*  // if valid move and moves avaliable for user -> user's turn
  if (checkLegalMove(board, dim, (char) rowMove, (char) colMove, compColour) && lookForMoves(board, dim, userColour)){
    //call usermove
    userMove(board, dim, compColour, userColour);
  }
  // if no moves for user but the move is legal
  if (!lookForMoves(board, dim, userColour) && checkLegalMove(board, dim, (char) rowMove, (char) colMove, compColour)){
    //if move fills the board, end game
    if (!lookForMoves(board, dim, compColour)){
      endGame(board, dim);
    }
    //if valid move but no moves for user, comp turn again
    printf("%c player has no valid move.", userColour);
    printf("\n");
    compMove(board, dim, compColour, userColour);
  }
  
  //if invalid move, end game
  if (!checkLegalMove(board, dim, (char) rowMove, (char) colMove, compColour)){
    printf("Invalid move.\n");
    //printBoard(board, dim);
    endGame(board, dim);
  }
*/
}

void endGame(char board[][26], int dim, bool validUserMove, char compColour){
/*endgame function*/
  //needs: board, dim
  //printBoard(board, dim);
  if (validUserMove){
    int wScore = 0, bScore = 0;
    for (int i = 0; i < dim; i++){
      for (int j = 0; j < dim; j++){
        if (board[i][j] == 'W'){
          wScore++;
        }
        if (board[i][j] == 'B'){
          bScore++;
        }
      }
    }
    if (wScore > bScore){
      printf("W player wins.");
    }
    if (bScore > wScore){
      printf("B player wins.");
    }
    if (bScore == wScore){
      printf("Draw!");
    }
    exit(0);
  }
  printf("%c player wins.", compColour);
  exit(0);
}

void printBoard(char board[][26], int dim) {
  char alphabet[] = {'a','b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
  printf("  "); //ensures the headers are directly over the corresponding columns
  for (int i = 0; i < dim; i++){
    printf("%c", alphabet[i]); //print the headers for the columns (abcd...)
  }
  printf("\n");
  for (int i = 0; i < dim; i++){
    printf("%c ", alphabet[i]); //print the header for the row (abcd...)
    for (int j = 0; j < dim; j++){
      printf("%c", board[i][j]); //print the Unused board
      
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

void printFlip(char board[][26], char colour, char opp, int row, int col/*, int deltaRow, int deltaCol*/, int dim){
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
  printBoard(board, dim); /*print flipped board*/
}

bool checkLegalMove(char board[][26], int dim, char r, char c, char colour) { //still needs updating
  int row = r - 'a' /*convert the row from char to int*/, rowCopy = row /*store current row*/;
  int col = c - 'a', colCopy = col; /*see above*/
  char opp = (colour == 'W') ? 'B' : 'W'; //ternary to set opposite colour
  if (!positionInBounds(dim, row, col) || board[row][col] != 'U'){                            //moved before loop
          return false;
        }
  for (int deltaRow = -1; deltaRow <= 1; deltaRow++){ 
    for (int deltaCol = -1; deltaCol <= 1; deltaCol++){
      if (deltaRow == 0 && deltaCol == 0){ /*check every direction except unmoving*/
        continue;
      } else {
        if (board[row + deltaRow][col+deltaCol] == opp && positionInBounds(dim, row+deltaRow, col+deltaCol)){
          while (board[row + deltaRow][col+deltaCol] == opp){ /*check in full direction for validity*/
            row += deltaRow;
            col += deltaCol;
          }
          if (board[row+deltaRow][col+deltaCol] == colour){ /*valid if check ends in colour*/
            board[rowCopy][colCopy] = colour; /*make checked cell colour*/
            printFlip(board, colour, opp, rowCopy, colCopy, dim); /*flip cells in between  to be colour*/
            return true;
          }
          row = rowCopy;
          col = colCopy;
        }
      }
    }
  }
  return false;
}

bool lookForMoves(char board[][26], int dim, char colour){
  int deltaRow, deltaCol;
  //printf("Available moves for %c:\n", colour);
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
          return true;
        }
      }
    }
  }
  return false;
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

    for (int i = 0; i < n; i++) {
        free(boardCopy[i]);
    }
    free(boardCopy);


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


