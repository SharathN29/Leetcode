// https://leetcode.com/problems/the-maze/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size(), n = maze[0].size(), d[] = {0, 1, 0, -1, 0};
        queue<vector<int>> todo;
        todo.push(start);
        maze[start[0]][start[1]] = -1;
        while (!todo.empty()) {
            vector<int> p = todo.front();
            todo.pop();
            for (int i = 0; i < 4; i++) {
                int r = p[0], c = p[1];
                while (r + d[i] >= 0 && r + d[i] < m && c + d[i + 1] >= 0 && c + d[i + 1] < n && maze[r + d[i]][c + d[i + 1]] <= 0) {
                    r += d[i];
                    c += d[i + 1];
                }
                if (r == destination[0] && c == destination[1]) {
                    return true;
                }
                if (!maze[r][c]) {
                    maze[r][c] = -1;
                    todo.push({r, c});
                }
            }
        }
        return false;
    }
};

int main() {
    Solution *sol = new Solution();
    vector<vector<int>> maze = {{0,0,1,0,0},{0,0,0,0,0},{0,0,0,1,0},{1,1,0,1,1},{0,0,0,0,0}};
    vector<int> start = {0,4};
    vector<int> destination = {3,2};
    if(sol->hasPath(maze, start, destination))
        cout << "There is a path" << endl;
    else cout << "Impossible to reach" << endl;
}