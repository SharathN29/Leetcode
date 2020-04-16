// https://leetcode.com/problems/contains-duplicate-ii/

#include <iostream>
#include <vector>
#include <unordered_map> 

using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, int> map;
    for(int i = 0; i < nums.size(); i++) {
        if(map.find(nums[i]) != map.end() && i - map[nums[i]] <= k)
            return true;
        map[nums[i]] = i;
    }
    return false;
}

int main() {
    vector<int> nums = {1,2,3,1};
    int k = 3;
    if(containsNearbyDuplicate(nums, k))
        cout << "Contains" << endl;
    else cout << "Does not contain" << endl;
}