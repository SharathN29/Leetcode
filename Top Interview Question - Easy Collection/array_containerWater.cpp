#include <iostream>
#include <vector>

using namespace std;

int maxArea(vector<int>& height) {
    int maxArea = 0, l = 0, r = height.size() - 1;
    while(l < r) {
        maxArea = max(maxArea, min(height[l], height[r])*(r-l));
        if(height[l] < height[r]) l++;
        else r--;
    }
    return maxArea;
}

int main() {
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    int res = maxArea(height);
    cout << "Maximum water that could be stored is " << res << endl;
}