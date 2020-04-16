// https://leetcode.com/problems/move-zeroes/
// Time : O(N), Space : O(1)

#include <iostream>
#include <vector>

using namespace std;

void moveZeroes(vector<int>& nums) {
	int i = 0;
	for(int j = 0; j < nums.size(); j++){
		if(nums[j] != 0){
			nums[i] = nums[j];
			i++;
		}
	}
	while(i < nums.size())
		nums[i++] = 0;
}

int main() {
	vector<int> nums = {0,1,0,2,3};
	moveZeroes(nums);
	for(int i = 0; i < nums.size(); i++)
		cout << nums[i] << " ";
	cout << endl;
}