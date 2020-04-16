// https://leetcode.com/problems/product-of-array-except-self/

#include <iostream>
#include <vector>

using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    int size = nums.size(), left = 1, right = 1;
    vector<int> res(size, 1);

    for(int i = 1; i < size; i++){
    	left *= nums[i-1];
    	res[i] *= left;
    }

    for(int i = size-2; i >= 0; i--){
    	right *= nums[i+1];
    	res[i] *= right;
    }
    return nums;
}

int main() {
	vector<int> nums = {1,2,3,4};
	vector<int> res = productExceptSelf(nums);
	for(int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	cout << endl;
}