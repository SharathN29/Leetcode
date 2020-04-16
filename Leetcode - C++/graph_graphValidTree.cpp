#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool hasCycle(vector<vector<int>>& neighbors, int kid, int parent, vector<bool>& visited) {
	if(visited[kid]) return true; 
	visited[kid] = true;
	for(auto n : neighbors[kid]) 
		if(n != parent && hasCycle(neighbors, n, kid, visited))
			return true;
		return false; 
}


bool validTree(int n, vector<vector<int>>& edges) {
    vector<vector<int>> neighbors(n);
    vector<bool> visited(n, false);
    for(auto edge : edges) {
    	neighbors[edge[0]].push_back(edge[1]);
    	neighbors[edge[1]].push_back(edge[0]);
    }
    if(hasCycle(neighbors, 0, -1, visited))
    	return false;
    for(bool v : visited)
    	if(!v) return false;
    return true;
}

int main() {
	int n = 5;
	vector<vector<int>> edges = {{0,1}, {0,2}, {0,3}, {1,4}};
	if(validTree(n ,edges))
		cout << "Valid Tree" << endl;
	else cout << "Not a valid tree " << endl; 
}