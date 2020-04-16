// https://leetcode.com/problems/intersection-of-two-arrays-ii/

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> intersect(vector<int>& nums1, vector<int>& nums2){
    unordered_map<int, int> map;
    vector<int> res;
    for(int n : nums1) 
        map[n]++;
    for(int n : nums2){
        if(map[n]-- > 0)
            res.push_back(n);
    }
    return res;
}

int main() {
    vector<int> nums1 = {4,9,5}, nums2 = {9,4,9,8,4};
    vector<int> res = intersect(nums1, nums2);

}