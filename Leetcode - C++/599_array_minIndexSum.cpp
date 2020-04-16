// https://leetcode.com/problems/minimum-index-sum-of-two-lists/

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
    unordered_map<string, int> map;
    for(int i = 0; i < list1.size(); i++)
        map[list1[i]] = i;

    int minIndexSum = INT_MAX;
    vector<string> res;
    for(int j = 0; j < list2.size(); j++) {
        if(map.count(list2[j]) != 0) {
            int index = map[list2[j]];
            if(index + j < minIndexSum){
                minIndexSum = index + j;
                res.clear();
                res.push_back(list2[j]);
            } 
            else if(index + j == minIndexSum){
                res.push_back(list2[j]);
            }
        } else continue; 
    }
    return res;
}

int main() {
	vector<string> list1 = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
	vector<string> list2 = {"KFC", "Shogun", "Burger King"};
	vector<string> res = findRestaurant(list1, list2);
	for(int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	cout << endl;

}