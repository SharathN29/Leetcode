#include <iostream>
#include <vector> 

using namespace std; 

void printVector(vector<vector<int>>& intervals) {
    cout << "{";
    for(int i = 0; i < intervals.size(); i++) {
        cout << "{";
        for(int j = 0; j < intervals[i].size(); j++) {
            cout << intervals[i][j] << " ";
        }
        cout << "}";
    }
    cout << "}" << endl;
}

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {return a[0] < b[0];});
    vector<vector<int>> res; 
    for(auto interval : intervals) {
        if(!res.empty() && res.back()[1] >= interval[0])
            res.back()[1] = max(res.back()[1], interval[1]);
        else res.push_back(interval);
    }
    return res;
}

int main() {
    vector<vector<int>> intervals = {{1,3}, {2,6}, {8,10}, {15,22}};
    cout << "Original input " << endl;
    printVector(intervals);
    vector<vector<int>> res = merge(intervals);
    printVector(res);

}