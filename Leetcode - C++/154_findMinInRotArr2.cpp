// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/
// Time : O(log N)

#include <iostream>
#include <vector>

using namespace std; 

int findMin(vector<int>& nums) {
    int left = 0, right = nums.size()-1;
    while(left < right) {
        int mid = left + (right-left)/2;
        if(nums[mid] < nums[right]) right = mid;
        else if(nums[mid] > nums[right]) left = mid+1;
        else right -= 1;
    }
    return nums[left];
}

int main() {
    vector<int> nums = {2,2,2,0,1};
    cout << "Min Element : " << findMin(nums) << endl;
}