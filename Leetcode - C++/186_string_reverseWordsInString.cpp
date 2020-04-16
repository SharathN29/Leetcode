// https://leetcode.com/problems/reverse-words-in-a-string-ii/

#include <iostream>
#include <vector>

using namespace std;

class Solution { 
public:
    void reverseWords(string &s) {
        reverse(s.begin(), s.end());
        int n = s.length(), l = 0, r = 0;
        while (r < n) {
            while (r < n && !isspace(s[r])) r++;
            reverse(s.begin() + l, s.begin() + r); 
            l = ++r;
        }
    } 
};

int main() {
    Solution *solution = new Solution();
    vector<char> s = {"t","h","e"," ","s","k","y"," ","i","s"," ","b","l","u","e"};
    solution->reverseWords(s);
    for(char c : s) 
        cout << c << " ";
    cout << endl;
}