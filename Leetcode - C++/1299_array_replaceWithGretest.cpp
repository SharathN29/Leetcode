// https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/

#include <iostream>
#include <vector>

using namespace std;

vector<int> replaceElements(vector<int>& arr) {
    int len = arr.size();
    int highest = arr[len-1];
    arr[len-1] = -1;
    for(int i = len-2; i >= 0; i--) {
    	int temp = arr[i];
    	arr[i] = highest;
    	if(temp > highest)
    		highest = temp;
    }
    return arr;
}

int main() {
	vector<int> arr = {17,18,5,4,6,1};
	vector<int> res = replaceElements(arr);
	for(int i : res)
		cout << i << " ";
	cout << endl;
}