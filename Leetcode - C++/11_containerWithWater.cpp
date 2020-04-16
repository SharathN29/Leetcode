// https://leetcode.com/problems/container-with-most-water/

#include <iostream>
#include <vector>

using namespace std; 

int maxArea(vector<int>& height) {
    int i = 0, j = height.size()-1, maxarea = 0;
    while(i<j){
    	maxarea = max(maxarea, min(height[i], height[j])*(j-i));
    	if(height[i] < height[j])
    		i++;
    	else j--;
    }
    return maxarea;
}

int main() {
	vector<int> height = {1,8,6,2,5,4,8,3,7};
	int area = maxArea(height);
	cout << "Max Area : " << area << endl;
}