// https://leetcode.com/problems/subarray-sum-equals-k/
// Time : O(N), Space : O(n)

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int subarraySum(vector<int>& nums, int k) {
    int cumulativeSum = 0;
    map<int, int> m;
    int count = 0;
    m[0]++;

    for(int i = 0; i < nums.size(); i++) {
    	cumulativeSum += nums[i];
    	count += map[cumulativeSum-k];
    	m[cumulativeSum]++;
    }
    return count;
}

int main() {
	vector<int> nums = {1,1,1};
	int k = 2;
	int res = subarraySum(nums, k);
	cout << "No of subarrays : " << res << endl;
}