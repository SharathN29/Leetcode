// https://leetcode.com/problems/palindrome-number/
// Time : O(log n), Space : O(1)
#include <iostream>

using namespace std;

bool isPalindrom(int x) {
	if(x < 0 || (x % 10 == 0)) 
		return false;

	int sum = 0; 
	while(x > sum) {
		sum = sum * 10 + x % 10;
		x /= 10;
	}
	return (x == sum) || (x == sum/10);
}

int main() {
	int x = 121; 
	if(isPalindrom(x))
		cout << "Palindrome" << endl;
	else cout << "Not Palindrome" << endl;
}