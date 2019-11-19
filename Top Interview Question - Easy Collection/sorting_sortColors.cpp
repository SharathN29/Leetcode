#include <iostream>
#include <vector>

using namespace std;

void sortColors(vector<int>& nums) {
    int low = 0, mid = 0, high = nums.size()-1; 
    while(mid <= high) {
        if(nums[mid] == 0)
            swap(nums[mid++], nums[low++]);
        else if(nums[mid] == 1)
            mid++;
        else if(nums[mid] == 2)
            swap(nums[mid], nums[high--]);
    }
}

int main() {
    vector<int> nums = {1, 0, 2, 2, 1, 0};
    sortColors(nums);
    cout << "Sorted Colors : ";
    for(int i = 0; i < nums.size(); i++)
        cout << nums[i] << " ";
    cout << endl;
}
