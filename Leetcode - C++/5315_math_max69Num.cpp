// https://leetcode.com/contest/weekly-contest-172/problems/maximum-69-number/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maximum69Number (int num) {
        string nums = to_string(num);
        for(int i = 0; i < nums.length(); i++) {
            if(nums[i] == '6') {
                nums[i] = '9';
                return stoi(nums);
            } else continue;
        }
        return num;
    }
};

int main() {
    Solution *sol = new Solution();
    int num = 9669;
    int res = sol->maximum69Number(num);
    cout << "Result : " << res << endl; 
}