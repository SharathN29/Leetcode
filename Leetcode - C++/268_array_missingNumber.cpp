// https://leetcode.com/problems/missing-number/

#include <iostream>
#include <vector>
#include <numeric>

using namespace std; 

int missingNumber(vector<int>& nums) {
	int n = nums.size();
	int sum = (n * (n+1)) / 2;
	int actualSum = accumulate(nums.begin(), nums.end(), 0);
	return sum-actualSum;
}

int main() {
    vector<int> nums = {9,6,4,2,3,5,7,0,1};
    cout << "Missing Number : " << missingNumber(nums) << endl;
} 