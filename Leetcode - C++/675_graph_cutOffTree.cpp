// https://leetcode.com/problems/cut-off-trees-for-golf-event/
// Time - O(M^2 * N^2), M -size of row, N- size of column

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        if(forest.empty() || forest[0].size() == 0) 
        return 0;

        int m = forest.size(), n = forest[0].size();
        vector<vector<int>> trees;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(forest[i][j] > 1) {
                    trees.push_back({forest[i][j], i, j});
                }
            }
        }

        sort(trees.begin(), trees.end());
        int ans = 0;

        for(int i = 0, row = 0, col = 0; i < trees.size(); i++) {
            int step = nextStep(forest, row, col, trees[i][1], trees[i][2]);
            if(step == -1) return -1;
            ans += step; 
            row = trees[i][1];
            col = trees[i][2];
        }
        return ans;
    }

private: 
    int nextStep(vector<vector<int>>& forest, int sr, int sc, int er, int ec) {
        if(sr == er && sc == ec) return 0;
        int m = forest.size(), n = forest[0].size();
        queue<pair<int, int>> q; 
        q.push({sr,sc});
        vector<vector<int>> visited(m, vector<int>(n, 0));
        visited[sr][sc] = 1;
        int step = 0;
        vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

        while(!q.empty()) {
            step++;
            int size = q.size();
            for(int i = 0; i < size; i++) {
                int row = q.front().first, col = q.front().second;
                q.pop();
                for(vector<int> dir : dirs) {
                    int r = row + dir[0], c = col + dir[1];
                    if(r < 0 || r >= m || c < 0 || c >= n || visited[r][c] == 1 || forest[r][c] == 0) continue; 
                    if(r == er && c == ec) return step;
                    visited[r][c] = 1;
                    q.push({r,c});
                }
            }
        }
        return -1;
    }
};

int main() {
    Solution *solution = new Solution();
    vector<vector<int>> forest = {{1,2,3},{0,0,4},{7,6,5}};
    cout << "Min Steps : " << solution->cutOffTree(forest) << endl;
}