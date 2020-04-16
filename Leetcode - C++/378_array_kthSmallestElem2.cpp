// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

#include <iostream>
#include <vector>

using namespace std; 

int kthSmallest(vector<vector<int>>& matrix, int k) {
	int n = matrix.size();
	int start = matrix[0][0], end = matrix[n-1][n-1];
	while(start < end) {
		int mid = start + (end - start) / 2;
		pair<int, int> smallLargePair = {matrix[0][0], matrix[n-1][n-1]};
		int count = countLessEqualTo(matrix, mid, smallLargePair);
		if(count == k) 
			return smallLargePair.first; 
		if(count < k) {
			start = smallLargePair.second;
		} else {
			end = smallLargePair.first;
		}
	}
	return start; 
}

int countLessEqualTo(vector<vector<int>>& matrix, int mid, pair<int, int>& smallLargePair) {
	int count = 0;
	int m = matrix.size(), row = n-1, col = 0;
	while(row >= 0 && col < n) {
		if(matrix[row][col] > mid) {
			smallLargePair.second = min(smallLargePair.second, matrix[row][col]);
			row--;
		} else {
			smallLargePair.first = max(smallLargePair.first, matrix[row][col]);
			count += row + 1;
			col++;
		}
	}
	return count;
}