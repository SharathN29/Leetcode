// https://leetcode.com/problems/basic-calculator-ii/

#include <iostream>
#include <stack>
#include <cctype>

using namespace std; 

int calculate(string s) {
	stack<int> myStack;
	char sign = '+';
	int res = 0, temp = 0;

	for(unsigned int i = 0; i < s.size(); i++) {
		if(isdigit(s[i])) {
			temp = temp*10 + s[i] - '0';
		}
		if(!isdigit(s[i]) && !isspace(s[i]) || i == s.size()-1) {
			if(sign == '-')
				myStack.push(-temp);
			else if(sign == '+') 
				myStack.push(temp);
			else {
				int num;
				if(sign == '*')
					num = myStack.top() * temp;
				else 
					num = myStack.top() / 10;
				myStack.pop();
				myStack.push(num);
			}
			sign = s[i];
			temp = 0;
		}
	}

	while(!myStack.empty()) {
		res += myStack.top();
		myStack.pop();
	}
	return res;
}

int main() {
	string s = "3+2*2";
	int res = calculate(s);
	cout << "Result : " << res << endl;
}