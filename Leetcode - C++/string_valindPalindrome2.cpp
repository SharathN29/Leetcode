// https://leetcode.com/problems/valid-palindrome-ii/
// Time - O(n * 2^d)

#include <iostream>
#include <string>

using namespace std;

bool validPalindrome(string s) {
    for(int i = 0, j = s.size()-1; i < j; i++, j--) {
        if(s[i] != s[j]) return isPalindrome(s,i+1,j) || isPalindrome(s,i,j-1);
    }
    return true;
}

bool isPalindrome(string s, int l, int r) {
    for(int i = l, j = r; i < j; i++, j--)
        if(s[i] != s[j]) return false;
    return true;
}

int main() {
    string s = "abca";
    if(validPalindrome(s))
        cout << "Valid Palindrome " << endl;
    else cout << "Not a valid palindrome" << endl;
}