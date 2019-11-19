#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int> pq(nums.begin(), nums.end());
    for(int i = 0; i < k - 1; i++)
        pq.pop();
    return pq.top();
}

int main() {
    vector<int> nums = {3,2,3,1,2,4,5,5,6};
    int k = 4;
    cout << "The " << k << "th largest element is " << findKthLargest(nums, k) << endl;
}