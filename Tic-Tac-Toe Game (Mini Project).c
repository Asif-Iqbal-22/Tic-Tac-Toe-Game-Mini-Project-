#include <stdio.h>

char board[3][3];
char player = 'X';

void initBoard() {
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            board[i][j] = ' ';
}

void printBoard() {
    printf("\n");
    for(int i=0;i<3;i++) {
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if(i != 2) printf("---|---|---\n");
    }
    printf("\n");
}

int checkWin() {
    for(int i=0;i<3;i++) {
        if(board[i][0]==player && board[i][1]==player && board[i][2]==player) return 1;
        if(board[0][i]==player && board[1][i]==player && board[2][i]==player) return 1;
    }
    if(board[0][0]==player && board[1][1]==player && board[2][2]==player) return 1;
    if(board[0][2]==player && board[1][1]==player && board[2][0]==player) return 1;
    return 0;
}

int main() {
    int row, col, moves;
    char playAgain;

    do {
        initBoard();
        player = 'X';
        moves = 0;
        printf("=== Tic-Tac-Toe Game ===\n");

        while(1) {
            printBoard();
            printf("Player %c, enter row and column (0-2): ", player);
            scanf("%d %d", &row, &col);

            if(row<0 || row>2 || col<0 || col>2 || board[row][col]!=' ') {
                printf("Invalid move! Try again.\n");
                continue;
            }

            board[row][col] = player;
            moves++;

            if(checkWin()) {
                printBoard();
                printf("Player %c wins!\n", player);
                break;
            } else if(moves==9) {
                printBoard();
                printf("It's a draw!\n");
                break;
            }

            player = (player=='X') ? 'O' : 'X';
        }

        printf("Do you want to play again? (Y/N): ");
        getchar(); // clear buffer
        scanf("%c", &playAgain);

    } while(playAgain=='Y' || playAgain=='y');

    printf("Thanks for playing!\n");
    return 0;
}
