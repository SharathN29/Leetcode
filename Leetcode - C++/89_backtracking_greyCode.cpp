// https://leetcode.com/problems/gray-code/ 

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        bitset<32> bits;
        vector<int> res; 
        utils(bits, res, n);
        return res; 
    }

    void utils(bitset<32>& bits, vector<int>& res, int k ) {
        if(k == 0) res.push_back(bits.u_long());
        else {
            utils(bits, res, k-1);
            bits.flip(k-1);
            utils(bits, res, k-1);
        }
    }
};

int main() {
    Solution *solution = new Solution();
    int n = 2;
    vector<int> res = solution->grayCode(n);
    for(int n : res) 
        cout << n << " ";
    cout << endl;
}