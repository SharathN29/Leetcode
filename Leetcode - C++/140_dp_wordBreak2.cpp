// https://leetcode.com/problems/word-break-ii/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
    }
};

int main() {
	Solution *sol = new Solution();
	string s = "catsanddog";
	vector<string> wordDict = {"cat", "cats", "and", "sand", "dog"};
	vector<string> res = sol->wordBreak(s, wordDict);
	for(string s : res)
		cout << s << " ";
	cout << endl;
}