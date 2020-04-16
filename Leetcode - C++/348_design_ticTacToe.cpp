// https://leetcode.com/problems/design-tic-tac-toe/

#include <iostream>
#include <vector>

using namespace std; 

class TicTacToe {
private:
	vector<int> rowJudge;
	vector<int> colJudge;
	int diag, anti;
	int total;

public:
    /** Initialize your data structure here. */
    TicTacToe(int n) : total(n), rowJudge(n), colJudge(n), diag(0), anti(0) {}
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        int add = player == 1 ? 1 : -1;
		diag += row == col ? add : 0;
		anti += row == total - col - 1 ? add : 0;
		rowJudge[row] += add;
		colJudge[col] += add;
		if(abs(rowJudge[row]) == total || abs(colJudge[col]) == total || abs(diag) == total || abs(anti) == total)
			return player; 
		return 0;
    }
};