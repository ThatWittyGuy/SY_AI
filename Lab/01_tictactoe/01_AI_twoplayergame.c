#include <stdio.h>
#include <stdbool.h>

#define SIZE 3

//Function for printing the Game Board
void print_board(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
            if (j < SIZE - 1) printf("| ");
        }
        printf("\n");
        if (i < SIZE - 1) printf("---------\n");
    }
}

//Function to check Winning condition
bool check_winner(char board[SIZE][SIZE], char mark) {
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == mark && board[i][1] == mark && board[i][2] == mark) return true;
        if (board[0][i] == mark && board[1][i] == mark && board[2][i] == mark) return true;
    }
    //Diagonal Condition
    if (board[0][0] == mark && board[1][1] == mark && board[2][2] == mark) return true;
    if (board[0][2] == mark && board[1][1] == mark && board[2][0] == mark) return true;
    return false;
}
//Function to check Draw condition
bool is_draw(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (board[i][j] == ' ') return false;
    return true;
}

//Actual function
void play_non_ai_tic_tac_toe() {
    char board[SIZE][SIZE] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
    char current_player = 'X';
    int row, col;

    while (true) {
        print_board(board);
        printf("Player %c, enter row and column (0-2): ", current_player);
        scanf("%d %d", &row, &col);

        if (board[row][col] != ' ') {
            printf("Cell already taken, try again.\n");
            continue;
        }

        board[row][col] = current_player;

        if (check_winner(board, current_player)) {
            print_board(board);
            printf("Player %c wins!\n", current_player);
            break;
        }
        if (is_draw(board)) {
            print_board(board);
            printf("It's a draw!\n");
            break;
        }

        current_player = (current_player == 'X') ? 'O' : 'X';
    }
}

//The Main function
int main() {
    play_non_ai_tic_tac_toe();
    return 0;
}