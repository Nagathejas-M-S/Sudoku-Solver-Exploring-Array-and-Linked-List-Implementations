
// 2nd approach  (linked list approach)
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a Sudoku cell
typedef struct Cell {
    char value;
    struct Cell* next;
} Cell;

// Define a structure for the Sudoku board
typedef struct SudokuBoard {
    Cell* cells[9][9];
} SudokuBoard;

// Initialize a cell with a given value
Cell* initializeCell(char value) {
    Cell* cell = malloc(sizeof(Cell));
    cell->value = value;
    cell->next = NULL;
    return cell;
}

// Initialize a Sudoku board with empty cells
SudokuBoard* initializeSudokuBoard() {
    SudokuBoard* board = malloc(sizeof(SudokuBoard));
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            board->cells[i][j] = initializeCell('.');
        }
    }
    return board;
}

// Print the Sudoku board 
void printSudoku(SudokuBoard* board) {
    printf("Sudoku Puzzle:\n");
    for (int i = 0; i < 9; i++) {
        if (i % 3 == 0 && i > 0) {
            printf("------+-------+------\n");
        }
        for (int j = 0; j < 9; j++) {
            if (j % 3 == 0 && j > 0) {
                printf("| ");
            }
            printf("%c ", board->cells[i][j]->value);
        }
        printf("\n");

    }
}

// Check if a number can be placed in a cell
bool isSafe(SudokuBoard* board, int row, int col, char number) {
    // Check the row
    for (int j = 0; j < 9; j++) {
        if (board->cells[row][j]->value == number) {
            return false;
        }
    }

    // Check the column
    for (int i = 0; i < 9; i++) {
        if (board->cells[i][col]->value == number) {
            return false;
        }
    }

    // Check the 3x3 box
    int boxRow = (row / 3) * 3;
    int boxCol = (col / 3) * 3;
    for (int i = boxRow; i < boxRow + 3; i++) {
        for (int j = boxCol; j < boxCol + 3; j++) {
            if (board->cells[i][j]->value == number) {
                return false;
            }
        }
    }

    return true;
}

// Solve the Sudoku puzzle using backtracking
bool solveSudoku(SudokuBoard* board) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (board->cells[row][col]->value == '.') {
                for (char num = '1'; num <= '9'; num++) {
                    if (isSafe(board, row, col, num)) {
                        board->cells[row][col]->value = num;
                        if (solveSudoku(board)) {
                            return true;
                        }
                        board->cells[row][col]->value = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main() {
    SudokuBoard* sudokuBoard = initializeSudokuBoard();

    // Input the Sudoku puzzle (use '.' for empty cells)
    printf("Enter the Sudoku puzzle (use '.' for empty cells):\n");
    for (int i = 0; i < 9; i++) {
            scanf("%c %c %c %c %c %c %c %c %c", &sudokuBoard->cells[i][0]->value, &sudokuBoard->cells[i][1]->value, &sudokuBoard->cells[i][2]->value, &sudokuBoard->cells[i][3]->value, &sudokuBoard->cells[i][4]->value, &sudokuBoard->cells[i][5]->value, &sudokuBoard->cells[i][6]->value, &sudokuBoard->cells[i][7]->value, &sudokuBoard->cells[i][8]->value);
            fflush(stdin);
        }
    printf("input Suduko Puzzle:\n");
    printSudoku(sudokuBoard);

    // Solve and print the Sudoku puzzle
    if (solveSudoku(sudokuBoard)) {
        printf("\nSolved Sudoku:\n");
        printSudoku(sudokuBoard);
    } else {
        printf("\nNo solution found.\n");
    }

    return 0;
}
