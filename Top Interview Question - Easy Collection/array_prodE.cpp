#include <iostream>
#include <vector>

using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    int size = nums.size(), left = 1, right = 1;
    vector<int> res(size, 1); 

    for(int i = 1; i < size; i++) {
        left *= nums[i-1];
        res[i] *= left;
    }

    for(int j = size - 2; j >= 0; j--) {
        right *= nums[j+1];
        res[j] *= right;
    }

    return res;
}

int main() {
    vector<int> nums = {1, 2, 3, 4};
    vector<int> res = productExceptSelf(nums);
    for(auto s : res)
        cout << s << " "; 
    cout<<endl;
}