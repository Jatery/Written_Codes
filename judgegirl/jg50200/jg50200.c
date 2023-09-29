#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

#define maxrow 500
#define maxcol 500

#define stone 0
#define queen 1
#define bishop 2
#define rook 3

void putstone(int board[maxrow][maxcol], int r, int c) {
	assert(board[r][c] == 0);
	board[r][c] = 1;
	return;
}

void bishopattack(int board[maxrow][maxcol], int r, int c, int row, int col) {
	for(int i = 1; r + i < row && c + i < col && board[r + i][c + i] == 0; ++i)
		board[r + i][c + i] = 1;
	for(int i = 1; r - i >= 0 && c + i < col && board[r - i][c + i] == 0; ++i)
		board[r - i][c + i] = 1;
	for(int i = 1; r + i < row && c - i >= 0 && board[r + i][c - i] == 0; ++i)
		board[r + i][c - i] = 1;
	for(int i = 1; r - i >= 0 && c - i >= 0 && board[r - i][c - i] == 0; ++i)
		board[r - i][c - i] = 1;
	board[r][c] = 1;
	return;
}

void rookattack(int board[maxrow][maxcol], int r, int c, int row, int col) {
	for(int i = 1; r + i < row && board[r + i][c] == 0; ++i)
		board[r + i][c] = 1;
	for(int i = 1; r - i >= 0 && board[r - i][c] == 0; ++i)
		board[r - i][c] = 1;
	for(int i = 1; c + i < col && board[r][c + i] == 0; ++i)
		board[r][c + i] = 1;
	for(int i = 1; c - i >= 0 && board[r][c - i] == 0; ++i)
		board[r][c - i] = 1;
	board[r][c] = 1;
	return;
}

void queenattack(int board[maxrow][maxcol], int r, int c, int row, int col) {
	bishopattack(board, r, c, row, col);
	rookattack(board, r, c, row, col);
	return;
}



int main() {
	int row, col, board[maxrow][maxcol] = {{0}};
	scanf("%d%d", &row, &col);

	assert(row <= maxrow);
	assert(col <= maxcol);

	

	int type, r, c;
	while(scanf("%d%d%d", &type, &c, &r) != EOF) {
		assert(type >= 0 && type <= 3);
		assert(c >= 0 && c < col);
		assert(r >= 0 && r < row);
		
		switch(type) {
			case stone:
				putstone(board, r, c);
				break;
			case queen:
				queenattack(board, r, c, row, col);
				break;
			case bishop:
				bishopattack(board, r, c, row, col);
				break;
			case rook:
				rookattack(board, r, c, row, col);
				break;
		}
	}

	for(int i = 0; i < row; ++i) 
		for(int j = 0; j < col; ++j) 
			printf("%d%c", board[i][j], (j == col - 1 ? '\n' : ' '));
}
