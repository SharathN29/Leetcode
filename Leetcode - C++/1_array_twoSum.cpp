// https://leetcode.com/problems/two-sum/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> map;
    vector<int> res; 
    for(int i = 0; i < nums.size(); i++){
        int num = target - nums[i];
        if(map.find(num) != map.end()){
            res.push_back(map[num]);
            res.push_back(i);
            return res;
        }
        else 
            map[nums[i]] = i;
    }
    return res;
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 17;
    vector<int> res = twoSum(nums, target);
    for(int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;
}