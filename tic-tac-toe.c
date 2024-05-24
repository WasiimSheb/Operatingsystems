#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tic-tac-toe.h"

#define SIZE 3

void initializeBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

void displayBoard(char board[SIZE][SIZE]) {
    printf("-------------\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("| %c ", board[i][j]);
        }
        printf("|\n");
        printf("-------------\n");
    }
}

int validateStrategy(const char *strategy) {
    if (strlen(strategy) != 9) {
        return 0;
    }

    int digitCount[10] = {0};

    for (int i = 0; i < 9; i++) {
        if (!isdigit(strategy[i])) {
            return 0;
        }

        int digit = strategy[i] - '0';
        if (digit < 1 || digit > 9) {
            return 0;
        }

        digitCount[digit]++;
    }

    for (int i = 1; i <= 9; i++) {
        if (digitCount[i] != 1) {
            return 0;
        }
    }

    return 1;
}

void getBoardIndices(int number, int *row, int *col) {
    int index = number - 1; // Convert to zero-based index
    *row = index / SIZE;    // Calculate row
    *col = index % SIZE;    // Calculate column
}

int isWinningMove(char board[SIZE][SIZE], char player) {
    for (int i = 0; i < SIZE; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return 1;
        }
    }

    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return 1;
    }

    return 0;
}

int isBoardFull(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}

void makeAIMove(char board[SIZE][SIZE], const char *strategy, char aiMark) {
    for (int i = 0; i < 9; i++) {
        int row, col;
        getBoardIndices(strategy[i] - '0', &row, &col);
        if (board[row][col] == ' ') {
            board[row][col] = aiMark;
            printf("%d\n", strategy[i] - '0');
            return;
        }
    }
}

void makePlayerMove(char board[SIZE][SIZE], char playerMark) {
    int move;
    while (1) {
        printf("Enter your move (1-9): ");
        scanf("%d", &move);
        if (move < 1 || move > 9) {
            printf("Invalid move. Try again.\n");
            continue;
        }
        int row, col;
        getBoardIndices(move, &row, &col);
        if (board[row][col] == ' ') {
            board[row][col] = playerMark;
            return;
        } else {
            printf("That spot is already taken. Try again.\n");
        }
    }
}
