// https://leetcode.com/problems/meeting-rooms-ii/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int minMeetingRooms(vector<vector<int>>& intervals) {
    map<int, int> m;
    for(int i = 0; i < intervals.size(); i++) {
        m[intervals[i][0]]++;
        m[intervals[i][1]]--;
    }

    int count = 0, maxCount = 0;
    for(auto it = m.begin(); it != m.end(); it++) {
        count += it->second;
        maxCount = max(maxCount, count);
    }
    return maxCount;
}

int main() {
	vector<vector<int>> intervals = {{0,30},{5,10},{15,20}};
	int minRooms = minMeetingRooms(intervals);
	cout << "Min meeting rooms required : " << minRooms << endl;
}