// https://leetcode.com/problems/prime-palindrome/

#include <iostream>
#include <vector>

using namespace std;

int evenPalindrome(int num) {
	string str1 = to_string(num);
	string str2 = str1;
	reverse(str2.begin(), str2.end());
	return stoi(str1+str2);
}

int oddPalindrome(int num) {
	string str1 = to_string(num);
	string str2 = str1.substr(0, str1.length()-1);
	reverse(str2.begin(), str2.end());
	return stoi(str1+str2);
}

bool isPrime(int num) {
	if(num == 1) return false; 
	for(int i = 2; i * i <= num; i++) {
		if(num % i == 0)
			return false;
	}
	return true; 
}

int primePalindrome(int N) {
    int even = 1;
	int odd = 1;
	int curr = 0;
	
	do {
		int evenp = evenPalindrome(even);
		int oddp = oddPalindrome(odd);
		curr = min(evenp, oddp);
		if(evenp < oddp) 
			++even;
		else ++odd; 
	} while(!(curr >= N && isPrime(curr)));
	return curr; 
}

int main() {
	int N = 7;
	cout << "Smallest Prime Palindrome : " << primePalindrome(N) << endl;
}