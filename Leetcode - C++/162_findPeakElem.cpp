// https://leetcode.com/problems/find-peak-element/

#include <iostream>
#include <vector>

using namespace std; 

int search(vector<int>& nums, int l, int r){
    if(l == r) return l;
    int mid = (l+r)/2;
    while(l < r) {
        if(nums[mid] > nums[mid+1])
            return search(nums, l, mid);
        return search(nums, mid+1, r);
    }
}

int findPeakElement(vector<int>& nums) {
    return search(nums, 0, nums.size()-1);
}

int main() {
    vector<int> nums = {1,2,3,1};
    int peak = findPeakElement(nums);
    cout << "Peak Element : " << peak << endl;
}