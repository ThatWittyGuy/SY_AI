#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 3

// Function to initialize the game board
void initializeBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = '-';
        }
    }
}

// Function to display the game board
void displayBoard(char board[SIZE][SIZE]) {
    printf("  0   1   2\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
            if (j < SIZE - 1) printf("| ");
        }
        printf("\n");
    }
}

// Function to check if a player has won
int checkWin(char board[SIZE][SIZE], char player) {
    // Check rows
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1;
        }
    }

    // Check columns
    for (int i = 0; i < SIZE; i++) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1;
    }

    return 0;
}

// Function to check if the game is a draw
int checkDraw(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == '-') {
                return 0;
            }
        }
    }
    return 1;
}

// Function to predict if the game will end in a draw
bool is_draw_predicted(char board[SIZE][SIZE], int turn_count) {

    bool x_can_win = false;
    bool o_can_win = false;


    if (turn_count >= 6) {
   
        for (int i = 0; i < SIZE; ++i) {
            if (board[i][0] == 'X' && board[i][1] == 'X' && board[i][2] == ' ') x_can_win = true;
            if (board[i][0] == 'O' && board[i][1] == 'O' && board[i][2] == ' ') o_can_win = true;
            if (board[0][i] == 'X' && board[1][i] == 'X' && board[2][i] == ' ') x_can_win = true;
            if (board[0][i] == 'O' && board[1][i] == 'O' && board[2][i] == ' ') o_can_win = true;
        }

        // Check diagonals for X and O
        if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == ' ') x_can_win = true;
        if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == ' ') o_can_win = true;
        if (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == ' ') x_can_win = true;
        if (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == ' ') o_can_win = true;


        if (!x_can_win && !o_can_win) {
            return true;
        }
    }

    return false;
}


void endGame(char board[SIZE][SIZE], char player) {
    if (checkWin(board, player)) {
        printf("Player %c wins!\n", player);
    } else if (checkDraw(board)) {
        printf("It's a draw!\n");
    }
}

int main() {
    char board[SIZE][SIZE];
    char player = 'X';
    int row, col;
    int turn_count = 0;

    initializeBoard(board);

    while (1) {
        displayBoard(board);

        if (turn_count >= 6 && is_draw_predicted(board, turn_count)) {
            printf("The game is going to end in a draw.\n");
            endGame(board, player);
            break;
        }

        printf("Player %c, enter row and column (0-%d): ", player, SIZE - 1);
        scanf("%d %d", &row, &col);

        if (row < 0 || row >= SIZE || col < 0 || col >= SIZE || board[row][col] != '-') {
            printf("Invalid move. Please try again.\n");
            continue;
        }

        board[row][col] = player;
        turn_count++;

        if (checkWin(board, player)) {
            displayBoard(board);
            printf("Player %c wins!\n", player);
            break;
        }

        if (checkDraw(board)) {
            displayBoard(board);
            printf("It's a draw!\n");
            break;
        }

        player = (player == 'X') ? 'O' : 'X';
    }

    return 0;
}