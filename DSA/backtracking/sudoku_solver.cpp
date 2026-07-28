#include <iostream>
#include <vector>

using namespace std;

// Size of the Sudoku grid
const int N = 9;

// Function to print the solved grid
void printGrid(int grid[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            cout << grid[row][col] << " ";
        }
        cout << endl;
    }
}

// Checks if it is safe to place 'num' at grid[row][col]
bool isSafe(int grid[N][N], int row, int col, int num) {
    // 1. Check if 'num' exists in the current row
    for (int x = 0; x < N; x++) {
        if (grid[row][x] == num) {
            return false;
        }
    }

    // 2. Check if 'num' exists in the current column
    for (int x = 0; x < N; x++) {
        if (grid[x][col] == num) {
            return false;
        }
    }

    // 3. Check if 'num' exists in the current 3x3 subgrid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }

    return true;
}

// Main recursive solver function
bool solveSudoku(int grid[N][N], int row, int col) {
    // Base case: If we reach the end of the board (row 8, col 9)
    if (row == N - 1 && col == N) {
        return true;
    }

    // Move to the next row if we reach the end of the current column
    if (col == N) {
        row++;
        col = 0;
    }

    // Skip cells that are already filled (greater than 0)
    if (grid[row][col] > 0) {
        return solveSudoku(grid, row, col + 1);
    }

    // Try placing numbers 1 to 9 in the empty cell
    for (int num = 1; num <= N; num++) {
        if (isSafe(grid, row, col, num)) {
            // Place the number tentatively
            grid[row][col] = num;

            // Move to the next cell
            if (solveSudoku(grid, row, col + 1)) {
                return true; 
            }

            // If placing 'num' doesn't lead to a solution, backtrack
            grid[row][col] = 0;
        }
    }

    // Trigger backtracking if no numbers 1-9 fit
    return false;
}

int main() {
    // 0 represents empty, unassigned cells
    int grid[N][N] = { 
        { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
        { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
        { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
        { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
        { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
        { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
        { 0, 0, 5, 2, 0, 6, 3, 0, 0 } 
    };

    if (solveSudoku(grid, 0, 0)) {
        cout << "Sudoku Solved Successfully:\n\n";
        printGrid(grid);
    } else {
        cout << "No solution exists for the given Sudoku puzzle." << endl;
    }

    return 0;
}