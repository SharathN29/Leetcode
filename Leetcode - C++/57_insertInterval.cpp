// https://leetcode.com/problems/insert-interval/

#include <iostream>
#include <vector>

using namespace std; 

//one of the slowest c++ submission 
// vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
//     intervals.push_back(newInterval);
//     sort(intervals.begin(), intervals.end());
//     for(int i = 1;i < intervals.size(); i++) {
//         if(intervals[i][0] <= intervals[i-1][1]) {
//             intervals[i-1][1] = max(intervals[i-1][1], intervals[i][1]);
//             intervals.erase(intervals.begin()+i);
//             i--;
//         } else continue;
//     }  
//     return intervals;
// }

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
	vector<vector<int>> res; 
	int index = 0;
	while(index < intervals.size() && intervals[index][1] < newInterval[0]) {
		res.push_back(intervals[index++]);
	}

	while(index < intervals.size() && intervals[index][0] <= newInterval[1]) {
		newInterval[0] = min(newInterval[0], intervals[index][0]);
		newInterval[1] = max(newInterval[1], intervals[index][1]);
		index++;
	}
	res.push_back(newInterval);
	while(index < intervals.size()) {
		res.push_back(intervals[index++]);
	}

	return res;
}

int main() {
	vector<vector<int>> intervals = {{1,2},{3,5},{6,7},{8,10},{12,16}};
	vector<int> newInterval = {4,8};
	vector<vector<int>> res = insert(intervals, newInterval);
	for(int i = 0; i < res.size(); i++)
		for(int j = 0; j < res[i].size(); j++) 
			cout << res[i][j] << " ";
		cout << endl;
	cout << endl;
}