/**
 * @file main.cpp
 * @author Kyle Byassee
 * @date 2022-03-30
 * @brief Encoding the possible movements of knight pieces multiple moves into the future.
 * 
 * Reads the board from a file. Its contents are the board size, coordinate information for a knight, and the number of possible moves into the future you need to display on the board.
 */

#include <iostream>
#include "Knight.h"

using namespace std;

int main() {
  Knight myKnight;  // Declare object and call constructor
  
  string fileName;
  cout << "Please enter the board file name: ";  // Prompt user for a file name
  cin >> fileName;
  cout << "File name accpeted: " << fileName << endl;

  myKnight.readFile(fileName);
  cout << "Data loaded from " << fileName << endl;  // Read data from the file and update the private data members

  cout << "\nInitial board:" << endl;
  myKnight.printBoard();  // Prints data from the file in a chess board format

  int depth = 0;
  cout << "\nHow many moves should be calculated? ";  // Prompt user for the the max recursive level
  cin >> depth;
  
  cout << "Calculating moves..." << endl;
  if(depth > 9 || depth < 0) {  // Error checking and imposing limits
    cout << "ERROR: invalid depth value, defaulting to 9" << endl;
    depth = 9;
  }
  int current = 0;
  int row = -1;  // Placeholder value
  int col = -1;  // Placeholder value
  myKnight.calculateMoves(row, col, depth, current);  // Calculate all possible moves up to depth moves

  cout << "All moves:" << endl;
  myKnight.printBoard();  // Prints the board again but with the number of moves to get to each square inside that square
  cout << endl;

  return 0;
}
