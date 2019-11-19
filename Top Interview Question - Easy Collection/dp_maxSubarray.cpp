#include <iostream>
#include <vector>

using namespace std;

int maxSubArray(vector<int>& nums) {
    int res = nums[0];
    for(int i = 1; i < nums.size(); i++){
        nums[i] = max(nums[i], nums[i-1]+nums[i]);
        if(nums[i] > res)
            res = nums[i];
    }
    return res; 
}

int main() {
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    int res = maxSubArray(nums);
    cout<<"Maximum subarray sum is " << res << endl;
}