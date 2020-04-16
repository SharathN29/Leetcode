// https://leetcode.com/problems/longest-increasing-subsequence/

#include <iostream>
#include <vector>

using namespace std;

int lengthOfLIS(vector<int>& nums) {
    int size = nums.size();
    if(!size) return 0;

    vector<int> dp(size, 1);
    int res = 1;
    for(int i = 1; i < size; i++) {
        for(int j = 0; j < i; j++) {
            if(nums[j] < nums[i]) {
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
        res = max(res, dp[i]);
    }
    return res;
}

int main() {
    vector<int> nums = {10,9,2,5,3,7,101,18};
    int length = lengthOfLIS(nums);
}