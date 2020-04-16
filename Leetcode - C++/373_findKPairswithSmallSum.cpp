// https://leetcode.com/problems/find-k-pairs-with-smallest-sums/

#include <iostream> 
#include <vector> 
#include <queue> 

using namespace std;

struct compare {
	bool operator()(const pair<int,vector<int>>& a, const pair<int, vector<int>>& b) {
		return a.first > b.first;
	}
};

vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
	vector<vector<int>> res; 
	priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, compare> pq; 

	for(int i = 0; i < nums1.size(); i++) {
		for(int j = 0; j < nums2.size(); j++) {
			int sum = nums1[i] + nums2[j];
			vector<int> temp = {nums1[i],nums2[j]};
			pq.emplace(sum,temp);
		}
	}

	for(int i = 0; i < k; i++) {
		res.push_back(pq.top().second);
		pq.pop();
	}
	return res;
}

int main() {
	vector<int> nums1 = {1,7,11}, nums2 = {2,4,6};
	int k = 3; 

	vector<vector<int>> res = kSmallestPairs(nums1, nums2, k);
	for(int i = 0; i < res.size(); i++) {
		for(int j = 0; j < res[i].size(); j++) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}