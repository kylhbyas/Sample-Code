# HW09 - Chess 3: With a Vengeance
Name: Kyle Byassee

Date: 2022-04-05

## Required Files
* Makefile
  * Controls compilation and cleans temporary and extraneous files.

* Knight.h
  * Declares the Knight class.

* Knight.cpp
  * Contains the definitions of the methods for the Knight class.

* main.cpp
  * Contains the main function and interacts with the user.

## Compilation Instructions
How do we compile your program?
* To compile type <make> which calls the Makefile.

## Program usage
How do we run your program?  Does it expect any inputs?
* To run the program type <make> to compile and make the executable then type <./knight> to run the executable.

* The program will prompt the user for a board file name, then another prompt for the number of moves in the future that the program will evaluate to.

* If the board file to be imported is in a different folder than the executable then the format will have to be <folder/fileName>

## Notes
Any extra notes, such as:
* What is working?
  * The entire program is working as intended.

* What are the limitations of your program?
  * The max board size is 32x32
  * The max depth is 9
  * Negative integers for depth, row, column, and board_size are not supported.

* What design decisions did you make?
  * Consistency was the primary consideration at the time of writing.

## Task
You are to read the board from a file. Its contents are the board size, coordinate information for a knight.

Input comes in the following file format:
```
board_size
row column
```

After loading information from the file, your program should print the current board, and prompt the user for the number of moves into the future you should calculate.  Valid values are 0 through 9.  In the event that an invalid value has been entered, your program should print an error message and default to displaying 9 moves into the future.

E.g., The input file:
```
8
5 3
```

Would correspond to the following user interaction:
```
Please enter the board file name: input/t2.txt
File name accepted: input/t2.txt
Data loaded from input/t2.txt

Initial board:
+---+---+---+---+---+---+---+---+
|   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+
|   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+
|   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+
|   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+
|   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+
|   |   |   | P |   |   |   |   |
+---+---+---+---+---+---+---+---+
|   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+
|   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+

How many moves should be calculated? -12
Calculating moves...
ERROR: invalid depth value, defaulting to 9
All moves:
+---+---+---+---+---+---+---+---+
| 4 | 3 | 4 | 3 | 4 | 3 | 4 | 3 |
+---+---+---+---+---+---+---+---+
| 3 | 2 | 3 | 2 | 3 | 2 | 3 | 4 |
+---+---+---+---+---+---+---+---+
| 2 | 3 | 2 | 3 | 2 | 3 | 2 | 3 |
+---+---+---+---+---+---+---+---+
| 3 | 4 | 1 | 2 | 1 | 4 | 3 | 2 |
+---+---+---+---+---+---+---+---+
| 2 | 1 | 2 | 3 | 2 | 1 | 2 | 3 |
+---+---+---+---+---+---+---+---+
| 3 | 2 | 3 | P | 3 | 2 | 3 | 2 |
+---+---+---+---+---+---+---+---+
| 2 | 1 | 2 | 3 | 2 | 1 | 2 | 3 |
+---+---+---+---+---+---+---+---+
| 3 | 4 | 1 | 2 | 1 | 4 | 3 | 2 |
+---+---+---+---+---+---+---+---+
```
Notice how all valid moves from the knight's position are marked with a '1', and all valid moves from each of those positions is marked with a '2'. If we look closely at the example, we see that 4 is the largest number on the board, indicating that any space on the board can be reached by a knight in the provided starting position within 4 moves!
