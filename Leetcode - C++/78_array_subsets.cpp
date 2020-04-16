//https://leetcode.com/problems/subsets/
// Time : O(N*2^N), Space : O(2^N)

#include <iostream>
#include <vector>

using namespace std;

void backtrack(vector<vector<int>>& res, vector<int> tempList, vector<int>& nums, int start) {
    res.push_back(tempList);
    for(int i = start; i < nums.size(); i++) {
        tempList.push_back(nums[i]);
        backtrack(res, tempList, nums, i+1);
        tempList.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    backtrack(res, {}, nums, 0);
    return res; 
}

int main() {
    vector<int> nums = {1,2,3};
    vector<vector<int>> res = subsets(nums);

}