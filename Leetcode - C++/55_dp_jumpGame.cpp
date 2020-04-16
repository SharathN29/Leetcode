// https://leetcode.com/problems/jump-game/

#include <iostream> 
#include <vector>

using namespace std; 

bool canJump(vector<int>& nums) {
    int lastPos = nums.size()-1;
    for(int i = lastPos; i >= 0; i--){
        if(i+nums[i] > lastPos){
            lastPos = i;
        }
    }
    return lastPos == 0;
}

int main() {
    vector<int> nums = {2,3,1,1,4};
    if(canJump(nums))
        cout << "Can jump" << endl;
    else cout << "Can't jump" << endl;
}