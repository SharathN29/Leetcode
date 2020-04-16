// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/

#include <iostream>
#include <vector>

using namespace std;

vector<int> findDisappearedNumbers(vector<int>& nums) {
	vector<int> res;
	int len = nums.size();
	for(int i = 0; i < len; i++){
		int m = abs(nums[i])-1;
		nums[m] = nums[m]>0 ? -nums[m] : nums[m];
	}

	for(int i = 0; i < len; i++){
		if(nums[i] > 0) res.push_back(i+1);
	}
	return res;
}

int main() {
    vector<int> nums = {4,3,2,7,8,2,3,1};
    vector<int> res = findDisappearedNumbers(nums);
    for(int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;
}