// https://leetcode.com/problems/4sum/
// Time - O(N^3)

#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res; 
        sort(nums.begin(), nums.end());
        if(nums.size() < 4) return res; 

        for(int i = 0; i < nums.size(); i++) {
            int target3 = target - nums[i];
            for(int j = i+1; j < nums.size(); j++) {
                int target2 = target3 - nums[j];
                int front = j+1, back = nums.size()-1;
                while(front < back) {
                    int sum = nums[front] + nums[back];
                    if(sum < target2) front++;
                    else if(sum > target2) back--;
                    else {
                        vector<int> quad(4,0);
                        quad[0] = nums[i];
                        quad[1] = nums[j];
                        quad[2] = nums[front];
                        quad[3] = nums[back];
                        res.push_back(quad);

                        while(front < back && nums[front] == quad[2]) front++;
                        while(front < back && nums[back] == quad[3]) back--;
                    }
                }
                while(j+1 < nums.size() && nums[j+1] == nums[j]) j++;
            }
            while(i+1 < nums.size() && nums[i+1] == nums[i]) i++;
        }
        return res;
    }
};

int main() {
    Solution *sol = new Solution();
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    vector<vector<int>> res = sol->fourSum(nums, target);
    for(int i = 0; i < res.size(); i++) {
        for(int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
