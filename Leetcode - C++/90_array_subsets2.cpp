// https://leetcode.com/problems/subsets-ii/

#include <iostream>
#include <vector> 

using namespace std; 

void backtrack(vector<int>& nums, vector<int> tempList, vector<vector<int>>& res, int start) {
    res.push_back(tempList);
    for(int i = start; i < nums.size(); i++) {
        if(i > start && nums[i] == nums[i-1]) continue; 
        tempList.push_back(nums[i]);
        backtrack(nums, tempList, res, i+1);
        tempList.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> res; 
    sort(nums.begin(), nums.end());
    backtrack(nums, {}, res, 0);
    return res; 
}

int main() {
    vector<int> nums = {1,2,2};
    vector<vector<int>> res = subsetsWithDup(nums);
    for(int i = 0; i < res.size(); i++) {
        for(int j = 0; j < res[0].size(); j++) { 
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}