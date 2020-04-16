// https://leetcode.com/problems/shortest-unsorted-continuous-subarray/

#include <iostream>
#include <vector>

using namespace std;

int findUnsortedSubarray(vector<int>& nums) {
    vector<int> sorted(nums);
    sort(sorted.begin(), sorted.end());
    int n = nums.size(), i = 0, j = n-1;
    while(i < n && nums[i] == sorted[i])
    	i++;
    while(j > i && nums[j] == sorted[j])
    	j--;
    return j-i+1;
}

int main() {
	vector<int> nums = {2, 6, 4, 8, 10, 9, 15};
	int length = findUnsortedSubarray(nums);
	cout << "Length of shortest subarray : " << length << endl;
}