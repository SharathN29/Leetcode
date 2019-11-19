#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int>& num){
    for(int i = 0; i < num.size(); i++)
        cout<< num[i] << "-"; 
}

void rotate(vector<int>& nums, int k){
    std::vector<int>::iterator it;
    for(int i = 0; i < k; i++){
        it = nums.begin(); 
        nums.insert(it, nums[nums.size()-1]);
        nums.pop_back();
    }
    cout<<"Elements in the array after the rotation ";
    printVector(nums);
}

int main(){
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    cout<<"Elements in the array before rotating " << endl;
    printVector(nums);
    int k = 3;
    rotate(nums, k);
}