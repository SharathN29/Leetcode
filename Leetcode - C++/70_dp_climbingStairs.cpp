//https://leetcode.com/problems/climbing-stairs/

#include <iostream>
#include <vector>

using namespace std;

int climbStairs(int n) {
    vector<int> dp(n+1);
    dp[1] = 1;
    dp[2] = 2; 

    for(int i = 3; i <= n; i++)
    	dp[i] = dp[i-1] + dp[i-2];

    return dp[n]; 
}

int main() {
	int n = 1; 
	int ways = climbStairs(n);
	cout << "Number of ways " << ways << endl;
}