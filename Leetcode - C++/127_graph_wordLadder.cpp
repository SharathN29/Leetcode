//https://leetcode.com/problems/word-ladder/
//Time : O(M*N), M - length of words and N is the total number of words in the input word list. 
// Space - O(M*N)

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std; 

int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
	unordered_set<string> set(wordList.begin(), wordList.end());
	queue<string> q; 
	q.push(beginWord);
	int distance = 1;

	while(!q.empty()) {
		int len = q.size();
		for(int i = 0; i < len; i++) {
			string word = q.front();
			q.pop(); 
			if(word == endWord)
				return distance;
			set.erase(word);
			for(int j = 0; j < word.size(); j++) {
				char c = word[j];
				for(int k = 0; k < 26; k++) {
					word[j] = 'a' + k;
					if(set.find(word) != set.end()) {
						q.push(word);
					}
				}
				word[j] = c;
			}
		}
		distance++;
	}
	return 0;
}

int main() {
	string beginWord = "hit", endWord = "cog";
	vector<string> wordList = {"hot","dot","dog","lot","log","cog"};

	cout << "Length of transformation : " << ladderLength(beginWord, endWord, wordList) << endl;
}