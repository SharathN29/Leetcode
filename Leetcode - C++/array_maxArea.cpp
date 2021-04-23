#include <iostream>
#include <vector>

using namespace std;

int AreaOfIsland(vector<vector<int>>& grid, int i, int j) {
    if(i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && grid[i][j] == 1) {
        grid[i][j] = 0;
        return 1 + AreaOfIsland(grid, i-1, j) + AreaOfIsland(grid, i+1, j) + AreaOfIsland(grid, i, j-1) + AreaOfIsland(grid, i, j+1);
    }
    return 0;
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
    int max_area = 0;
    for(int i = 0; i < grid.size(); i++)
        for(int j = 0; j < grid[0].size(); j++)
            if(grid[i][j] == 1)
                max_area = max(max_area, AreaOfIsland(grid, i, j));
    return max_area;
}

int main () { 
    vector<vector<int>> grid = {{0,0,1,0,0,0,0,1,0,0,0,0,0},
                                {0,0,0,0,0,0,0,1,1,1,0,0,0},
                                {0,1,1,0,1,0,0,0,0,0,0,0,0},
                                {0,1,0,0,1,1,0,0,1,0,1,0,0},
                                {0,1,0,0,1,1,0,0,1,1,1,0,0},
                                {0,0,0,0,0,0,0,0,0,0,1,0,0},
                                {0,0,0,0,0,0,0,1,1,1,0,0,0},
                                {0,0,0,0,0,0,0,1,1,0,0,0,0}};
    
    cout << "The maximum area of the island is " << maxAreaOfIsland(grid) << endl;
}