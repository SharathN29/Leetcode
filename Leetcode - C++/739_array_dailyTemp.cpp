// https://leetcode.com/problems/daily-temperatures/
// Time- O(n), Space - O(n)

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> temp(T.size());
		for(int i = T.size()-1; i >= 0; --i) {
			int j = i+1; 
			while(j < T.size() && T[j] <= T[i]) {
				if(res[j] > 0) 
					j = j+ res[j];
				else j = T.size();
			}
			if(j < T.size())
				res[i] = j - i;
		} 
		return res;
    }
};

int main() {
	Solution *sol = new Solution();
	vector<int> T = {73, 74, 75, 71, 69, 72, 76, 73};
	vector<int> res = sol->dailyTemperatures(T);
	for(int n : res)
		cout << n << " ";
	cout << endl;
}