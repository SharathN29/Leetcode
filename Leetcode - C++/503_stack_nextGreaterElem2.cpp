// https://leetcode.com/problems/next-greater-element-ii/
// Time - O(N), Space - O(N)

#include <iostream>
#include <vector>
#include <stack>

using namespace std; 

vector<int> nextGreaterElements(vector<int>& nums) {
	int n = nums.size();
	vector<int> stack, res(n,-1);
	for(int i = 0; i < 2*n; i++) {
		while(stack.size() && nums[stack.back()] < nums[i%n]) {
			res[stack.back()] = nums[i%n];
			stack.pop_back();
		}
		stack.push_back(i%n);
	}   
	return res;
}

int main() {
	vector<int> nums = {1,2,1};
	for(int i = 0; i < nextGreaterElements(nums).size(); i++) 
		cout << nextGreaterElements(nums)[i] << " ";
	cout << endl;
}