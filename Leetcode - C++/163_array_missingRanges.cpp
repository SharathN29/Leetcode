// https://leetcode.com/problems/missing-ranges/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res; 
        int pre = lower - 1;
        for(int i = 0; i <= nums.size(); i++) {
            int curr = (i == nums.size() ? upper+1 : nums[i]);
            if(curr - pre >= 2) 
                res.push_back(getRange(pre+1, curr-1));
            pre = curr; 
        }
        return res; 
    }
    
    string getRange(int left, int right) {
        return left == right ? to_string(left) : to_string(left) + "->" + to_string(right);
    }
};

int main() {
    Solution *sol = new Solution();
    vector<int> nums = {0, 1, 3, 50, 75};
    int lower = 0, upper = 99;
    vector<string> res = sol->findMissingRanges(nums, lower, upper);
    for(string s : res)
        cout << s << " ";
    cout << endl;
}