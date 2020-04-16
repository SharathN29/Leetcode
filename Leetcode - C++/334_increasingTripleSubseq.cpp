// https://leetcode.com/problems/increasing-triplet-subsequence/

#include <iostream>
#include <vector>

using namespace std;

bool increasingTriplet(vector<int>& nums) {
    int c1 = INT_MAX, c2 =INT_MAX;
    for(int i : nums) {
        if(i <= c1) 
            c1 = i;
        else if(i <= c2)
            c2 = i;
        else return true;
    }
    return false;
}

int main() {
    vector<int> nums = {1,2,3,4,5};
    if(increasingTriplet(nums))
        cout << "Increasing triplet" << endl;
    else cout << "Not a increasing subsequence" << endl;
}