#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> res;
    if(nums.empty()) return res;

    std::sort(nums.begin(), nums.end());
    for(int i = 0; i < nums.size(); i++) {
        int target3 = target - nums[i];
        for(int j = i+1; j < nums.size(); j++) {
            int target2 = target3 - nums[j];
            int front = j+1;
            int back = nums.size()-1;

            while(front < back) {
                int twoSum = nums[front] + nums[back];
                if(twoSum < target2) front++;
                else if(twoSum > target2) back--;
                else{
                    vector<int> quad(4,0);
                    quad[0] = nums[i];
                    quad[1] = nums[j];
                    quad[2] = nums[front];
                    quad[3] = nums[back];
                    res.push_back(quad);

                    while(front < back && nums[front] == quad[2]) ++front;
                    while(front < back && nums[back] == quad[3]) --back;
                }
            }
            while(j+1 < nums.size() && nums[j+1] == nums[j]) ++j;
        }
        while(i+1 < nums.size() && nums[i+1] == nums[i]) ++i;
    }
    return res;
}

int main() {
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    vector<vector<int>> res = fourSum(nums, target);

    for(int i = 0; i < res.size(); i++){
        cout<<"[";
        for(int j = 0; j < res[i].size(); j++){
            cout<<res[i][j] << " ";
        }
        cout<< "]";
    }
    cout <<"\n";
}