// https://leetcode.com/problems/search-a-2d-matrix/

#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
	int row = matrix.size();
	if(!row) return false;
	int col = matrix[0].size();

	int left = 0, right = row*col-1;
	int pivotIndex, pivotElem;

	while(left < right){
		pivotIndex = (left+right)/2;
		pivotElem = matrix[pivotIndex/col][pivotIndex%col];

		if(target == pivotElem) return true;
		else {
			if(target < pivotElem) right = pivotIndex-1;
			else left = pivotIndex+1;
		}
	}
	return false;
}

int main() {
	vector<vector<int>> matrix = {{1,   3,  5,  7},
								  {10, 11, 16, 20},
								  {23, 30, 34, 50}};
	int target = 3;
	if(searchMatrix(matrix, target))
		cout << "Element found" << endl;
	else cout << "Element not found" << endl;
}