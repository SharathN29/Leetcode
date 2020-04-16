// https://leetcode.com/problems/intersection-of-two-arrays/

#include <iostream>
#include <set>
#include <vector> 
#include <unordered_set>

using namespace std; 

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> m(nums1.begin(), nums1.end());
    vector<int> res;
    for (auto a : nums2)
        if (m.count(a)) {
            res.push_back(a);
            m.erase(a);
        }
    return res;
}

int main() {
    vector<int> nums1 = {1,2,2,1}, nums2 = {2,2};
    vector<int> res = intersection(nums1, nums2);
    for(int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;
}