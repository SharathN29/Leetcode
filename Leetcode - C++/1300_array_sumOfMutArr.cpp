// https://leetcode.com/problems/sum-of-mutated-array-closest-to-target/

#include <iostream>
#include <vector>

using namespace std;

int findBestValue(vector<int>& arr, int target) {
    int l, r, mid, sum = 0, m = -1; 
    sum = accumulate(arr.begin(), arr.end(), 0);
    m = *max_element(arr.begin(), arr.end());

    if(sum == target) return m;

    for(l = 1, r = m; l < r;) {
        mid = (l + r) / 2;
        sum = 0;
        for(int n : arr) 
            sum += n > mid ? mid : n;
        if(sum >= target) r = mid; 
        else l = mid+1; 
    }

    int sum1 = 0, sum2 = 0;
    for(int n : arr) {
        sum1 += n > l ? l : n;
        sum2 += n > l-1 ? l-1 : n;
    }

    return (abs(sum2-target) <= abs(sum1-target)) ? l-1 : l;
}

int main() {
	vector<int> arr = {2,3,5}; 
	int target = 10; 
	int res = findBestValue(arr, target);
	cout << "Result : " << res << endl;
}