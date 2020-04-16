// https://leetcode.com/problems/trapping-rain-water/

#include <iostream>
#include <vector>

using namespace std;

int trap(vector<int>& height) {
	int left = 0, right = height.size()-1; 
	int res = 0;
	int maxleft = 0, maxright = 0;

	while(left <= right) {
		if(height[left] <= height[right]) {
			if(height[left] >= maxleft) maxleft = height[left];
			else res += maxleft - height[left];
			left++;
		} else {
			if(height[right] >= maxright) maxright = height[right];
			else res += maxright - height[right];
			right--;
		}
	} 
	return res;
}

int main() {
	vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
	int amount = trap(height);
	cout << "Amount of water trapped : " << height << endl;
}