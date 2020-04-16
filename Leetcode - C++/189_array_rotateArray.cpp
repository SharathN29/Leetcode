// https://leetcode.com/problems/rotate-array/

#include <iostream>
#include <vector>

using namespace std; 

void rotate(vector<int>& nums, int k) {
	reverse(nums.begin(), nums.end());
	reverse(nums.begin(), nums.begin()+(k%nums.size()));
	reverse(nums.begin()+(k%nums.size()), nums.end());  
}

int main() {
	vector<int> nums = {1,2,3,4,5,6,7};
	int k = 3;
	rotate(nums, k);
	for(int i : nums) 
		cout << i << " ";
	cout << endl;
}