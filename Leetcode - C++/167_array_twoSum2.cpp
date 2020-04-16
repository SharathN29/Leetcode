// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
// Time - O(N), Space - O(N)

#include <iostream>
#include <vector>

using namespace std; 

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> map;
        vector<int> res;
        for(int i = 0; i < numbers.size(); i++) {
            int num = target - numbers[i];
            if(map.find(num) != map.end()) {
                res.push_back(map[num]);
                res.push_back(i+1);
                return res;
            }
            map[numbers[i]] = i+1;
        }
        return vector<int>();
    }
};

int main() {
    Solution *solution = new Solution();
    vector<int> numbers = {2,7,11,15};
    int target = 9;
    vector<int> res = solution->twoSum(numbers, target);
    for(int n : res)
        cout << n << " ";
    cout << endl;
}