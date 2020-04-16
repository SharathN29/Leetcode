// https://leetcode.com/problems/longest-valid-parentheses/

#include <iostream>
#include <vector>
#include <string> 
#include <stack>

using namespace std;

// This is a O(n) time and space solution, as it turns out we can do it without using extra space by traversing the string twice 
// int longestValidParentheses(string s) {
//     int maxAns = 0;
//     stack<int> st; 
//     st.push(-1);
//     for(int i = 0; i < s.length(); i++) {
//         if(s[i] == '(') {
//             st.push(i);
//         } else{
//             st.pop();
//             if(st.empty()) {
//                 st.push(i);
//             } else {
//                 maxAns = max(maxAns, i-st.top());
//             }
//         }
//     }
//     return maxAns; 
// }

int longestValidParentheses(string s) {
	int left = 0, right = 0; 
	int maxLength = 0;

	for(int i = 0; i < s.length(); i++) {
		if(s[i] == '(') left++;
		else right++;
		if(left == right) maxLength = max(maxLength, 2*right);
		else if(right >= left) left = right = 0;
	}

	left = right = 0;
	
	for(int i = s.length()-1; i >= 0; i--) {
		if(s[i] == '(') left++;
		else right++;
		if(left == right) maxLength = max(maxLength, 2*left);
		else if(left >= right) left = right = 0;
	}

	return maxLength;
}

int main() {
	string s = ")()()()(()";
	int len = longestValidParentheses(s);
	cout << "Length : " << len << endl;
}