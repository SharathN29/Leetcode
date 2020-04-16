// https://leetcode.com/problems/longest-continuous-increasing-subsequence/

#include <iosttream>
#include <vector>

using namespace std;

int findLengthOfLCIS(vector<int>& nums) {
    int len = nums.size();
    int maxLen = INT_MIN; 
    vector<int> dp(len,0);
    if(len == 0) return 0;
    dp[0] = maxLen = 1;
    for(int i = 1; i < len; i++) {
        dp[i] = nums[i-1] < nums[i] ? dp[i-1] + 1 : 1; 
        if(dp[i] > maxLen)
            maxLen = dp[i];
    }
    return maxLen;
}

int main() {
	vector<int> nums = {1,3,5,4,7};
	int res = findLengthOfLCIS(nums);
	cout << "Longest Continuous Increasing Subsequence : " << res << endl;
}