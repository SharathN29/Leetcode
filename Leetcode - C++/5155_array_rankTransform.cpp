// https://leetcode.com/contest/biweekly-contest-18/problems/rank-transform-of-an-array/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int, vector<int>> m;
        for(int i = 0; i < arr.size(); i++) {
            m[arr[i]].push_back(i);
        }

        int rank = 1;
        for(auto it : m) {
            while(it.second.size()) {
                arr[it.second.back()] = rank;
                it.second.pop_back();
            }
            rank++;
        }
        return arr;
    }
};

int main() {
    Solution *sol = new Solution();
    vector<int> arr = {40,10,20,30};
    vector<int> res = sol->arrayRankTransform(arr);
    for(int r : res)
        cout << r << " ";
    cout << endl;
}