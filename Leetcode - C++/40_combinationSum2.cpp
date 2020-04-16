// https://leetcode.com/problems/combination-sum-ii/

#include <iostream>
#include <vector>

using namespace std; 

void backtrack(vector<int>& candidates, vector<vector<int>>& res, vector<int> tempList, int remain, int start){
    if(remain < 0) return;
    else if(remain == 0) res.push_back(tempList);
    else {
        for(int i = start; i < candidates.size(); i++){
            if(i > start && candidates[i] == candidates[i-1]) continue; 
            tempList.push_back(candidates[i]);
            backtrack(candidates, res, tempList, remain-candidates[i], i+1);
            tempList.pop_back();
        }
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> res; 
    sort(candidates.begin(), candidates.end());
    backtrack(candidates, res, {}, target, 0);
    return res; 
}

int main() {
    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;
    vector<vector<int>> res = combinationSum2(candidates, target);
    for(int i = 0; i < res.size(); i++) {
        for(int j = 0; j < res[i].size(); j++) { 
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}