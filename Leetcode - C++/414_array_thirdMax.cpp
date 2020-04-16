// https://leetcode.com/problems/third-maximum-number/
// time - O(N)

#include <iostream>
#include <vector>

using namespace std; 

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> three;
        for(int n : nums) {
            three.insert(n);
            if(three.size() > 3) 
                three.erase(three.begin())''
        }
        return three.size() == 3 ? *three.begin() : *three.rbegin();
    }
};

int main() {
    Solution *solution = new Solution();
    vector<int> nums = {3,2,1};
    cout << "Third Max : " << solution->thirdMax(nums) << endl;
}