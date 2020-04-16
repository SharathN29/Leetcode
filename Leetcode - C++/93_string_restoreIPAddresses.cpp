// https://leetcode.com/problems/restore-ip-addresses/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        
    }
};

int main() {
    Solution *sol = new Solution();
    string s = "25525511135";
    vector<string> res = sol->restoreIpAddresses(s);
    for(string s : res)
        cout << s << " ";
    cout << endl;
}