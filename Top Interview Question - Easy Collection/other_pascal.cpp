#include <iostream>
#include <vector>

using namespace std; 

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> res(numRows);

    for(int i = 0; i < numRows; i++) {
        res[i].resize(i+1);
        res[i][0] = res[i][i] = 1;

        for(int j = 1; j < i; j++) 
            res[i][j] = res[i-1][j-1] + res[i-1][j];
    }
    return res; 
}

int main() {
    int numRows = 5;
    vector<vector<int>> res = generate(numRows);
    for(int i = 0; i < res.size(); i++)
        for(int j = 0; j < res[i].size(); j++)
            cout <<res[i][j] <<" ";
        cout << "\n";
    cout << "\n";
}