// https://leetcode.com/problems/3sum/

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res; 
    sort(nums.begin(), nums.end());

    for(int i = 0; i < nums.size(); i++){
        int target = -nums[i];
        int front = i+1;
        int back = nums.size()-1;

        while(front < back){
            int sum = nums[front] + nums[back];
            if(sum < target)
                front++;
            else if(sum > target)
                back--;
            else{
                vector<int> three(3,0);
                three[0] = nums[i];
                three[1] = nums[front];
                three[2] = nums[back];
                res.push_back(three);

                while(front < back && nums[front] == three[1]) front++;
                while(front < back && nums[back] == three[2]) back--;
            }
        }
        while(i+1 < nums.size() && nums[i+1] == nums[i]) i++;
    }
    return res;
}

int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};

}