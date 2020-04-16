// https://leetcode.com/problems/jump-game-ii/

#include <iostream>
#include <vector>

using namespace std;

int jump(vector<int>& nums) {
	int n = nums.size(), start = 0, end = 0, steps = 0;
	while(end < n-1) {
		steps++;
		int maxEnd = end+1;
		for(int i = start; i <= end; i++) {
			if(i + nums[i] >= n-1) return steps;
			maxEnd = max(maxEnd, i+nums[i]);
		}
		start = end+1;
		end = maxEnd;
	}
	return steps;
}

int main() {
	vector<int> nums = {2,3,1,1,4};
	int jumps = jump(nums);
	cout << "Min Jumps : " << jumps << endl; 
}