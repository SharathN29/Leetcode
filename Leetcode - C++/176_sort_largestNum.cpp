// https://leetcode.com/problems/largest-number/
// time - O(nlogn), space - O(N)

#include <iostream>
#include <vector>
#include <string>

using namespace std; 

class Solution {
public: 
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [] (int a, int b){
            return to_string(a) + to_string(b) > to_string(b) + to_string(a);
        });
        string ans;
        for(int n : nums) 
            ans += to_string(n);
        return ans[0] == '0' ? "0" : ans;
    }
};

int main() {
    Solution *solution = new Solution();
    vector<int> nums = {3,30,34,5,9};
    string res = solution->largestNumber(nums);
    cout << "Largest Num : " << res << endl;
}