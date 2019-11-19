#include <iostream>
#include <vector>

using namespace std;

int singleNumber(vector<int>& nums) {
    int a = 0;
    for(int i = 0; i < nums.size(); i++){
        a ^= nums[i];
        cout<<a<<endl;
    }
    return a;
}

int main() {
    vector<int> nums = {1,2,2,3,3,4,4};
    int res = singleNumber(nums);
    cout<<"The single element in the array is " << res << endl;
}

