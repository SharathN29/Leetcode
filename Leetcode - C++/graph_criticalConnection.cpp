#include <iostream>
#include <vector>

using namespace std; 

vector<vector<int>>g, ret; 
vector<int> visitedTime, lowTime; 
int timestamp = 0;

vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
	visitedTime = vector<int>(n);
	lowTime = vector<int>(n);
	g.resize(n);

	for(vector<int> c : connections) {
		int u = c[0], v = c[1];
		g[u].push_back(v);
		g[v].push_back(u);
	}

	dfs(0,-1);
	return ret;
}

void dfs(int curr, int prev) {
	if(visitedTime[curr] > 0) return; 
	visitedTime[curr] = lowTime[curr] = ++visitedTime;
	for(int next : g[curr]) {
		if(next == prev) continue; 
		dfs(next, curr);
		lowTime[curr] = min(lowTime[curr], lowTime[next]);
		if(lowTime[next] > visitedTime[curr])
			ret.push_back({curr, next});
	}
}

int main() {
	int n = 4; 
	vector<vector<int>> connections = {{0,1},{1,2},{2,0},{1,3}};
	vector<vector<int> res = criticalConnections(n, connections);
	for(int i = 0; i < res.size(); i++) {
		for(int j = 0; j < res[i].size(); j++) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}