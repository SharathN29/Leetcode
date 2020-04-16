#include <iostream>
#include <vector>

usign namespace std; 

void backtracking(vector<string>& res, string s, int  open, int close, int maxLen) {
    if(s.length() == 2 * maxLen){
        res.push_back(s);
        return; 
    }

    if(open < maxLen)
        backtracking(res, s+"(", open+1, close, maxLen);
    if(close < open)
        backtracking(res, s+")", open, close+1, maxLen);
}

vector<string> generateParenthesis(int n) {
    vector<string> res; 
    backtracking(res, "" , 0, 0, n);
    return res; 
}

int main() {
	int n = 3;
	vector<string> res = generateParenthesis(n);
	for(int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	cout << endl;
}