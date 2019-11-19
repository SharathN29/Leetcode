// Valid Palindrome

// Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

// Note: For the purpose of this problem, we define empty string as valid palindrome.

// Example 1:

// Input: "A man, a plan, a canal: Panama"
// Output: true
// Example 2:

// Input: "race a car"
// Output: false

#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string s) {
    for(int i = 0, j = s.size()-1; i < j; i++, j--){
        while(isalnum(s[i]) == false && i < j) i++;
        while(isalnum(s[j]) == false && i < j) j--;
        if(toupper(s[i]) != toupper(s[j])) return false;
    }
    return true;
}

int main() {
    string s = "A man, a plan, a canal: Panama";
    if(isPalindrome(s))
        cout<<"It is a palindrome " << endl;
    else
        cout<<"Not a palindrome" << endl;
}