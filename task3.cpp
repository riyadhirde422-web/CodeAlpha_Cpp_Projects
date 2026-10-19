#include <iostream>
using namespace std;

const int N = 9;

void printGrid(int grid[N][N])
{
    cout << "\nSolved Sudoku:\n";

    for (int row = 0; row < N; row++)
    {
        if (row % 3 == 0)
            cout << "-------------------------\n";

        for (int col = 0; col < N; col++)
        {
            if (col % 3 == 0)
                cout << "| ";

            cout << grid[row][col] << " ";
        }

        cout << "|\n";
    }

    cout << "-------------------------\n";
}

bool isSafe(int grid[N][N], int row, int col, int num)
{
    for (int x = 0; x < N; x++)
    {
        if (grid[row][x] == num)
            return false;

        if (grid[x][col] == num)
            return false;
    }

    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grid[startRow + i][startCol + j] == num)
                return false;
        }
    }

    return true;
}

bool solveSudoku(int grid[N][N])
{
    int row, col;
    bool empty = false;

    for (row = 0; row < N; row++)
    {
        for (col = 0; col < N; col++)
        {
            if (grid[row][col] == 0)
            {
                empty = true;
                break;
            }
        }

        if (empty)
            break;
    }

    if (!empty)
        return true;

    for (int num = 1; num <= 9; num++)
    {
        if (isSafe(grid, row, col, num))
        {
            grid[row][col] = num;

            if (solveSudoku(grid))
                return true;

            grid[row][col] = 0;
        }
    }

    return false;
}

int main()
{
    int grid[N][N] =
        {
            {5, 3, 0, 0, 7, 0, 0, 0, 0},
            {6, 0, 0, 1, 9, 5, 0, 0, 0},
            {0, 9, 8, 0, 0, 0, 0, 6, 0},
            {8, 0, 0, 0, 6, 0, 0, 0, 3},
            {4, 0, 0, 8, 0, 3, 0, 0, 1},
            {7, 0, 0, 0, 2, 0, 0, 0, 6},
            {0, 6, 0, 0, 0, 0, 2, 8, 0},
            {0, 0, 0, 4, 1, 9, 0, 0, 5},
            {0, 0, 0, 0, 8, 0, 0, 7, 9}};

    cout << "=========================\n";
    cout << "      SUDOKU SOLVER\n";
    cout << "     CodeAlpha Task 3\n";
    cout << "=========================\n";

    cout << "\nOriginal Sudoku (0 = empty):\n";
    printGrid(grid);

    if (solveSudoku(grid))
    {
        printGrid(grid);
    }
    else
    {
        cout << "No solution exists for this puzzle.\n";
    }

    return 0;
}