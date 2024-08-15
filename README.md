# Sudoku-Solver-Exploring-Array-and-Linked-List-Implementations

## Project Description
This project demonstrates two approaches to solving Sudoku puzzles in C. The first approach uses a traditional 2D array, while the second explores a linked list structure to manage the Sudoku grid. Each method implements backtracking to efficiently find solutions for given Sudoku puzzles.

## How to Run
### Compile and Run the 2D Array Approach:
gcc sudoku_approach1.c -o sudoku_approach1  
./sudoku_approach1

### Compile and Run the Linked List Approach:
gcc sudoku_approach2.c -o sudoku_approach2  
./sudoku_approach2

## Code Structure
### 2D Array Approach:
Uses a simple 9x9 2D array to represent the Sudoku board.
Implements functions to input the puzzle, check the validity of numbers, and solve the puzzle using backtracking.

## Linked List Approach:
Uses a linked list structure where each cell is a node in the list.
Provides an alternative data structure to explore Sudoku solving, maintaining the same backtracking logic.
Examples
After running either program, input a Sudoku puzzle with . for empty cells. The solver will process and display the solved Sudoku puzzle.

Example Input:

5 3 . . 7 . . . .
6 . . 1 9 5 . . .
. 9 8 . . . . 6 .
8 . . . 6 . . . 3
4 . . 8 . 3 . . 1
7 . . . 2 . . . 6
. 6 . . . . 2 8 .
. . . 4 1 9 . . 5
. . . . 8 . . 7 9
