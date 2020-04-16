#include <iostream>
#include <string>

using namespace std;

string reverseWords(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != ' ') {
            int j = i;
            for (; j < s.length() && s[j] != ' '; j++) { }
            reverse(s.begin() + i, s.begin() + j);
            i = j - 1;
        }
    }
    
    return s;
}

int main() {
	string s = "Let's take LeetCode contest";
	string res = reverseWords(s);
	cout << "Reversed string : " << res << endl;
}