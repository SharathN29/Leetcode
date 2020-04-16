// https://leetcode.com/problems/set-mismatch/
// Time - O(N), Space - O(N)

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> countNums(nums.size(), 0);
        vector<int> res(2,-1);
        
        for(int n : nums) 
            countNums[n-1]++;
        
        for(int i = 0; i < countNums.size(); i++) {
            if(countNums[i] == 2)
                res[0] = i+1;
            if(countNums[i] == 0)
                res[1] = i+1;
        }
        return res;
    }
};

int main() {
    Solution *solution = new Solution();
    vector<int> nums = {1,2,2,4};
    vector<int> res = solution->findErrorNums(nums);
    for(int n : res) 
        cout << n << " ";
    cout << endl;
}