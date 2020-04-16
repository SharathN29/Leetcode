// https://leetcode.com/problems/maximum-length-of-pair-chain/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[1] < b[1]; 
    }

public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), cmp);
        int count = 0;
        vector<int>& pair = pairs[0];
        for(int i = 0; i < pairs.size(); i++) {
            if(i == 0 || pairs[i][0] > pair[1]) {
                count++;
                pair = pairs[i];
            }
        }
        return count;
    }
};

int main() {
    Solution *solution = new Solution();
    vector<vector<int>> pairs = {{1,2},{2,3},{3,4}};
    int maxLength = solution->findLongestChain(pairs);
    cout << "Max Length : " << maxLength << endl;
}