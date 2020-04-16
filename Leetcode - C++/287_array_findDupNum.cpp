// https://leetcode.com/problems/find-the-duplicate-number/
// Time - O(n), Space - O(1)

#include <iostream>
#include <vector>

using namespace std; 

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if(nums.size() > 1) {
        	int slow = nums[0];
			int fast = nums[nums[0]];
			
			while(slow != fast) {
				slow = nums[slow];
				fast = nums[nums[fast]];
			}
			fast = 0;
			while(fast != slow) {
				slow = nums[slow];
				fast = nums[fast];
			}
			return slow;
        }
		return -1;
    }
};

int main() {
	Solution *solution = new Solution();
	vector<int> nums = {1,3,4,2,2};
	int dup = solution->findDuplicate(nums);
	cout << "Duplicate Element : " << dup << endl;
}