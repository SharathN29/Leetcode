// https://leetcode.com/contest/weekly-contest-172/problems/minimum-number-of-taps-to-open-to-water-a-garden/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        for(int i = 0; i < ranges.size(); i++) {
            int len = 0;
            while(len <= ranges) {
                len += 
            }

        }
    }
};

int main() {
    Solution *sol = new Solution();
    int n = 5;
    vector<int> ranges = {3,4,1,1,0,0};
    int min = sol->minTaps(n, ranges);
    cout << "Min Taps : " << min << endl;
}