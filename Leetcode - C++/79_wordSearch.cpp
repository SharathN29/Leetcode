// https://leetcode.com/problems/word-search/

#include <iostream>
#include <vector>

using namespace std;

bool exist(vector<vector<char>>& board, string word) {
    int m = board.size(), n = board[0].size();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (search(board, i, j, word.c_str())) {
                return true;
            }
        }
    }
    return false;
}

bool search(vector<vector<char>>& board, int r, int c, const char* word) {
    if (!word[0]) {
        return true;
    }
    int m = board.size(), n = board[0].size();
    if (r < 0 || r >= m || c < 0 || c >= n || board[r][c] != word[0]) {
        return false;
    }
    board[r][c] = 0;
    if (search(board, r - 1 ,c, word + 1) || search(board, r + 1, c, word + 1) ||
        search(board, r, c - 1, word + 1) || search(board, r, c + 1, word + 1)) {
        return true;
    }
    board[r][c] = word[0];
    return false;
}

int main() {
	vector<vector<char>> board = {{}};
	string word = "";
	if(exist(board, word))
		cout << "Word Exist" << endl;
	else cout << "Word does not exist" << endl;
}