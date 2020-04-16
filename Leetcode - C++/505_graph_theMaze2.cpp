// https://leetcode.com/problems/the-maze-ii/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    vector<vector<int>> dirs_ = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& dest) {
        const int m = maze.size(), n = maze[0].size();
        if (m == 0 || n == 0) return -1;
        
        vector<vector<int>> dist(m, vector<int>(n, -1));
        queue<pair<int,int>> q;
        q.push({start[0], start[1]});
        dist[start[0]][start[1]] = 0;
        
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            
            for (const auto& d : dirs_) {
                int x = cur.first, y = cur.second;
                int cur_dist = dist[x][y];
                while (x+d[0] >= 0 && x+d[0] < m && y+d[1] >= 0 && y+d[1] < n && !maze[x+d[0]][y+d[1]]) {
                    x += d[0]; y += d[1];
                    ++cur_dist;
                }
                // first time visit or we have shorter distance solution
                if (dist[x][y] == -1 || cur_dist < dist[x][y]) {
                    dist[x][y] = cur_dist;
                    q.push({x, y});
                }
            }
        }
        return dist[dest[0]][dest[1]];        
    }
};

int main() {
    Solution *sol = new Solution();
    vector<vector<int>> maze = {{0,0,1,0,0},{0,0,0,0,0},{0,0,0,1,0},{1,1,0,1,1},{0,0,0,0,0}};
    vector<int> start = {0,4};
    vector<int> destination = {3,2};
    int dist = sol->shortestDistance(maze, start, destination);
    cout << "Shortest Distance " << dist << endl;
}