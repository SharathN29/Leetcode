// https://leetcode.com/problems/min-cost-climbing-stairs/

#include <iostream>
#include <vector>

using namespace std;

int minCostClimbingStairs(vector<int>& cost) {
	int n = cost.size();
    vector<int> dp(n,0);

    dp[0] = cost[0], dp[1] = cost[1];
    for(int i = 2; i < n; i++) {
    	dp[i] = min(dp[i-2], dp[i-1]) + cost[i];
    }

    return min(dp[i-1], dp[i-2]);
}

int main() {
	vector<int> cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
	int minCost = minCostClimbingStairs(cost);
	cout << "Minimum Cost : " << minCost << endl;
}