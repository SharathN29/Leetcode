// https://leetcode.com/problems/word-break-ii/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
    unordered_map<string, vector<string>> m;

    vector<string> combine(string word, vector<string> prev){
        for(int i=0;i<prev.size();++i){
            prev[i]+=" "+word;
        }
        return prev;
    }
    
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        if(m.count(s)) return m[s];
        vector<string> result;
        if(dict.count(s)){
            result.push_back(s);
        }
        for(int i=1;i<s.size();++i){
            string word=s.substr(i);
            if(dict.count(word)){
                string rem=s.substr(0,i);
                vector<string> prev=combine(word,wordBreak(rem,wordDict));
                result.insert(result.end(),prev.begin(), prev.end());
            }
        }
        m[s]=result;
        return result;
    }
};

int main() {
    Solution *sol = new Solution();
    string s = "carsanddog";
    vector<string> wordDict = {"cat", "cats", "and", "sand", "dog"};
    vector<string> res = sol->wordBreak(s, wordDict);
    for(string s : res) 
        cout << s << " ";
    cout << endl;
}