// https://leetcode.com/problems/plus-one/

#include <iostream>
#include <vector>

using namespace std; 

vector<int> plusOne(vector<int>& digits){
	int carry = 0;
	for(int i = digits.size()-1; i>= 0; i--){
		if(digits[i] == 9)
			digits[i] = 0;
		else {
			digits[i]++;
			return digits; 
		}
	}
	digits[0] = 1;
	digits.push_back(0);
	return digits;
}

int main() {
	vector<int> digits = {1,9,9};
	vector<int> res = plusOne(digits);
	for(int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	cout << endl;
}