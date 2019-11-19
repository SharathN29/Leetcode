#include <iostream>
#include <unordered_set>
#include <math.h>

using namespace std; 

bool isHappy(int n) {
	unordered_set<int> happy;
	while(n != 1) {
		if(happy.find(n) == happy.end())
			happy.insert(n);
		else return false; 
		
		int sum = 0;
		while(n != 0){
			sum += pow(n%10, 2);
			n /= 10;
		}
		n = sum;
	}	
	return true;
}

int main() {
	int n = 19;
	if(isHappy(n)) cout << "Happy Number" << endl;
	else cout << "Not a happy number" << endl;
}
