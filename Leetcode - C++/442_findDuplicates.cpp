// https://leetcode.com/problems/find-all-duplicates-in-an-array/

#include <iostream>
#include <vector>

using namespace std;

vector<int> findDuplicates(vector<int>& nums) {
    int len = nums.size();
    vector<int> res;
    for(int i = 0; i < len; i++){
    	int m = abs(nums[i])-1;
    	if(nums[m] < 0)
    		res.push_back(m+1);
    	nums[m] = -nums[m];
    }
    return res;
}

int main() {
	vector<int> nums = {4,3,2,7,8,2,3,1};
	vector<int> res = findDuplicates(nums);
	for(int i = 0; i < res.size(0; i++)
		cout << res[i] << " ";
	cout << endl;
}