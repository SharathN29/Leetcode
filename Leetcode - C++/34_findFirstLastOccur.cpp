// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
// Time : O(log n), Space : O(1)

#include <iostream>
#include <vector>

using namespace std; 

vector<int> searchRange(vector<int>& nums, int target) {
  if(nums.size() == 0)
    return {-1,-1};
  int i = 0, j = nums.size()-1;
  vector<int> res(2,-1);
  
  while(i < j) {
    int mid = (i+j)/2;
    if(nums[mid] < target) i = mid+1;
    else j = mid;
  }
  if(nums[i] != target) return res;
  else res[0]= i;
  
  j = nums.size()-1;
  while(i < j) {
    int mid = ((i+j)/2)+1;
    if(nums[mid] > target) j = mid-1;
    else i = mid;
  }
  res[1] = j;
  return res;
}

int main() {
	vector<int> nums = {5,7,7,8,8,10};
	int target = 8;

	vector<int> res = searchRange(nums, target);
	for(int i : res) 
		cout << i << " ";
	cout << endl;
}