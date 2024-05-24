#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tic-tac-toe.h"

#define SIZE 3

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "tic-tac-toe.h"

#define SIZE 3

/* 
 * @brief: Initializes the Tic-Tac-Toe board with empty spaces.
 * --------------------------
 * @details: Initializes each cell of the Tic-Tac-Toe board to contain an empty space character (' ').
 * 
 * @param: board The 3x3 Tic-Tac-Toe board to be initialized.
 */
void initializeBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

/* 
 * @brief: Displays the current state of the Tic-Tac-Toe board.
 * --------------------------
 * @details: Prints the current state of the Tic-Tac-Toe board to the standard output.
 *            Each cell of the board is displayed as '| <content> ', where <content> is either 'X', 'O', or empty.
 *            Rows are separated by horizontal lines.
 * 
 * @param: board The 3x3 Tic-Tac-Toe board to be displayed.
 */
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

/* 
 * @brief: Validates the strategy number provided as input.
 * --------------------------
 * @details: Checks if the strategy number is a valid 9-digit number containing each digit from 1 to 9 exactly once.
 * 
 * @param: strategy The strategy number provided as input.
 * 
 * @return: 1 if the strategy is valid, otherwise 0.
 */
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

/* 
 * @brief: Converts a move number (1-9) to row and column indices on the board.
 * --------------------------
 * @details: Converts the move number to a zero-based index and calculates the corresponding row and column indices.
 * 
 * @param: number The move number (1-9) to be converted.
 * @param: row Pointer to store the row index.
 * @param: col Pointer to store the column index.
 */
void getBoardIndices(int number, int *row, int *col) {
    int index = number - 1; // Convert to zero-based index
    *row = index / SIZE;    // Calculate row
    *col = index % SIZE;    // Calculate column
}

/* 
 * @brief: Checks if a move by a player results in a win.
 * --------------------------
 * @details: Checks all rows, columns, and diagonals of the board to see if they contain the player's mark in a winning combination.
 * 
 * @param: board The 3x3 Tic-Tac-Toe board to be checked.
 * @param: player The player's mark ('X' or 'O') to check for a win.
 * 
 * @return: 1 if the player has won, otherwise 0.
 */
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

/* 
 * @brief: Checks if the Tic-Tac-Toe board is full, indicating a draw.
 * --------------------------
 * @details: Checks if there are any empty
/* 
 * @brief: Checks if the Tic-Tac-Toe board is full, indicating a draw.
 * --------------------------
 * @details: Checks if there are any empty spaces left on the board. If all cells are filled with 'X' or 'O',
 *            the board is considered full and the game ends in a draw.
 * 
 * @param: board The 3x3 Tic-Tac-Toe board to be checked.
 * 
 * @return: 1 if the board is full, indicating a draw, otherwise 0.
 */
int isBoardFull(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                return 0;  // If any empty space found, board is not full
            }
        }
    }
    return 1;  // If no empty spaces found, board is full
}

/* 
 * @brief: Makes a move for the AI opponent based on the provided strategy number.
 * --------------------------
 * @details: Iterates through the strategy number digits to find the next move for the AI.
 *            The AI prioritizes moves based on the strategy number, selecting the highest priority available move.
 *            Once a valid move is found, it updates the board with the AI's mark and prints the chosen slot number.
 * 
 * @param: board The 3x3 Tic-Tac-Toe board.
 * @param: strategy The strategy number provided as input.
 * @param: aiMark The AI's mark ('X' or 'O') to make the move.
 */
void makeAIMove(char board[SIZE][SIZE], const char *strategy, char aiMark) {
    for (int i = 0; i < 9; i++) {
        int row, col;
        getBoardIndices(strategy[i] - '0', &row, &col);
        if (board[row][col] == ' ') {
            board[row][col] = aiMark;
            printf("%d\n", strategy[i] - '0');  // Print chosen slot
            return;
        }
    }
}

/* 
 * @brief: Allows the human player to make a move.
 * --------------------------
 * @details: Prompts the user to enter their move (1-9) until a valid move is provided.
 *            Validates the input and updates the board with the player's mark.
 * 
 * @param: board The 3x3 Tic-Tac-Toe board.
 * @param: playerMark The human player's mark ('X' or 'O') to make the move.
 */
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
