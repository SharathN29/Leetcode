#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int maximumMinimumPath(vector<vector<int>>& A) {
    int nr = A.size(), nc = nr ? A[0].size() : 0, maxScore = A[0][0];
    const vector<pair<int, int>> dirs = {{-1,0},{1,0},{0,1},{0,-1}};
    priority_queue<tuple<int, int, int>> pq;
    pq.emplace(A[0][0], 0, 0);
    A[0][0] = -1;
    while(!pq.empty()) {
        auto [a, i, j] = pq.top();
        pq.pop();
        maxScore = min(maxScore, a);
        if(i == nr - 1 && j == nc - 1)
            return maxScore;
        for(auto dir : dirs) {
            int newX = i + dir.first, newY = j + dir.second;
            if(newX >= 0 && newX < nr && newY >=0 && newY < nc && A[newX][newY] >= 0) {
                pq.emplace(A[newX][newY], newX, newY);
                A[newX][newY] = -1;
            }
        } 
    }
    return -1;
}

int main() {
    vector<vector<int>> A = {{3,4,6,3,4},{0,2,1,1,7},{8,8,3,2,7},{3,2,4,9,8},{4,1,2,0,0},{4,6,5,4,3}};
    int res = maximumMinimumPath(A);
    cout << "Result : " << res << endl;
}