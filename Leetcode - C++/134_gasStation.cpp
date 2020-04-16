// https://leetcode.com/problems/gas-station/

#include <iostream> 
#include <vector> 

using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
	int n = gas.size();
	int startPoint = 0, total = 0, curr = 0;

	for(int i = 0; i < n; i++) {
		total += gas[i] - cost[i];
		curr += gas[i] - cost[i];
		if(curr < 0) {
			curr = 0;
			startPoint = i+1;
		}
	}
	return total >= 0 ? startPoint : -1;
}

int main() {
	vector<int> gas = {1,2,3,4,5};
	vector<int> cost = {3,4,5,1,2};

	int start = canCompleteCircuit(gas, cost);
	cout << "Starting Point  : " << start << endl; 
}