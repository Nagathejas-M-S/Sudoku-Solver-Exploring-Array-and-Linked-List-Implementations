// 1st approach (2d array approach)

#include <stdbool.h>
#include <stdio.h>

bool isSafe(char (*board)[9], int row, int col, int number) {
    // Check the column
    for (int i = 0; i < 9; i++) {
        if (board[i][col] == (char)(number + '0')) {
            return false;
        }
    }

    // Check the row
    for (int j = 0; j < 9; j++) {
        if (board[row][j] == (char)(number + '0')) {
            return false;
        }
    }

    // Check the 3x3 grid
    int sr = 3 * (row / 3);
    int sc = 3 * (col / 3);

    for (int i = sr; i < sr + 3; i++) {
        for (int j = sc; j < sc + 3; j++) {
            if (board[i][j] == (char)(number + '0')) {
                return false;
            }
        }
    }

    return true;
}

bool helper(char (*board)[9], int row, int col) {
    if (row == 9) {
        return true;
    }

    int nrow = 0;
    int ncol = 0;

    if (col == 8) {
        nrow = row + 1;
        ncol = 0;
    } else {
        nrow = row;
        ncol = col + 1;
    }

    if (board[row][col] != '.') {
        if (helper(board, nrow, ncol)) {
            return true;
        }
    } else {
        // Fill the place
        for (int i = 1; i <= 9; i++) {
            if (isSafe(board, row, col, i)) {
                board[row][col] = (char)(i + '0');
                if (helper(board, nrow, ncol)) {
                    return true;
                } else {
                    board[row][col] = '.';
                }
            }
        }
    }

    return false;
}
void inputSudoku(char (*board)[9]) {
    printf("Enter the Sudoku puzzle (use '.' for empty cells):\n");
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            scanf(" %c", &board[i][j]);
        }
    }
}

void printSudoku(char (*board)[9]) {
    printf("Sudoku Puzzle:\n");
    for (int i = 0; i < 9; i++) {
        if (i % 3 == 0 && i > 0) {
            printf("------+-------+------\n");
        }
        for (int j = 0; j < 9; j++) {
            if (j % 3 == 0 && j > 0) {
                printf("| ");
            }
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void solveSudoku(char (*board)[9]) {
    helper(board, 0, 0);
    printSudoku(board);
}

int main() {
    char sudokuBoard[9][9];

    inputSudoku(sudokuBoard);
    printSudoku(sudokuBoard);
    solveSudoku(sudokuBoard);

    return 0;
}

