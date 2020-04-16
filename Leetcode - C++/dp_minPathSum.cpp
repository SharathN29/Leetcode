#include <iostream>
#include <vector>

using namespace std; 

int minPathSum(vector<vector<int>>& grid) {
	int r = grid.size(), c = grid[0].size();
	vector<vector<int>> dp(r, vector<int>(c, grid[0][0]));

	for(int i = 1; i < r; i++) 
		dp[i][0] = dp[i-1][0] + grid[i][0];

	for(int j = 1; j < c; j++)
		dp[0][j] = dp[0][j-1] + grid[0][j];

	for(int i = 1; i < r; i++) {
		for(int j = 1; j < c; j++) {
			dp[i][j] = min(dp[i-1][j] , dp[i][j-1]) + grid[i][j];
		}
	}

	return dp[r-1][c-1];
}

int main() {
	vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};
	int minPath = minPath(grid);
}