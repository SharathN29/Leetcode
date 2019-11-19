#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue> 

using namespace std; 

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> frequency;
    vector<int> res;
    priority_queue<pair<int, int>> pq;

    for(int num : nums) 
        frequency[num]++;
    
    for(auto it = frequency.begin(); it != frequency.end(); it++) {
        pq.push(make_pair(it->second, it->first));
        if(pq.size() > frequency.size() - k) {
            res.push_back(pq.top().second);
            pq.pop();
        }
    }
    return res;
}

int main() {
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    vector<int> res = topKFrequent(nums, k);
    cout << "The top " << k << " elements in the list are ";
    for(int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;
}