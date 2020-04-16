// https://leetcode.com/problems/next-greater-element-i/
// Time - O(N), Space - O(N)

#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        unordered_map<int, int> map;
        for(int i = 0; i < nums2.size(); i++) {
            while(!s.empty() && s.top() < nums2[i]) {
                map[s.top()] = nums2[i];
                s.pop();
            }
            s.push(nums2[i]);
        }
        for(int i = 0; i < nums1.size(); i++) {
            if(map.find(nums1[i]) != map.end())
                nums1[i] = map[nums1[i]];
            else nums1[i] = -1;
        }
        return nums1;
    }
};

int main() {
    Solution *sol = new Solution();
    vector<int> nums1 = {4,1,2}, nums2 = {1,3,4,2};
    vector<int> res = sol->nextGreaterElement(nums1, nums2);
    for(int r : res)
        cout << r << " ";
    cout << endl;
}

