#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

#define SIZE 3

void initializeBoard(char board[SIZE][SIZE]);
void displayBoard(char board[SIZE][SIZE]);
int validateStrategy(const char *strategy);
void getBoardIndices(int number, int *row, int *col);
int isWinningMove(char board[SIZE][SIZE], char player);
int isBoardFull(char board[SIZE][SIZE]);
void makeAIMove(char board[SIZE][SIZE], const char *strategy, char aiMark);
void makePlayerMove(char board[SIZE][SIZE], char playerMark);

#endif // TIC_TAC_TOE_H
