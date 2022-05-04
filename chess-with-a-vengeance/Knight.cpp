/**
 * @file Knight.cpp
 * @author Kyle Byassee
 * @date 2022-03-30
 * @brief The Knight class methods are defined here.
 * 
 * Methods are Knight constructor, readFile, validMoves, and printBoard.
 */

#include <iostream>
#include <string>
#include <fstream>
#include "Knight.h"

using namespace std;

Knight::Knight() {
  board_size = 0;
  row = 0;
  column = 0;

  for(int i = 0; i < BIG_CHESS; i++) {  // 0 thru 7 in standard chess
    for(int j = 0; j < BIG_CHESS; j++) {
      board[i][j] = ' ';
      // The following block is for creating the alternating black and white squares on typical chess boards
      /*
      if(i % 2 == 0 && j % 2 == 0) {  //        even rows with even columns
        board[i][j] = '#';
      } else if(i % 2 != 0 && j % 2 != 0) {  // odd rows with odd columns
        board[i][j] = '#';
      } else {
        board[i][j] = ' ';
      }
      */
    }
  }
}

void Knight::readFile(std::string fileName) {
  ifstream infile;
  
  infile.open(fileName);
  infile >> board_size;
  while(infile) {
    infile.get();  // to ignore the \n
    infile >> row;
    infile >> column;
  }
  infile.close();

  board[row][column] = 'P';
}

void Knight::calculateMoves(int row, int col, int depth, int current) {
  //cout << "Loop: " << current << endl;
  if(current == 0) {  // To update parameters upon initial function call.
    row = this->row;
    col = column;
  }
  
  if(current > depth) {  // Checking stop/exit conditions
    return;
  } else if(row < 0 || col < 0 || row >= board_size || col >= board_size) {
    return;
  }
  
  if(board[row][col] == ' ' || (board[row][col] > char (current + 48) && board[row][col] != 'P')) {  // ASCII conversion  int x == char (int x + 48)
    board[row][col] = char (current + 48);
  }
  
  calculateMoves(row - 2, col - 1, depth, current + 1);
  calculateMoves(row - 2, col + 1, depth, current + 1);
  calculateMoves(row - 1, col - 2, depth, current + 1);
  calculateMoves(row - 1, col + 2, depth, current + 1);
  calculateMoves(row + 1, col - 2, depth, current + 1);
  calculateMoves(row + 1, col + 2, depth, current + 1);
  calculateMoves(row + 2, col - 1, depth, current + 1);
  calculateMoves(row + 2, col + 1, depth, current + 1);
  //cout << "End of Loop: " << current << endl;
}

void Knight::printBoard() {  
  for(int i = 0; i < board_size; i++) {
    for(int plusdash = 0; plusdash < board_size; plusdash++) {
      cout << "+---";
    }
    cout << '+' << endl;
    //"+---+---+---+---+---+---+---+---+"
    
    // Row 1 Start
    cout << '|';
    for(int j = 0; j < board_size; j++) {
      cout << ' ' << board[i][j] << ' ' << '|';
      // The following block is for creating the alternating black and white squares on typical chess boards
      /* if(i % 2 == 0 && j % 2 == 0) {  //        even rows with even cols
	cout << '#' << board[i][j] << '#' << '|';
      }
      else if (i % 2 != 0 && j % 2 != 0) {  //     odd rows with odd cols
	cout << '#' << board[i][j] << '#' << '|';
      } else {
	cout << ' ' << board[i][j] << ' ' << '|';
	}*/
    }
    cout << endl;
  } // Row 8 End
  
  for(int plusdash = 0; plusdash < board_size; plusdash++) {  // plusdash++ lol
    cout << "+---";
    }
  cout << '+' << endl;
  //"+---+---+---+---+---+---+---+---+"
}
