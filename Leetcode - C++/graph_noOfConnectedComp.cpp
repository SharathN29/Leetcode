#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int countComponents(int n, vector<vector<int>>& edges) {
	vector<bool> visited(n, false);
	vector<vector<int>> adjList(n, vector<int>(0));
	stack<int> dfs;

	int count = 0, ans = 0;

	for(edge : edges) {
		int from = edge[0];
		int to = edge[1];

		adjList[from].push_back(to);
		adjList[to].push_back(from);
	}

	for(int i = 0; i < n; i++) {
		if(!visited[i]) {
			ans++;
			dfs.push(i);

			while(!dfs.empty()) {
				int current = dfs.top(); 
				dfs.pop(); 

				visited[current] = true;
				for(int neighbour : adjList[current])
					if(!visited[neighbour]) dfs.push(neighbour);
			}
		}
	}
	return ans; 
}

int main() {
	int n = 5;
	vector<vector<int>> edges = {{0,1}, {1,2}, {3,4}};
	int components = countComponents(n, edges);
	cout << "Number of connected components : " << components << endl;
}