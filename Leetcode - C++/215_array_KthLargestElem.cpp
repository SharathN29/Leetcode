// https://leetcode.com/problems/kth-largest-element-in-an-array/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int findKthLargest(vector<int>& nums, int k) {
	priority_queue<int> pq(nums.begin(), nums.end());
	for(int i = 0; i < k; i++)
		pq.pop();
	return pq.top();   
}

int main() {
	vector<int> nums = {3,2,1,5,6,4};
	int k = 2;
	int kthlar = findKthLargest(nums,k);
	cout << "Kth largest element : " << kthlar << endl;
}