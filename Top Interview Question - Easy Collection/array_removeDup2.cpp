#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int removeDuplicates(vector<int>& nums) {
    int i = 0;
    for (int n : nums)
        if (i < 2 || n > nums[i-2])
            nums[i++] = n;
    return i;
}

int main() {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(3);
    int res = removeDuplicates(nums);
    cout<< "Length of array with atmost 2 duplicates " << res << endl;
}