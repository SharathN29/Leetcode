// https://leetcode.com/problems/top-k-frequent-elements/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,int> map;
    for(int n : nums)
    	map[n]++;

    vector<int> res;
    priority_queue<pair<int,int>> pq; 

    for(auto it = map.begin(); it != map.end(); it++){
    	pq.push(make_pair(it->second, it->first));
    	if(pq.size() > map.size()-k){
    		res.push_back(pq.top().second);
    		pq.pop();
    	}
    }
    return res;
}

int main() {
	vector<int> nums = {1,1,1,2,2,3};
	int k = 2;

}