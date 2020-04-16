// https://leetcode.com/problems/median-of-two-sorted-arrays/

#include <iostream>
#include <vector>

using namespace std; 

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	if(nums1.size() > nums2.size()) {
		return findMedianSortedArrays(nums2, nums1); 
	}

	int x = nums1.size(), y = nums2.size();
	int low = 0, high = x; 
	while(low <= high) {
		int partitionX = (x+y)/2, partitionY = (x+y+1)/2 - partitionX;
		int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX-1];
		int minRightX = (partitionX == x) ? INT_MAX : nums1[partitionX];
		int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY-1];
		int minRightY = (partitionY == y) ? INT_MAX : nums2[partitionY];

		if(maxLeftX <= minRightY && maxLeftY <= minRightX) {
			if((x+y) % 2 == 0) {
				return ((double)max(maxLeftX, maxLeftY) + min(minRightX, minRightY) / 2); 
			} else {
				return ((double)max(maxLeftX, maxLeftY));
			}
		} else if(maxLeftY > minRightY) {
			high = partitionX-1;
		} else {
			low = partitionX+1;
		}
	}
}

int main() {
	vector<int> nums1 = {1,3,8,9,15};
	vector<int> nums2 = {7,11,19,21,25};
	double res = findMedianSortedArrays(nums1, nums2);
	cout << "Median : " << res << endl;
}