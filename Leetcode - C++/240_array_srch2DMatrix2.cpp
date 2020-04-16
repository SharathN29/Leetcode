// https://leetcode.com/problems/search-a-2d-matrix-ii/

#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    if(!m) return false;
    int n = matrix[0].size();

    int i = 0, j = n-1;

    while(i < m && j >= 0) {
    	if(matrix[i][j] == target) return true;
    	esle if(matrix[i][j] < target) i++;
    	else j--;
    }
    return false;
}

int main() {
	vector<vector<int>> matrix = {{1,   4,  7, 11, 15},
								  {2,   5,  8, 12, 19},
								  {3,   6,  9, 16, 22},
								  {10, 13, 14, 17, 24},
								  {18, 21, 23, 26, 30}
								};

	int target = 5;

	if(searchMatrix(matrix, target))
		cout << "Element Found" << endl;
	else cout << "Element not found" << endl;
}