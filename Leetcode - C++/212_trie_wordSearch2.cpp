// https://leetcode.com/problems/word-search-ii/
// Reference : https://leetcode.com/problems/word-search-ii/discuss/59836/My-C%2B%2B-Trie-%2B-Backtrace-based-solution-(48-ms)

#include <iostream>
#include <vector>

using namespace std;

class Solution {
	class Trie{
	public:
		Trie *children[26];
		bool leaf;
		int idx; 
		Trie() {
			this->leaf = false; 
			this->idx = 0;
			fill_n(this->children, 26, nullptr);
		}
	};
	
public:
	void insertWords(Trie *root, vector<string>& words, int idx) {
		int pos = 0, len = words[idx].size();
		while(pos < len) {
			if(root->children[words[idx][pos]-'a'] == nullptr)
				root->children[words[idx][pos]-'a'] = new Trie();
			root = root->children[words[idx][pos++]-'a']; 
		}
		root->leaf = true; 
		root->idx = idx; 
	}
	
	Trie *buildTrie(vector<string> words) {
		Trie *root = new Trie();
		for(int i = 0; i < words.size(); i++) 
			insertWords(root, words, i);
		return root; 
	}
	
	void checkWords(vector<vector<char>>& board, int i, int j, int row, int col, Trie *root, vector<string>& res, vector<string>& words) {
		char temp;
		if(board[i][j] == 'X') return;
		if(root->children[board[i][j]-'a'] == nullptr) return;
		else {
			temp = board[i][j];
			if(root->children[temp-'a']->leaf) {
				res.push_back(words[root->children[temp-'a']->idx]);
				root->children[temp-'a']->leaf = false; 
			}
			board[i][j] = 'X';
			if(i > 0) checkWords(board, i-1, j, row, col, root->children[temp-'a'], res, words);
			if((i+1) < row) checkWords(board, i+1, j, row, col, root->children[temp-'a'], res, words);
			if(j > 0) checkWords(board, i, j-1, row, col, root->children[temp-'a'], res, words);
			if((j+1) < col) checkWords(board, i, j+1, row, col, root->children[temp-'a'], res, words);
			board[i][j] = temp;
		}
	}
	
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res; 
		int row = board.size();
		if(row == 0) return res; 
		int col = board[0].size();
		if(col == 0) return res; 
		int wordCount = words.size();
		if(wordCount == 0) return res;
		
		Trie *root = buildTrie(words);
		
		for(int i = 0; i < row; i++) {
			for(int j = 0; j < col && wordCount > res.size(); j++) {
				checkWords(board, i, j, row, col, root, res, words);
			}
		}
		return res;
    }
};

int main() {
	Solution *sol = new Solution();
	vector<vector<char>> board = {{'o','a','a','n'}, {'e','t','a','e'}, {'i','h','k','r'},{'i','f','l','v'}};
	vector<string> words = {"oath","pea","eat","rain"};
	vector<string> res = sol->findWords(board, words);
	for(string s : res) 
		cout << s << " ";
	cout << endl;
}