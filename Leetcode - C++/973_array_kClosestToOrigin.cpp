// https://leetcode.com/problems/k-closest-points-to-origin/

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std; 

struct compare {
    bool operator() (const pair<double,vector<int>>& a, const pair<double,vector<int>>& b) {
        return a.first > b.first;
    }
};

vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
    vector<vector<int>> res; 
    priority_queue<pair<double, vector<int>>, vector<pair<double, vector<int>>>, compare> pq;

    for(vector<int> p : points) {
        double dist = sqrt(p[0]*p[0] + p[1]*p[1]);
        pq.push(make_pair(dist, p));
    }

    for(int i = 0; i < K; i++) {
        res.push_back(pq.top().second);
        pq.pop();
    }
    return res;
}

int main() {
    vector<vector<int>> points= {{3,3}, {5,-1},{-2,4}};
    int K = 2;
    vector<vector<int>> res = kClosest(points, K);
}