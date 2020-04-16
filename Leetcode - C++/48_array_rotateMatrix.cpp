// https://leetcode.com/problems/rotate-image/

#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<vector<int>>& matrix) {
    reverse(matrix.begin(), matrix.end());
    for(int i = 0; i < matrix.size(); i++)
    	for(int j = i; j < matrix[i].size(); j++)
    		swap(matrix[i][j], matrix[j][i]);
}

int main() {
	vector<vector<int>> nums = {{1,2,3}, {4,5,6}, {7,8,9}};
	rotate(nums);
	for(int i = 0; i < nums.size(); i++)
		for(int j = 0; j < nums[0].size(); j++)
			cout << nums[i][j] << " ";
		cout << endl;
	cout << endl;
}