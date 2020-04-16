// https://leetcode.com/problems/number-of-islands/
// Time - O(M*N), where M - no of rows, N - no of columns
// Space - worst case O(M*N)

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//Breadth First Implementation
int numIslandsBFS(vector<vector<char>>& grid) {
   int numOfIsland = 0;
   int nr = grid.size();
   int nc = grid[0].size();
   if(!nr) return 0;

   for(int r = 0; r < nr; r++){
      for(int c = 0; c < nc; c++){
         if(grid[r][c] == '1'){
            numOfIsland++;
            grid[r][c] = '0';
            queue<pair<int, int>> neighbors;
            neighbors.push({r,c});
            while(!neighbors.empty()){
               auto rc = neighbors.front();
               neighbors.pop();
               int row = rc.first, col = rc.second;
               if(row-1 >= 0 && grid[row-1][col] == '1'){
                  neighbors.push({row-1, col});
                  grid[row-1][col] = '0';
               }
               if(row+1 < nr && grid[row+1][col] == '1'){
                  neighbors.push({row+1, col});
                  grid[row+1][col] = '0';
               }
               if(col-1 >= 0 && grid[row][col-1] == '1'){
                  neighbors.push({row, col-1});
                  grid[row][col-1] = '0';
               }
               if(col+1 < nc && grid[row][col+1] == '1'){
                  neighbors.push({row, col+1});
                  grid[row][col+1] = '0';
               }
            }
         }
      }
   } 
   return numOfIsland;
}

void dfs(vector<vector<char>>& grid, int r, int c) {
   int nr = grid.size();
   int nc = grid[0].size();

   grid[r][c] = '0';
   if(r-1 >= 0 && grid[r-1][c] == '1') dfs(grid, r-1, c);
   if(r+1 < nr && grid[r+1][c] == '1') dfs(grid, r+1, c);
   if(c-1 >= 0 && grid[r][c-1] == '1') dfs(grid, r, c-1);
   if(c+1 < nc && grid[r][c+1] == '1') dfs(grid, r, c+1);
}

// Deapth First Traversal
int numIslands(vector<vector<char>>& grid){
   int nr = grid.size();
   if(!nr) return 0;
   int nc = grid[0].size();
   int numOfIsland = 0;

   for(int r = 0; r < nr; r++){
      for(int c = 0; c < nc; c++){
         if(grid[r][c] == '1'){
            numOfIsland++;
            dfs(grid, r, c);
         }
      }
   }
   return numOfIsland;
}

int main() {
   vector<vector<char>> grid = {{'1', '1', '1', '1', '0'}, 
                                {'1', '1', '0', '1', '0'}, 
                                {'1', '1', '0', '0', '0'}, 
                                {'0', '0' ,'0' ,'0' ,'0'}};
   int res = numIslandsBFS(grid);
   cout << "Number of Island : " << res << endl;

   int res2 = numIslands(grid);
   cout << "DFS : " << res << endl;
}