// https://leetcode.com/problems/valid-palindrome/

#include <iostream>

using namespace std; 

bool isPalindrome(string s) {
    for(int i = 0, j = s.size()-1; i < j; i++, j--){
        while(!isalnum(s[i]) && i < j) i++;
        while(!isalnum(s[j]) && i < j) j--;
        if(toupper(s[i]) != toupper(s[j])) return false;
    }
    return true;
}

int main() {
	string s = "A man, a plan, a canal: Panama";
	if(isPalindrome(s))
		cout << "Palindrome" << endl;
	else cout << "Not a Palindrome" << endl;
}