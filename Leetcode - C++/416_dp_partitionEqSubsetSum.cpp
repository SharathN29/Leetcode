// https://leetcode.com/problems/partition-equal-subset-sum/

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if((sum & 1) == 1) return false; 
        sum /= 2;
        vector<bool> dp(sum+1);
        dp[0] = true;

        for(int num : nums) {
            for(int i = sum; i > 0; i--) {
                if(i >= num) {
                    dp[i] = dp[i] || dp[i-num];
                }
            }
        }
        return dp[sum];
    }
};

int main() {
    Solution *solution = new Solution();
    vector<int> nums = {1, 5, 11, 5};
    if(solution->canPartition(nums))
        cout << "Can Partition" << endl;
    else cout << "Cannot partition" << endl;
}