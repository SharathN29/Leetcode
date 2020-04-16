// https://leetcode.com/problems/game-of-life/

#include <iostream>
#include <vector>

using namespace std; 

int check(vector<vector<int>>& board, int i, int j) {
    int r = board.size(), c = r ? board[0].size():0; 
    if(i < 0 || i >= r || j < 0 || j >=c) return 0;
    if(abs(board[i][j]) == 1) return 1; 
    return 0;
}

void gameOfLife(vector<vector<int>>& board) {
    int r = board.size(), c = r ? board[0].size():0; 

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            int live = check(board, i, j+1) + 
                        check(board, i, j-1) +
                        check(board, i+1, j) +
                        check(board, i-1, j) +
                        check(board, i+1, j+1) +
                        check(board, i-1, j-1) +
                        check(board, i-1, j+1) +
                        check(board, i+1, j-1);

            if(board[i][j]) 
                if(live < 2 || live > 3)
                    board[i][j] = -1;

            if(!board[i][j]) 
                if(live == 3)
                    board[i][j] = 2;
        }
    }

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(board[i][j] == -1){
                board[i][j] = 0;
            }
            if(board[i][j] == 2){
                board[i][j] = 1;
            }
        }
    }
}

int main() {
    vector<vector<int>> board = {{0,1,0},{0,0,1},{1,1,1},{0,0,0}};
    gameOfLife(board);
}