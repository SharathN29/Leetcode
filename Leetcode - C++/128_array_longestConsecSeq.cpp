// https://leetcode.com/problems/longest-consecutive-sequence/

#include <iostream>
#include <<vector>
#include <unordered_set> 

using namespace std;

// one posssible way to do is to sort the array which will take O(nlogn) time and then find the longest 
// consecuitive sequence in O(N) time. Which will be O(nlogn) in total. 

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> vals(nums.begin(), nums.end());
        int res = 1;
        for(int n : nums) {
            if(vals.find(n) == vals.end()) continue;
            vals.erase(n);
            int prev = n - 1, next = n + 1;
            while(vals.find(prev) != vals.end()) vals.erase(prev--);
            while(vals.find(next) != vals.end()) vals.erase(next++);
            res = max(res, next - prev - 1);
        }
        return res;
    }
};

int main(){ 
    Solution *solution = new Solution();
    vector<int> nums = {100,4,200,1,3,2};
    int length = solution->longestConsecutive(nums);
    cout << "Length : " << length << endl;
}