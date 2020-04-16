// https://leetcode.com/problems/minimum-cost-to-connect-sticks/

#include <iostream> 
#include <vector>
#include <queue>

using namespace std;

int connectSticks(vector<int>& sticks) {
    priority_queue<int, vector<int>, greater<int>> pq(sticks.begin(), sticks.end());
	int result = 0;
	while(pq.size() > 1) {
		int stick1 = pq.top(); pq.pop();
		int stick2 = pq.top(); pq.pop();
		result += stick1 + stick2;
		pq.push(stick1 + stick2);
	}
	return result;
}

int main() {
	vector<int> sticks = {1,8,3,5};
	int cost = connectSticks(sticks);
	cout << "Minimum cost : " << cost << endl;
}