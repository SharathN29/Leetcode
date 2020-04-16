// https://leetcode.com/problems/single-number/

#include <iostream>
#include <bitset>
#include <unordered_map>
#include <vector>

using namespace std; 

// int singleNumber(vector<int>& nums) {
//     unordered_map<int, int> map;
//     for(int i : nums)
//         map[i]++;
//     for(auto it : map) 
//         if(it.second == 1)
//             return it.first;
// }

int singleNumber(vector<int>& nums) {
    int res = 0;
    for(int i : nums)
        res = res ^ i;
    return res;
}

int main() {
    vector<int> nums = {1,1,2,2,3,3,4,4,5};
    int singleNum = singleNumber(nums);
    cout << "Single Number : " << singleNum << endl;
}