#include <iostream>
#include <vector> 

using namespace std; 

vector<int> merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    for(int i = m - 1, j = n - 1, k = m + n - 1; j>=0;)
        nums1[k--] = (i >= 0 && nums1[i] > nums2[j]) ? nums1[i--] : nums2[j--];
    return nums1;
}

int main() {
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    int m = 3; 
    vector<int> nums2 = {2, 5, 6};
    int n = 3;
    vector<int> res = merge(nums1, m, nums2, n);
    for(int i = 0; i < res.size(); i++)
        cout<< res[i] << " ";
    cout<<"\n";
}