#include <iostream>
#include <vector>
#include <queue>

using namespace std; 

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
	vector<vector<int>> graph(numCourses, vector<int>());
	vector<int> indegree(numCourses, 0);
	int visitedNodesCount = 0;
	vector<int> result; 
	queue<int> nodes; 

	for(auto edge : prerequisites) {
		graph[edge[1]].push_back(edge[0]);
		indegree[edge[0]]++;
	}

	for(int nodeId = 0; nodeId < numCourses; nodeId++) {
		if(indegree[nodeId] == 0) {
			nodes.push(nodeId);
		}
	}

	while(!nodes.empty()) {
		visitedNodesCount++;
		int nodeId = nodes.front();
		nodes.pop(); 
		result.push_back(nodeId);
		for(auto neighberID : graph[nodeId]) {
			if(--indegree[neighberID] == 0) {
				nodes.push(neighberID);
			}
		}
	}
	return visitedNodesCount == numCourses ? result : vector<int>();
}

int main() {
	int numCourses = 4;
	vector<vector<int>> prerequisites = {{1,0},{2,0},{3,1},{3,2}};
	vector<int> result = findOrder(numCourses, prerequisites);
	for(int i = 0; i < result.size(); i++) 
		cout << result[i] << " ";
	cout << endl;
}