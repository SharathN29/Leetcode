// https://leetcode.com/problems/valid-parentheses/
// Time : O(n), Space : O(n)

#include <iostream>
#include <stack>

using namespace std;

bool isValid(string s) {
    stack<int> st;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '(' || s[i] == '{' || s[i] == '[')
            st.push(s[i]);
        else {
            if(st.empty()) return false;
            if(s[i] == ')' && st.top() != '(') return false;
            else if(s[i] == ']' && st.top() != '[') return false;
            else if(s[i] == '}' && st.top() != '{') return false;
            st.pop();
        }
    }
    return st.empty();
}

int main() {
    string s = "]";
    if(isValid(s))
        cout << "Valid Parentheses" << endl;
    else cout << "Invalid" << endl;
}