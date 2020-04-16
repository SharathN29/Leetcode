// https://leetcode.com/problems/largest-rectangle-in-histogram/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int largestRectangleArea(vector<int>& heights) {
	int n = heights.size();
	stack<int> s;
	int maxArea = 0, top, area;
	int i = 0;
	while(i < heights.size()) {
		if(s.empty() || heights[s.top()] < heights[i])
			s.push(i++);
		else {
			top = s.top();
			s.pop();
			area = heights[top] * (s.empty() ? i : i-s.top()-1);
			if(maxArea < area)
				maxArea = area;
		}
	}

	while(!s.empty()) {
		top = s.top();
		s.pop();
		area = heights[top] * (s.empty() ? i : i-s.top()-1);
		if(maxArea < area)
			maxArea = area;
	}
	return maxArea;
}

int main() {
	vector<int> heights = {2,1,5,6,2,3};
	cout << "Largest Area : " << largestRectangleArea(heights) << endl;
}