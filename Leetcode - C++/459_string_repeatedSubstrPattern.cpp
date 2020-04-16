// https://leetcode.com/problems/repeated-substring-pattern/

#include <iostream>
#include <unordered_map>

using namespace std; 

class Solution {
private:
    string comp = "";

public:
    bool repeatedSubstringPattern(string s) {
        unordered_map<char, int> map;
        for(int i = 0; i < s.length(); i++) {
            if(map.find(s[i]) != map.end()) {
                string temp = s.substr(i-comp.length(), i);
                if(comp.empty()) comp = temp;
                else {
                    if(comp != temp) return false; 
                    else map.clear();
                }
            }
            map[s[i]] = i;
        }
        return true;
    }
};

int main() {
    Solution *solution = new Solution();
    string s = "abcdabcdabcdabcdabcd";
    if(solution->repeatedSubstringPattern(s))
        cout << "Yes, repeated substring pattern" << endl;
    else cout << "No, not a repeated substring pattern" << endl;
}