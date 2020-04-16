// https://leetcode.com/problems/palindromic-substrings/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
		vector<vector<bool>> dp(n, vector<bool>(n));
		int res = 0;
		
		for(int i = 0; i < n; i++) {
			for(int j = i; j >= 0; j--) {
				if(s[j] == s[i] && (i-j < 2 || dp[i-1][j+1]))
					dp[i][j] = true;
				if(dp[i][j])
					res++;
			}
		}
		return res;
    }
};

int main() {
	Solution *sol = new Solution();
	string s = "abc";
	cout << "Count : " << sol->countSubstrings(s) << endl;	
}