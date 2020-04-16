// https://leetcode.com/problems/majority-element/

#include <iostream>
#include <vector>

using namespace std;

int majorityElement(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    return nums[nums.size()/2];
}

int main() {
    vector<int> nums = {2,2,1,1,1,2,2};
    int majority = majorityElement(nums);
    cout << "Majority Element : " << majority << endl;
}