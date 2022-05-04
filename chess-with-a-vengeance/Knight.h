/**
 * @file Knight.h
 * @author Kyle Byassee
 * @date 2022-03-30
 * @brief The declaration of the Knight class.
 * 
 * Holds the current board size, knight's position as row and column, and holds the board array.
 */

#ifndef KNIGHT_H
#define KNIGHT_H
#include <string>

const int BIG_CHESS = 32;

/**
 * A Knight class to hold information for a knight piece.
 *
 * @class Knight Knight.h "hw09-chess-with-a-vengeance-kylhbyas/Knight.h"
 * @brief The declaration of the Knight class.
 *
 */
class Knight {
 private:
  int board_size = 0;
  int row = 0;
  int column = 0;
  char board[BIG_CHESS][BIG_CHESS] = {' '};  // size of standard chess board == 8 x 8
  
 public:

/**
 * Initializes the board to blanks, and initializes any other relevant member values.
 *
 * @pre This header file included in main().
 * @post Object is declared for use.
 * 
 */
  Knight();

/**
 * Reads data from the file, populating any relevant variables including the location of the rook in the grid.
 *
 * @param std::string fileName The user defined file name.
 * @pre Object declaration.
 * @return void 
 * @post The objects private data members are updated.
 * 
 */
  void readFile(std::string fileName);

/**
 * Recursive method to update the grid to include possible future moves of the knight, up to depth, with current tracking the current move.  If a position can be reached through multiple paths, only show the smallest value.
 *
 * @param int row position of move under consideration.
 * @param int col position of move under consideration.
 * @param int depth User defined max recursion level.
 * @param int current Current recursion level.
 * @pre Object declaration.
 * @return void 
 * @post The board array is updated.
 * 
 */
  void calculateMoves(int row, int col, int depth, int current);

/**
 * Prints the board to the screen.
 *
 * @pre Object declaration.
 * @return void 
 * @post 
 * 
 */
  void printBoard();
};
#endif //KNIGHT_H
