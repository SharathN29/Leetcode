// https://leetcode.com/problems/search-suggestions-system/

#include <iostream>
#include <vector>

using namespace std;

vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
    
}

int main() {
	vector<string> products = {"mobile","mouse","moneypot","monitor","mousepad"};
	string searchWord = "mouse";
	vector<vector<string>> res = suggestedProducts(products, searchWord);
	for(int i = 0; i < res.size(); i++) {
		for(int j = 0; j < res[i].size(); j++) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}