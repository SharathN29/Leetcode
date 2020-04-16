#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void wallsAndGates(vector<vector<int>>& rooms) {
    int row = rooms.size();
    if(!row) return;
    int col = rooms[0].size(); 

    queue<pair<int, int>> canReach;
    vector<pair<int, int>> dirs = {{1,0}, {0,1}, {-1,0}, {0,-1}};

    for(int i = 0; i < row; i++) {
    	for(int j = 0; j < col; j++) {
    		if(rooms[i][j] == 0)
    			canReach.emplace(i,j);
    	}
    }

    while(!canReach.empty()) {
    	int r = canReach.front().first, c = canReach.front().second;
    	canReach.pop();
    	for(auto dir : dirs) {
    		int x = r + dir.first, y = c + dir.second;
    		if(x < 0 || x >= row || y < 0 || y >= col || rooms[x][y] <= rooms[r][c] + 1)
    			continue;
    		rooms[x][y] = rooms[r][c] + 1;
    		canReach.emplace(x,y);
    	}
    }
}

int main() {
	vector<vector<int>> rooms = {{}}
}