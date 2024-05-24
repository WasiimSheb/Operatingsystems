#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tic-tac-toe.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Error\n");
        return 1;
    }

    if (!validateStrategy(argv[1])) {
        printf("Error\n");
        return 1;
    }

    char board[SIZE][SIZE];
    char strategy[10];
    strcpy(strategy, argv[1]);
    char aiMark = 'X';
    char playerMark = 'O';

    initializeBoard(board);

    while (1) {
        // AI move
        makeAIMove(board, strategy, aiMark);
        displayBoard(board);
        if (isWinningMove(board, aiMark)) {
            printf("I win\n");
            break;
        }
        if (isBoardFull(board)) {
            printf("DRAW\n");
            break;
        }

        // Player move
        makePlayerMove(board, playerMark);
        displayBoard(board);
        if (isWinningMove(board, playerMark)) {
            printf("I lost\n");
            break;
        }
        if (isBoardFull(board)) {
            printf("DRAW\n");
            break;
        }
    }

    return 0;
}
