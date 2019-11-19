#include <iostream>
#include <vector> 

using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
    int i = 0, j = nums.size() - 1;
    vector<int> res(2, -1);

    while(i < j) {
        int mid = (i + j) / 2;
        if(nums[mid] < target) i = mid + 1;
        else j = mid;
    }
    if(nums[i] != target) return res;
    else res[0] = i;

    j = nums.size() - 1;
    while(i < j) {
        int mid = (i + j) / 2 + 1; 
        if(nums[mid] > target) j = mid - 1;
        else i = mid;
    }
    res[1] = j;
    return res;
}

int main() {
    vector<int> nums = {6,8,8,8,8,8,8,8,8,8,8,8,8,8,6};
    int target = 8;
    vector<int> res = searchRange(nums, target);
    cout << "Element " << target << " is in the range "; 
    for(auto e : res)
        cout << e << " ";
    cout << endl;
}