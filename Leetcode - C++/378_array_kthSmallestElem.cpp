// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct compare{
	bool operator() (const pair<int, pair<int,int>>& a, const pair<int, pair<int,int>>& b) {
		return a.first > b.first;
	}
};


int kthSmallest(vector<vector<int>>& matrix, int k) {
	int n = matrix.size();
	priority_queue<pair<int,pair<int,int>>, vector<pair<int, pair<int,int>>>, compare> minHeap; 

	for(int i = 0; i < m; i++) {
		minHeap.push(make_pair(matrix[i][0], make_pair(i, 0)));
	}

	int count = 0, result = 0;

	while(!minHeap.empty()) {
		auto heapTop = minHeap.top();
		minHeap.pop();
		result = heapTop.first;
		if(++count == k) 
			break;
		heapTop.second.second++;
		if(n > heapTop.second.second) {
			heapTop.first = matrix[heapTop.second.first][heapTop.second.second];
			minHeap.push(heapTop);
		}
	}
	return result;
}

int main() {
	vector<vector<int>> matrix = {{1,5,9},{10,11,13},{12,13,15}};
	int k = 5;

	cout << "The " << k <<"th smallest element : " << kthSmallest(matrix, k) << endl;
}