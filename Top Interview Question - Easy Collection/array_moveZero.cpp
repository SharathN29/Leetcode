#include <iostream>
#include <vector>

using namespace std; 

void moveZeroes(vector<int>& nums) {
    int j = 0;
    for(int i = 0; i < nums.size(); i++)
        if(nums[i] != 0)
            nums[j++] = nums[i];

    for(; j < nums.size(); j++)
        nums[j] = 0;

    cout<<"Elements of the vector after moving the zeroes to the end " << endl;
    for(int i = 0; i < nums.size(); i++)
        cout<<nums[i] << " ";
    cout<<"\n";
}

int main() {
    vector<int> nums = {0,2,3,0,44,0,1123,2};
    moveZeroes(nums);
}