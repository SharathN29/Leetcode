// https://leetcode.com/problems/coin-change/
// Time : O(S*N), S is the amount and n is the number of coings 
// Space : O(S)

#include <iostream>
#include <vector>

using namespace std; 

int coinChange(vector<int>& coins, int amount) {
	sort(coins.begin(), coins.end());
	vector<int> dp(amount+1, amount+1);
	dp[0] = 0;
	for(int i = 1; i <= amount; i++) {
		for(int j = 0; j < coins.size(); j++) {
			if(coins[j] <= i) {
				dp[i] = min(dp[i], 1+dp[i-coins[j]]);
			} else {
				break;
			}
		}
	}
	return dp[amount] > amount ? -1 : dp[amount];
}

int main() {
	vector<int> coins = {1,2,5};
	int amount = 11;
	int numCoins = coinChange(coins, amount);
	cout << "Num of coins" << numCoins << endl;
}