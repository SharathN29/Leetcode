#include <iostream>
#include <vector> 

using namespace std;

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    int count = 0;
    sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){return a[0] < b[0];});
    int res = 0, pre = 0;
    for(int i = 1; i < intervals.size(); i++) {
        if(intervals[i][1] < intervals[pre][0])
            res++; 
            if(intervals[i][1] < intervals[pre][1]) pre = i;
        pre = i; 
    }
    return res;
}

int main() {
    vector<vector<int>> intervals = {{1,2}, {2,3}, {3,4}, {1,3}};
    cout << "Minimum number of intervals to be removed " << eraseOverlapIntervals(intervals) << endl;
}