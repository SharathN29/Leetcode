// https://leetcode.com/problems/two-sum-less-than-k/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std; 

int twoSumLessThanK(vector<int>& A, int K) {
    sort(A.begin(), A.end());
    int max = -1, i = 0, j = A.size()-1;
    while(i < j) {
    	int sum = A[i] + A[j];
    	if(sum < K) {
    		max = max(max, sum);
    		i++;
    	} else 
    		j--;
    }
    return max;
}

int main() {
	vector<int> A = {34,23,1,24,75,33,54,8};
	int K = 60;
	int sum = twoSumLessThanK(A, K);
	cout << "TwoSum less than " << K << " : " << sum << endl; 
}