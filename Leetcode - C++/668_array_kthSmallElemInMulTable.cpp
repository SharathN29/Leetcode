// https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/

#include <iostream>
#include <vector>

using namespace std; 

int findKthNumber(int m, int n, int k) {
	int low = 1, high = m*n;
	while(low < high) {
		int mid = low + (high-low) / 2;
		int count = 0, j = m; 
		for(int i = 1; i <= n; i++) {
			while(j >= 1 && i*j > mid) j--; 
			count += (j);
		}
		if(count < k) low = mid+1;
		else high = mid;
	} 
	return low;
}

int main() {
	int m = 2, n = 6, k = 15; 
	int kthNumber = findKthNumber(m,n,k);
	cout << "Kth number is : " << kthNumber << endl;
}