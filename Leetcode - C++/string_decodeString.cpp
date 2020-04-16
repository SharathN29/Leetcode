#include <iostream>
#include <stack>
#include <string>

using namespace std; 

string decodeString(string s) {
    stack<int> count;
    stack<string> result; 
    string res = "";
    int index = 0, num = 0;

    while(index < s.length()) {
    	if(isdigit(s[index])){
    		num = num * 10 + (s[i] - '0'); 
    	}
    	else if(isalpha(s[i])) {
    		res += s[i];
    	}
    	else if(s[i] == '[') {
    		result.push(res);
    		count.push(num);
    		res = "";
    		num = 0;
    	}
    	else if(s[i] == ']') {
    		string temp = res;
    		for(int i = 0; i < count.top()-1; i++)
    			res += temp;
    		res = result.top() + res;
    		result.pop(), count.pop();
    	}
    }
    return res; 
}

int main() {
	string s = "3[a2[c]]";
	string res = decodeString(s);
	cout << "Decoded String : " << res << endl;
}