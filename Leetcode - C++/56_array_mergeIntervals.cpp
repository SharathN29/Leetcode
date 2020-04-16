// https://leetcode.com/problems/merge-intervals/

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), [](vector<int>a vector<int> b){return a[0] < b[0];});
    vector<vector<int>> result; 

    for(vector<int> interval : intervals) {
    	if(result.size() == 0 || result[result.size()-1][1] < interval[0])
    		result.push_back(intervals);
    	else 
    		result[result.size()-1][1] = max(result[result.size()-1][1], intervals[1]);
    }
    return result;
}

int main() {
	vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
	vectot<vector<int>> res = merge(intervals);
	for(int i = 0; i < res.size(); i++) {
		for(int j = 0; j < res[i].size(); j++) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}