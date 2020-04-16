// https://leetcode.com/problems/queue-reconstruction-by-height/
// Time - O(N^2), O(NlogN) for the sorting. N insert oprations, each take O(k) time. 
// Space - O(N). For the output array

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [] (vector<int> p1, vector<int>p2) {
        	return p1[0] > p2[0] ||(p1[0] == p2[0] && p1[1] < p2[1]);
        });
		vector<vector<int>> res;
		for(auto person : people) {
			res.insert(res.begin()+person[1], person);
		}
		return res;
    }
};

int main() {
	Solution *sol = new Solution();
	vector<vector<int>> people = {{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
	vector<vector<int>> res = sol->reconstructQueue(people);
	for(int i = 0; i < res.size(); i++) {
		for(int j = 0; j < res[i].size(); j++) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}