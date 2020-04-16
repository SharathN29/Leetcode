// https://leetcode.com/problems/can-place-flowers/

#include <iostream>
#include <vector>

using namespace std; 

bool canPlaceFlowers(vector<int>& flowerbed, int n) {
	int i = 0, count = 0;
	while(i < flowerbed.size()){
		if(flowerbed[i] == 0 && (i == 0 || flowerbed[i-1] == 0) && (i == flowerbed.size()-1 || flowerbed[i+1] == 0)){
			flowerbed[i] = 1;
			count++;
		}
		i++;
	}
	return count >= n;
}

int main() {
	vector<int> flowerbed = {1,0,0,0,1};
	int n = 1;
	if(canPlaceFlowers(flowerbed, n))
		cout << "Can Place Flowers" << endl;
	else cout << "Cannot place flowers" << endl;
}