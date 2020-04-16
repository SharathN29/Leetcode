// https://leetcode.com/problems/meeting-rooms/

#include <iostream>
#include <vector>

using namespace std;

bool canAttendMeetings(vector<vector<int>>& intervals) {
    if(intervals.size() == 0) return true;
    sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b) {return a[0] < b[0];});
    for(int i = 0; i < intervals.size()-1; i++) {
    	if(intervals[i][1] > intervals[i+1][0])
    		return false;
    }
    return true;
}

int main() {
	vector<vector<int>> intervals = {{0,30},{5,10},{15,20}};
	if(canAttendMeetings(intervals))
		cout << "Can attend meetings " << endl;
	else cout << "Cannot attend meetings" << endl;
}