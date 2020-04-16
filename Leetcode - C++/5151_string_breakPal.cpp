// https://leetcode.com/contest/biweekly-contest-18/problems/break-a-palindrome/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string breakPalindrome(string S) {
        int n = S.size();
        for (int i = 0; i < n / 2; ++i) {
            if (S[i] != 'a') {
                S[i] = 'a';
                return S;
            }
        }
        S[n - 1] = 'b';
        return n < 2 ? "" : S;
    }
};

int main() {
    Solution *sol = new Solution();
    string pal = "abccba";
    string res = sol->breakPalindrome(pal);
    cout << res << endl;
}