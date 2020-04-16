// https://leetcode.com/problems/permutations/

#include <iostream>
#include <vector>

using namespace std;

void backtrack(vector<vector<int>>& res, vector<int> tempList, vector<int>& nums){
    if(tempList.size() == nums.size()) {
        res.push_back(tempList);
    } else {
        for(int i = 0; i < nums.size(); i++) {
            if(find(tempList.begin(), tempList.end(), nums[i]) != tempList.end()) continue;
            tempList.push_back(nums[i]);
            backtrack(res, tempList, nums);
            tempList.pop_back();
        }
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res; 
    backtrack(res, {}, nums);
    return res; 
}

int main() {
    vector<int> nums = {1,2,3};
    vector<vector<int>> res = permute(nums);
    for(int i = 0; i < res.size(); i++) {
        for(int j = 0; j < res[0].size(); j++) { 
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}