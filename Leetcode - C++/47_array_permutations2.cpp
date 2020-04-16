// https://leetcode.com/problems/permutations-ii/

#include <iostream>
#include <vector>

using namespace std;

void backtrack(vector<vector<int>>& res, vector<int> tempList, vector<int>& nums, vector<bool>& used) {
    if(tempList.size() == nums.size()){
        res.push_back(tempList);
    } else {
        for(int i = 0; i < nums.size(); i++) {
            if(used[i] || i > 0 && nums[i] == nums[i-1] && !used[i-1]) continue;
            used[i] = true;
            tempList.push_back(nums[i]);
            backtrack(res, tempList, nums, used);
            used[i] = false; 
            tempList.pop_back();
        }
    }
}


vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> res; 
    vector<bool> used(nums.size());
    sort(nums.begin(), nums.end());
    backtrack(res, {}, nums, used);
    return res;
}

int main() {
    vector<int> nums = {1,1,2};
    vector<vector<int>> res = permuteUnique(nums);
    for(int i = 0; i < res.size(); i++) {
        for(int j = 0; j < res[i].size(); j++) { 
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}