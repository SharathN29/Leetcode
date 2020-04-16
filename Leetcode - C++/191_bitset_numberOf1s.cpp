//https://leetcode.com/problems/number-of-1-bits/

#include <iostream>

using namespace std;

int hammingWeight(uint32_t n) {
	int res = 0;
	while(n) {
		n = n & (n-1);
		res++;
	}
	return res;
}

int main() {
	uint32_t n = 12;
	int res = hammingWeight(n);
	cout << "Hamming Weight : " << res << endl;
}