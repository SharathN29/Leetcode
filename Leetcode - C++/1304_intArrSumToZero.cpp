//https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/

#include <iostream>
#include <vector>

using namespace std;

vector<int> sumZero(int n) {
    vector<int> res;
    if(n % 2 == 1) {
    	res.push_back(0);
    	n--;
    }
    int half = - (n/2);
    while(half <= n/2) {
    	if(half != 0)
    		res.push_back(half);
    	half++;
    }
    return res;
}

int main() {
	int n = 5;
	vector<int> res = sumZero(n);
	for(int n : res)
		cout << n << " ";
	cout << endl;
}