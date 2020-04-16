#include <iostream>
#include <string> 
#include <vector>

using namespace std;

string helper(string& s1, string& s2) {
    string res = "";
    for(int i = 0; i < s1.length(); i++){
        if(s1[i] == s2[i])
            res += s1[i];
        else return res;
    }
    return res;
}

string longestCommonPrefix(vector<string>& strs) {
    if(strs.size() == 0) return "";
    if(strs.size() == 1) return strs[0];
    string res = helper(strs[0], strs[1]);
    for(int i = 2; i < strs.size(); i++) {
        res = helper(res, strs[i]);
    }
    return res;
}

int main(){
    vector<string> strs = {"a"};
    string longestPrefix = longestCommonPrefix(strs);
    cout << "Longest Common Prefix : " << longestPrefix << endl;
}