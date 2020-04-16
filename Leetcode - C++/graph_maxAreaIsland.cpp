#include <iostream>
#include <vector>

using namespace std;

int area(int r, int c, vector<vector<int>>& grid, vector<vector<bool>>& seen){
    if(r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || seen[r][c] || grid[r][c] == 0)
        return 0;
    seen[r][c] = true;
    return (1+area(r-1, c, grid, seen)+area(r+1, c, grid, seen)+area(r, c-1, grid, seen)+area(r, c+1, grid, seen));
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
    int nr = grid.size();
    if(!nr) return 0;
    int nc = grid[0].size();
    vector<vector<bool>> seen(nr, vector<bool>(nc,false));
    int maxArea = 0;

    for(int r = 0; r < nr; r++) {
        for(int c = 0; c < nc; c++) {
            maxArea = max(maxArea, area(r,c, grid, seen));
        }
    }
    return maxArea;
}

int main() {
	vector<vector<int>> grid = {{0,0,1,0,0,0,0,1,0,0,0,0,0},
								{0,0,0,0,0,0,0,1,1,1,0,0,0},
								{0,1,1,0,1,0,0,0,0,0,0,0,0},
								{0,1,0,0,1,1,0,0,1,0,1,0,0},
								{0,1,0,0,1,1,0,0,1,1,1,0,0},
								{0,0,0,0,0,0,0,0,0,0,1,0,0},
								{0,0,0,0,0,0,0,1,1,1,0,0,0},
								{0,0,0,0,0,0,0,1,1,0,0,0,0}};

	int res = maxAreaOfIsland(grid);
	cout << "Max Area : " << res << endl;
}