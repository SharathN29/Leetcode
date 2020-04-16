// https://leetcode.com/problems/prison-cells-after-n-days/

#include <iostream>
#include <vector>

using namespace std;

int countNeighbor(vector<int>& cells, int n) {
	int count = 0;
	if(n > 0 && cells[n-1] >= 1)
		count++;
	if(n < cells.size()-1 && cells[n+1] >= 1)
		count++;
	return count;
}

int getActions(vector<int>& cells, int n) {
	int currentState = cells[n];
	if(n == 0 || n == cells.size()-1) {
		if(cells[n] == 1)
			return 2;
		return 0;
	}
	
	int neighborCount = countNeighbor(cells, n);
	if(neighborCount == 0 || neighborCount == 2) {
		if(currentState == 1)
			return 1;
		return -1; 
	}
	if(currentState == 0) 
		return 0;
	return 2;
}

void prisonAfter1Day(vector<int>& cells) {
	int len = cells.size();
	for(int i = 0; i < len; i++) {
		cells[i] = getActions(cells, i);
	}
	
	for(int i = 0; i < len; i++) {
		if(cells[i] == 2) 
			cells[i] = 0;
		else if(cells[i] == -1)
			cells[i] = 1;
	}
}

vector<int> prisonAfterNDays(vector<int>& cells, int N) {
	for(int i = 0; i <= (N-1)%14; i++) {
		prisonAfter1Day(cells);
	}
	return cells;
}

int main () {
    vector<int> cells = {0,1,0,1,1,0,0,1};
	int N = 7;
	vector<int> res = prisonAfterNDays(cells, N);
	for(int n : res) 
		cout << n << " ";
	cout << endl;
}