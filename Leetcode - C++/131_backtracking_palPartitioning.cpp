// https://leetcode.com/problems/palindrome-partitioning/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        if(s.empty()) return res; 
        vector<string> path;
        dfs(0, s, path, res);
        return res;
    }
    
    void dfs(int index, string& s, vector<string>& path, vector<vector<string>>& res) {
        if(index == s.length()) {
            res.push_back(path);
            return;
        }
        for(int i = index; i < s.length(); i++) {
            if(isPalindrome(s, index, i)) {
                path.push_back(s.substr(index, i-index+1));
                dfs(i+1, s, path, res);
                path.pop_back();
            }
        }
    }
    
    bool isPalindrome(string& s, int l, int r) {
        while(l <= r) {
            if(s[l++] != s[r--]) 
                return false;
        }
        return true;
    }
};

int main() {
    Solution *solution = new Solution();
    string s = "aab";
    vector<vector<string>> res = solution->partition(s);
    for(int i = 0; i < res.size(); i++) {
        for(int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}