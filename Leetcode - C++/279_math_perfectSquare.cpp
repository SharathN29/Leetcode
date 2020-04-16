// https://leetcode.com/problems/perfect-squares/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std; 

class Solution {
public:
    int numSquares(int n) {
        if(n == 0) return 0;
        vector<int> dp(n+1, 0);
        
        for(int i = 0; i <= n; i++) {
            dp[i] = i;
            for(int j = 2; j <= sqrt(i); j++) {
                dp[i] = min(dp[i], 1 + dp[i - j*j]);
            }
        }
        return dp[n];
    }
};

int main() {
    Solution *solution = new Solution();
    int n = 12;
    int res = solution->numSquares(n);
    cout << "Result : " << res << endl;
}