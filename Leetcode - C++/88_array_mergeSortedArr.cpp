// https://leetcode.com/problems/merge-sorted-array/

#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    m--;
    n--;
    int p = m + n + 1;
    while ((n >= 0) && (m >= 0)){
        if (nums2[n] >= nums1[m]){
            nums1[p--] = nums2[n--];
        } else{
            nums1[p--] = nums1[m--];
        }
    }
    while (n >= 0){
        nums1[p--] = nums2[n];
        n--;
    }
}