// https://leetcode.com/problems/spiral-matrix-ii/

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generateMatrix(int size) {
    int m = size, n = size, u = 0, d = m-1, l = 0, r = n-1, p = 1;

    vector<vector<int>> matrix(size, vector<int>(size)); 

    while(u <= d && l <= r){
        for(int col = l; col <= r; col++) 
        	matrix[u][col] = p++;

        if(++u > d) break;

        for(int row = u; row <= d; row++)
            matrix[row][r] = p++;

        if(--r < l) break;

        for(int col = r; col >= l; col--) 
            matrix[d][col] = p++;

        if(--d < u) break;

        for(int row = d; row >= u; row--) 
            matrix[row][l] = p++;

        if(++l > r) break;
    }
    return matrix;
}

int main() {
	int n = 3;
	vector<vector<int>> matrix = generateMatrix(n);
}	