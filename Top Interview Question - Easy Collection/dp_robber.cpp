#include <iostream>
#include <vector>

using namespace std;

int rob(vector<int>& nums) {
    int n = nums.size();
    if(n == 0) return 0;
    if(n == 1) return nums[0];
    if(n == 2) return max(nums[0], nums[1]);

    vector<int> f(n,0);
    f[0] = nums[0];
    f[1] = max(nums[0], nums[1]);

    for(int i = 2; i < n; i++)
        f[i] = max(nums[i]+f[i-2], f[i-1]);

    return f[n-1];
}

int main() {
    vector<int> nums = {2,7,9,3,1};
    int res = rob(nums);
    cout << "Maximum amount of money that I can rob without alerting the police " << res << endl;
}