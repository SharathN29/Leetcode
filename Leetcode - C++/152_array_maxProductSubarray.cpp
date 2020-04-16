// https://leetcode.com/problems/maximum-product-subarray/

#include <iostream>
#include <vector>

using namespace std;

int maxProduct(vector<int> A) {
	int n = A.size(), res = A[0], l = 0, r = 0; 
	for(int i = 0; i < n; i++) {
		l = (l ? l : 1) * A[i]; 
		r = (r ? r : 1) * A[n-i-1];
		res = max(res, max(l,r));
	}
	return res;
}

int main() {
	vector<int> A = {2,3,-2,4};
	int max = maxProduct(A);
	cout << "Maximum subarray product : " << max << endl;
}