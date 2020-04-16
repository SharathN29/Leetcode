#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

string mostCommonWord(string paragraph, vector<string>& banned) {
    unordered_set<string> ban(banned.begin(), banned.end());
    unordered_map<string, int> count; 

    for(auto &c : paragraph) {
    	c = isalpha(c) ? tolower(c) : ' ';
    }
	istringstream iss(paragraph);
	string w; 
	pair<string, int> res("",0);
	while(iss >> w){
		if(ban.find(w) == find.end() && ++count[w] > res.second) {
			res = make_pair(w, count[w]);
		}
	}  
    return res.first; 
}

int main() {
	string paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.";
	vector<string> banned = {"hit"};

	cout << "Most Common Word : " << mostCommonWord(paragraph, banned) << endl;
}