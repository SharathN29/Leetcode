// https://leetcode.com/problems/analyze-user-website-visit-pattern/

#include <iostream> 
#include <vector>

using namespace std;

vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
    unordered_map<string, vector<string>> map;
	for(int i = 0; i < username.size(); i++) {
		map[username[i]].push_back(website[i]);
	}
	
	unordered_map<string, unordered_set<string>> mapSet;
	for(int i = 0; i < username.size(); i++) {
		mapSet[website[i]].insert(username[i]);
	}
	
	
}

int main() {
	vector<string> username = {"joe","joe","joe","james","james","james","james","mary","mary","mary"};
	vector<int> timestamp = {1,2,3,4,5,6,7,8,9,10};
	vector<string> website = {"home","about","career","home","cart","maps","home","home","about","career"};
}