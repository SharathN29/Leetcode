#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<vector<int>> graph; 

bool canFinish(int numCourses, vector<vector<int>>& prerequisites){
    graph g = buildGraph(numCourses, prerequisites);
    vector<int> degrees = computeIndegrees(g);
    for(int i = 0; i < numCourses; i++) {
        int j = 0;
        for(; j < numCourses; j++) {
            if(!degrees[j]) {
                break;
            }
        }
        if(j == numCourses) {
            return false; 
        }
        degrees[j]--;
        for(int v : g[j]) {
            degrees[v]--;
        }
    }
    return true;
}

graph buildGraph(int numCourses, vector<vector<int>>& prerequisites) {
    graph g(numCourses);
    for(auto p : prerequisites) {
        g[p[1]].push_back(p[0]);
    }
    return g;
}

vector<int> computeIndegrees(graph& g) {
    vector<int> degrees(g.size(), 0);
    for(auto adj : g) {
        for(int v : adj) {
            degrees[v]++;
        }
    }
    return degrees;
}

int main(){
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1,0},{0,1}};
    if(canFinish(numCourses, prerequisites))
        cout << "Can Finish the courses" << endl;
    else cout << "Wont be able to finish the courses" << endl;
}