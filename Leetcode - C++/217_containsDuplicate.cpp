// https://leetcode.com/problems/contains-duplicate/
// Time : O(N), SPace : O(N)

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std; 

// bool containsDuplicate(vector<int>& nums) {
//     unordered_map<int, int> map;
//     for(int n : nums)
//         map[n]++;
//     for(auto it : map)
//         if(it.second > 1)
//             return true;
//     return false; 
// }

bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> set;
    for(int n : nums){
        if(set.count(n) >= 1)
            return true;
        else set.insert(n);
    }
    return false;
}

int main() {
    vector<int> nums = {1,2,3,4,1};
    if(containsDuplicate(nums))
        cout << "Contains duplicate " << endl;
    else cout << "No duplicate elements" << endl;
}