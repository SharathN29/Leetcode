// https://leetcode.com/problems/brick-wall/
// Time - O(N), where N represents number of bricks in the wall. 
// Space - O(M), where M represents the width of the wall. 

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int leastBricks(vector<vector<int>>& wall) {
	int res = INT_MIN; 
	unordered_map<int, int> map;

	for(auto i : wall) {
		int width = 0;
		for(int j = 0; j < i.size()-1; j++) {
			width += i[j];
			map[width]++;
		}
	}

	for(auto& i : map) {
		res = max(res, i.second);
	}

	if(res == INT_MIN)
		res = 0;
	return wall.size()-res; 
}

int main() {
	vector<vector<int>> wall = {{1,2,2,1},{3,1,2},{1,3,2},{2,4},{3,1,2},{1,3,1,1}};
	int least = leastBricks(wall);
	cout << "Least Bricks to go through : " << least << endl;
}