// https://leetcode.com/problems/search-in-rotated-sorted-array/

#include <iostream>
#include <vector>

using namespace std;

int search(vector<int>& nums, int target) {
    int left = 0, right = nums.size()-1;
    while(left <= right) {
        int mid = left+(right-left)/2;
        if(nums[mid] == target) return mid;
        else if(nums[mid] >= nums[left]) {
            if(target >= nums[left] && target < nums[mid]) right = mid-1;
            else left = mid+1;
        } else {
            if(target <= nums[right] && target > nums[mid]) left = mid+1;
            else right = mid-1;
        }
    }
    return -1;
}

int main() {
	vector<int> nums = {4,5,6,7,0,1,2};
	int target = 0;

	int index = search(nums, target);
	cout << "Index : " << index << endl;
}