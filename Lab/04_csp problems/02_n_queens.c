#include <stdio.h>
#include <stdbool.h>

#define MAX 20

int board[MAX][MAX];
int queenPositions[MAX]; // Array to store the positions of queens

// Function to print the board along with column indices of queens
void printBoard(int n)
{
    // Print column indices of queens
    printf("Queens positions: [");
    for (int j = 0; j < n; j++)
    {
        printf("%d", queenPositions[j] + 1); // +1 to convert from 0-based to 1-based index
        if (j < n - 1)
            printf(", ");
    }
    printf("]\n");

    // Print the board
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 1)
                printf(" Q ");
            else
                printf(" . ");
        }
        printf("\n");
    }
    printf("\n");
}

// Function to check if placing a queen at (row, col) is safe
bool isSafe(int row, int col, int n)
{
    for (int i = 0; i < col; i++)
    {
        if (board[row][i])
            return false; // Check row
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j])
            return false; // Check upper diagonal
    }
    for (int i = row, j = col; j >= 0 && i < n; i++, j--)
    {
        if (board[i][j])
            return false; // Check lower diagonal
    }
    return true;
}

// Function to solve the N-Queens problem
void solveNQueens(int col, int n)
{
    if (col >= n)
    {
        printBoard(n);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (isSafe(i, col, n))
        {
            board[i][col] = 1;        // Place queen
            queenPositions[col] = i;  // Store the row position of the queen in this column
            solveNQueens(col + 1, n); // Recur to place the rest of the queens
            board[i][col] = 0;        // Backtrack
        }
    }
}

int main()
{
    int n;
    printf("Enter the number of queens (N): ");
    scanf("%d", &n);

    // Initialize the board
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            board[i][j] = 0;

    printf("\nAll possible solutions for %d queens:\n", n);
    solveNQueens(0, n);
    return 0;
}