// https://leetcode.com/problems/132-pattern/
// https://leetcode.com/problems/132-pattern/discuss/166953/Easy-and-concise-C%2B%2B-solution-using-a-stack-with-explanation-VERY-EASY-to-understand

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool find132pattern(vector<int>& nums) {
    stack<int> s;
	int prev = INT_MIN;
	
	for(auto it = nums.rbegin(); it != nums.rend(); it++) {
		while(!s.empty() && s.top() < *it) {
			if(prev > s.top())
				return true;
			prev = s.top();
			s.pop();
		}
		s.push(*it);
	}
	return !s.empty() && prev > s.top();
}

int main() {
	vector<int> nums = {3,1,4,2};
	if(find132pattern(nums))
		cout << "Pattern Exists" << endl;
	else cout << "Not, it doesn't exists" << endl;
}