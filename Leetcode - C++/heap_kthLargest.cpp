#include <iostream>
#include <vector>
#include <queue>

using namespace std;

priority_queue<int,vector<int>,greater<int>> pq; 
int K;

KthLargest(int k, vector<int>& nums) {
	K = k;
	for(int n : nums)
		add(n);
}

int add(int val) {
    if(pq.size() < K || val > pq.top())
    	pq.push(val);
    if(pq.size() > K)
    	pq.pop();
    return pq.top();
}