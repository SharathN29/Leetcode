#include <iostream>
#include <vector> 

using namespace std;

bool containsDuplicate(vector<int>& nums){
    if(nums.size() == 0) return false;
    if(nums.size() == 1) return false;
    sort(nums.begin(), nums.end());

    for(int i = 0; i < nums.size() - 1; i++){
        if(nums[i] == nums[i+1])
        return true;
        break;
    }
    return false;
}

int main(){
    vector<int> nums = {1,2,3,1,2};
    bool res = containsDuplicate(nums);
    if(res)
        cout<<"There is a duplicate element in the array" << endl;
    else
        cout<<"There are no duplicate elements " << endl;
}