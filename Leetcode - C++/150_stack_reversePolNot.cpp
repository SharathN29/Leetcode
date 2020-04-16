// https://leetcode.com/problems/evaluate-reverse-polish-notation/

#include <iostream>
#include <vector>
#include <stack>

using namespace std; 

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i = 0; i < tokens.size(); i++) {
            if(tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/")
                st.push(stoi(tokens[i]));
            else {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                if(tokens[i] == "*") st.push(a*b);
                else if(tokens[i] == "+") st.push(a+b);
                else if(tokens[i] == "-") st.push(a-b);
                else if(tokens[i] == "/") st.push(a/b);
            }
        }
        return st.top();
    }
};

int main() {
    Solution *solution = new Solution();
    vector<string> tokens = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    int res = solution->evalRPN(tokens);
    cout << "Result : " << res << endl;
}