//https://leetcode.com/problems/basic-calculator/
// Time - O(N), where N is the length of the string
// Space - O(N)

#include <iostream>
#include <stack>

using namespace std; 

int calculate(string& s) {
	stack<int> nums, ops;
	int num = 0, res = 0, sign = 1;
	for(char& c: s) {
		if(isdigit(c)) {
			num = num*10 + c - '0';
		} else {
			res = sign * num;
			num = 0;
			if(c == '+') sign = 1;
			if(c == '-') sign = -1;
			if(c == '(') { 
				nums.push(res);
				ops.push(sign);
				res = 0;
				sign = 1;
			}
			if(c == ')') {
				res = ops.top() * res + nums.top();
				ops.pop();
				nums.pop();
			}
		}
	}
	res += sign * num;
	return res;
}

int main() {
	string s = "(1+(4+5+2)-3)+(6+8)";
	int res = calculate(s);
	cout << "Result : " << res << endl;
}