// https://leetcode.com/problems/sliding-window-maximum/

#include <iostream>
#include <vector>

using namespace std; 

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res; 
        deque<int> d;
        int i = 0;
        while(i < nums.size()) {
            while(d.size() < k) {
                d.push_back(nums[i++]);
            }
            res.push_back(*max_element(d.begin(), d.end()));
            d.pop_front();
        }
        return res;
    }
};

int main() {
    Solution *solution = new Solution();
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int> res = solution->maxSlidingWindow(nums, k);
    cout << "Max Sliding window : ";
    for(int n : res) 
        cout << n << " ";
    cout << endl;  
}