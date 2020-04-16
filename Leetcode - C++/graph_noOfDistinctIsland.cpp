#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std; 

int numDistinctIslands(vector<vector<int>>& grid) {
    int m = grid.size();
    if(!m) return 0;
    int n = grid[0].size();
    unordered_set<string> islands;
    for(int i = 0; i < m; i++){
    	for(int j = 0; j < n; j++){
    		if(grid[i][j]) {
    			string island; 
    			dfs(grid, i, j, i, j, island);
    			islands.insert(island);
    		}
    	}
    }
    return islands.size();
}

void dfs(vector<vector<int>>& grid, int i, int j, int r, int c, string& island) {
	int m = grid.size(), n = grid[0].size();
	if(r >= 0 && r < m && c >= 0 && c < n && grid[r][c]) {
		grid[r][c] = 0;
		island += to_string(r-i) + to_string(c-j);
		dfs(grid, i, j, r-1, c, island);
		dfs(grid, i, j, r+1, c, island);
		dfs(grid, i, j, r, c-1, island);
		dfs(grid, i, j, r, c+1, island);
	}
}

int main() {
	vector<vector<int>> grid = {{1,1,0,0,0},{1,1,0,0,0},{0,0,0,1,1},{0,0,0,1,1}};
	int distinctIslands = numDistinctIslands(grid);
	cout << "Number of distinct islands : " << distinctIslands << endl; 
}