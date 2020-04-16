#include <iostream>
#include <vector>

using namespace std;

int maximalSquare(vector<vector<char>>& matrix) {
    if(matrix.empty()) return 0;
    int nr = matrix.size(), nc = nr ? matrix[0].size() : 0;
    int size = 0;
    vector<vector<int>> dp(nr, vector<int>(nc, 0));
    for(int i = 0; i < nr; i++) {
    	for(int j = 0; j < nc; j++) {
    		if(!i || !j || matrix[i][j] == '0') {
    			dp[i][j] = matrix[i][j] - '0';
    		} else {
    			dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
    		}
    		size = max(size, dp[i][j]);
    	}
    }
    return size*size;
}

int main() {
	vector<vector<char>> matrix = {{'1','0','1','0','0'},
								   {'1','0','1','1','1'},
								   {'1','1','1','1','1'},
								   {'1','0','0','1','0'}};
	int res = maximalSquare(matrix);
	cout << "Maximum Square : " << res << endl;
}