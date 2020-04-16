// https://leetcode.com/problems/counting-bits/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ret(num+1, 0);
		for(int i = 1; i <= num; i++) 
			ret[i] = ret[i&(i-1)] + 1;
		return ret;
    }
};

int main() {
	int num = 4;
	vector<int> res = countBits(num);
	for(int n : res)
		cout << n << " ";
	cout << endl;
}