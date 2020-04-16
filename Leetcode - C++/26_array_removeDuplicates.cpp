// https://leetcode.com/problems/remove-duplicates-from-sorted-array/
// Time : O(n), SPace : O(1)

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std; 

int removeDuplicates(vector<int>& nums) {
	int i = 0;
	for(int j = 1; j < nums.size(); j++){
		if(nums[j] != nums[i]){
			i++;
			nums[i] = nums[j];
		}
	}
	return i;
}

int main() {
	vector<int> nums = {1,1,2};
	cout << "Length of array : " << removeDuplicates(nums) << endl;
}