// https://leetcode.com/problems/reverse-string/
// Time : O(N), Space : O(1)

#include <iostream>
#include <vector>

using namespace std;

void reverseString(vector<char>& s) {
    int start = 0, end = s.size()-1;
    while(start < end){ 
    	swap(s[start], s[end]);
    	start++;
    	end--;
    }
}

int main() {
	vector<char> s = {"h", "e", "l", "l", "o"};
	reverseString(s);
	for(char c : s)
		cout << c << " ";
	cout << endl;
}