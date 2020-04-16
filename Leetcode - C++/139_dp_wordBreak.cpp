// https://leetcode.com/problems/word-break/

#include <iostream>
#include <vector>

using namespace std;

bool wordBreak(string s, vector<string>& wordDict) {
    vector<bool> dp(s.size()+1, false);
    dp[0] = true;
    for(int i = 0; i<s.size(); i++){
        if(dp[i]){
            for(auto& temp:wordDict){
                if(s.find(temp, i)==i){
                    dp[i+temp.length()] = true;
                }
            }
        }
    }
    return dp[s.size()];
}

int main() {
	string s = "leetcode";
	vector<string> wordDict = {"leet", "code"};
	if(wordBreak(s, wordDict))
		cout << "Possible" << endl;
	else cout << "Not Possible" << endl;
}